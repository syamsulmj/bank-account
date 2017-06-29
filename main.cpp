#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <fstream>
#include <ctime>

using namespace std;

string id, password;
long double deposit;
const double annualRate = 0.20;

// ====================
// DECLARATION OF CLASS
// ====================
class generic
{
private:
    long double belen,belen2;
    long double sumOfBal;
    double monthlyIn;
    double rate;

public:
    long double constructor(double bal, double inter);
    long double intCal(double , double );
    void balance();
    long double withdraw(double);
    long double deposit(double );
    double servCharges();

};

class savingAccount
{
private:
    string act;
    long double con;
    bool the;

public:
    string active();
    bool check();
    void printCheck();

};

class choice
{
private:

    int in;
    int pick;
    char rawr;
    long double sum;

public:

    int showChoice();
    void loginChoice();
    void selectChoice();


};

class registerNewAndLogin
{
private:

    string reg1,reg2;
    string pass1,pass2;
    double des;

public:
    void disReg();
    void log();
    void save();
    void load();
    double opening();
    void save2();

};

class history
{
private:
    double depoSum, withSum;

public:
    void savingDepo(double a);
    void savingWith(double a);
    void dispTotalDepo();
    void dispTotalWith();
    void dispStatDepo();
    void dispStatWith();

};

    generic gen;
    savingAccount save; //declaration for class name variable
    choice ch;
    registerNewAndLogin reg;
    history his;

// ==============
// MAIN PROGRAM!!
// ==============


int main()
{
    //std::ios::sync_with_stdio(false);

    int i, j, k;
    int x,y,z;
    char last;

    getchar();
    cout<< "\t\t   ===================================\n";
    cout<< "\t\t\tWELCOME TO MAJESTIC BANK\n";
    cout<< "\t\t   THIS PROGRAM ACT AS AN BANK ACCOUNT\n";
    cout<< "\t\t   ===================================\n";
    START:
    cout<< "\n\nPLEASE LOG IN INTO YOUR ACCOUNT.";
    cout<< "\nIF YOU DON'T HAVE ANY ACCOUNT YET, YOU CAN REGISTER NOW!\n\n";


        x= ch.showChoice();

    switch (x)
    {
    case 1:
        cout<< "You have selected to register a new account.\n";
        reg.disReg();

        goto START;
        break;

    case 2:
        cout<< "You have selected to login into your account\n";
        reg.log();


        break;

    case 3:
        goto END;
        break;

    default:
        cout<< "Sorry wrong input. Please try again.\n\n";
        reg.load();
        goto START;
        break;
    }

    reg.load();
    cout<< "DO YOU WISH TO CONTINUE USING THIS PROGRAM?(Y/N)\n";
    cin>> last;

    if(last == 'Y' || last == 'y')
    {
        reg.load();
        goto START;
    }
    else
    {
        EXIT_FAILURE;
        reg.load();
    }
    END:

    cout<<"\n\n\t\tTHANK YOU FOR BANKING WITH MAJESTIC BANK!\n\t\t         PLEASE COME AGAIN! :D\n\n\n";

    return 0;
}

// ======================================
// FUNCTION DEFINITION FOR CHOICE CLASS!!
// ======================================

int choice :: showChoice()
{
    cout<<"1. REGISTER A NEW ACCOUNT\n";
    cout<<"2. LOG IN INTO YOUR ACCOUNT\n";
    cout<<"3. QUIT THIS PROGRAM\n\nYOUR CHOICE: ";
    cin >> std::ws;
    cin >> in;

    return in;
}

void choice :: loginChoice()
{
    cout << "===================================\n";
    cout << "WELCOME " << id << "!!!\n";
    cout << "===================================\n\n";
    cout << "PLEASE SELECT WHICH TRANSACTION YOU WOULD LIKE TO MAKE\n\n";
    cout << "1. WITHDRAW MONEY\n";
    cout << "2. DEPOSIT MONEY\n";
    cout << "3. CHECK BALANCE\n";
    cout << "4. CHECK STATISTICS\n";
    cout << "5. LOG OUT\n\n";
    cout << "YOUR CHOICE: ";

}
void choice :: selectChoice()
{
    double kaka;

    BEGIN:

    loginChoice();

    cin >> pick;
    reg.load();

    switch (pick)
    {
    case 1:


        cout << "YOU CHOOSE TO WITHDRAW YOUR MONEY\n\n";

        if (save.check() == true)
        {
            save.printCheck();
            reg.load();
            goto BEGIN;
        }

        cout << "PLEASE ENTER HOW MUCH MONEY YOU WANT TO WITHDRAW\n\n";
        cout << "RM ";
        cin >> kaka;
        sum = gen.withdraw(kaka);
        if(sum < 0)
        {
            cout << "\n\n\t\tINSUFFICIENT FUND!\n\n";
            reg.load();
            goto BEGIN;
        }
        his.savingWith(kaka);
        deposit = sum;
        reg.save();
        reg.load();
        goto BEGIN;
        break;

    case 2:
        cout << "YOU CHOOSE TO DEPOSIT YOUR MONEY\n\n";
        cout << "PLEASE ENTER HOW MUCH MONEY YOU WANT TO DEPOSIT\n\n";
        cout << "RM ";
        cin >> kaka;
        sum = gen.deposit(kaka);

        deposit = sum;
        reg.save();
        reg.load();
        goto BEGIN;
        break;

    case 3:
        cout << "YOU CHOOSE TO CHECK YOUR BALANCE\n\n";
        kaka = reg.opening();
        cout << fixed << setprecision(2);
        cout << "YOUR BALANCE IS: RM " << kaka << endl;

        reg.load();
        goto BEGIN;
        break;
    case 4:
        his.dispStatWith();
        his.dispStatDepo();
        his.dispTotalDepo();
        his.dispTotalWith();
        cout << "\n\n";
        reg.load();
        goto BEGIN;
        break;
    case 5:
        cout << "\n\n\t\tTHANK YOU FOR USING OUR SYSTEM\n\n";
        break;

    default:
        cout <<"\n\nSorry, Wrong input!";
        reg.load();
        goto BEGIN;
        break;
    }

    POPO:
    cout << "\n\nIS IT ALREADY END OF THE YEAR? (Y/N)\n";
    cin >> rawr;

    if(rawr == 'Y' || rawr == 'y')
    {
        ifstream l;
        double rate2,monthlyIn2;
        double pe;
        l.open((id + ".txt").c_str());
        l >> id >> password >> pe;
        l.close();
        cout << "\n\nTHE SYSTEM WILL CALCULATE FOR THE ANNUAL INTEREST RATE";
        deposit = gen.constructor(pe,annualRate);
        reg.save();

        rate2 = (annualRate/12);
        monthlyIn2 = pe * rate2;
        cout << fixed << setprecision(2);
        cout << "\n\nTHE TOTAL INTEREST RATE = RM" << monthlyIn2;
        cout << "\nTHE TOTAL SERVICE CHARGES = RM" << gen.servCharges();
        cout << "\nTHE TOTAL BALANCE AFTER ANNUAL INTEREST RATE AND SERVICE CHARGES IS:\n";
        cout << "RM " << deposit;
        cout << "\n\n";

    }
    else if(rawr == 'N' || rawr == 'n')
    {
        cout << "\n\nTHANK YOU! :D";
    }

    else
    {
        cout << "Sorry, Wrong Input!";
        goto POPO;
    }
}

// ========================================
// FUNCTION DEFINITION FOR GENERIC CLASS!!!
// ========================================
long double generic :: constructor(double bal, double inter)
{
    belen = intCal(bal , inter);

    return belen;
}

long double generic :: intCal(double b1, double in1)
{
    rate = (in1/12);
    monthlyIn = b1 * rate;
    sumOfBal = b1 + monthlyIn - servCharges();

    return sumOfBal;
}

long double generic :: deposit(double a)
{
    belen = reg.opening() + a;
    his.savingDepo(a);

    return belen;
}

long double generic :: withdraw(double b)
{
    belen2 = reg.opening() - b;

    return belen2;
}

double generic :: servCharges()
{
    ifstream ka;

    ka.open((id+ "withhistory.txt").c_str());
    double x[1000];
    string y[1000];
    int ass = 0;
    int manggis = 0;
    double total = 0;

    while(!ka.eof())
    {
        ka >> x[ass];
        ka >> y[ass];
        ass++;
        if(ass > 4)
        {
            ++manggis;
        }
    }
    --ass;
    --manggis;

    total = (ass*0.1) + manggis + (5*12);
    ka.close();

    return total;
}

// ============================================
// FUNCTION DEFINITION FOR REGISTRATION CLASS!!
// ============================================

void registerNewAndLogin :: disReg()
{
    bool penentu = false;

    do
    {
        cout<< "\n\nPLEASE INSERT YOUR ID: ";
        cin >> std::ws;
        getline(cin, reg1);

        ifstream kambing;
        kambing.open((reg1 + ".txt").c_str());
        if(!kambing)
        {
            penentu = true;
        }

        else if(kambing)
        {
            cout<< "\n\nSorry but the id name has been used by other user";
            cout<< "\nPlease try again\n\n\n";
            penentu = false;
            load();
        }

        kambing.close();
    }while(penentu != true);


    cout<< endl;
    cout<< "PLEASE INSERT YOUR PASSWORD: ";
    cin >> std::ws;
    getline(cin,pass1);

    cout<< endl;
    cout<< "PLEASE INSERT YOUR AMOUNT OF MONEY TO DEPOSIT FOR OPENING AN ACCOUNT\n";
    cout<< "(THE AMOUNT OF MONEY YOU DEPOSIT MUST BE MORE THAN \nRM 25.00 TO ACTIVATE YOUR ACCOUNT)\n";
    cout<< "\n\nRM ";

    while (des <= 25.00)
    {
        cin >> des;

            if (des >= 25.00)
            {
                save2();
                break;
            }
            else
            {
                cout<< "\n\nTHE AMOUNT OF MONEY YOU INSERTED IS NOT ENOUGH TO\nACTIVATE YOUR ACCOUNT\n";
                cout<< "PLEASE TRY AGAIN\n\n";
                cout<< "RM ";

            }

    }


    cout<< "\n\n\t\tWELL DONE! YOUR REGISTRATION IS SUCCESSFULL! :D\n\n";
    load();




}

void registerNewAndLogin :: log()
{
    char q;
   do
   {
       LOGIN:
       cout<< "\n\nID NAME: ";
        cin>> id;

        cout<< "PASSWORD: ";
        cin>> password;
        cout<< endl;

    ifstream logi;

    logi.open((id + ".txt").c_str());

    logi >> reg2 >> pass2;

    if( id == reg2 && password == pass2)
    {
        cout<< "YOU HAVE SUCCESSFULLY LOGIN INTO YOUR ACCOUNT\n";
        load();
        ch.selectChoice();
    }
    else
    {
        cout<< "THE ID OR PASSWORD YOU ENTERED IS INCORRECT\n";
        cout<< "DO YOU WANT TO TRY AGAIN? (Y/N)\n";
        cin >> q;
        if(q == 'Y' || q == 'y')
        {
            load();
            goto LOGIN;
        }
        else
        {

            goto OUT;

        }

    }
   }while (id != reg2 && password != pass2);


    OUT:;
    load();
}

void registerNewAndLogin :: save()
{
    ofstream login;

    login.open((id + ".txt").c_str());

    login << id << endl << password << endl << deposit;

    login.close();

}

void registerNewAndLogin :: load()
{
    cout << "\n\n";
    system("pause");
    system("cls");
}

double registerNewAndLogin :: opening()
{
    ifstream myFile;

    myFile.open((id+".txt").c_str());

    myFile >> id >> password >> des;


    myFile.close();

    return des;

}

void registerNewAndLogin :: save2()
{
    ofstream login;

    login.open((reg1 + ".txt").c_str());

    login << reg1 << endl << pass1 << endl << des;

    login.close();

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    ofstream wth;
    wth.open((reg1 + "depohistory.txt").c_str());

    wth << des << " " << setw(2) << setfill('0') << now->tm_mday << '.'
    << setw(2) << setfill('0') << (now->tm_mon + 1) << '.'
    << setw(4) << setfill('0') << (now->tm_year + 1900) << endl;

    wth.close();



}

// ===========================================
// FUNCTION DEFINITION FOR CLASS SAVINGACCOUNT
// ===========================================

string savingAccount :: active()
{
    con= reg.opening();

    if(con < 25.00)
    {
        act = "INACTIVE";
    }
    else if(con >= 25.00)
    {
        act = "ACTIVE";
    }

    return act;
}

bool savingAccount :: check()
{
    string p;

    p = active();

    if (p == "INACTIVE")
    {
        the = true;
    }
    else if(p == "ACTIVE")
    {
        the = false;
    }

    return the;

}

void savingAccount :: printCheck()
{
    cout << "WITHDRAW UNSUCCESSFUL\n";
    cout << "YOUR ACCOUNT IS INACTIVE\n";
    cout << "YOU NEED TO DEPOSIT MORE MONEY TO MAKE YOUR ACCOUNT BECOME ACTIVE AGAIN\n";
    cout << "(BALANCE MUST BE MORE THAN RM 25.00 TO BECOME ACTIVE)\n\n";


}

// ======================================
// FUNCTION DEFINITION FOR CLASS HISTORY
// ======================================


void history :: savingDepo(double a)
{
    ofstream file;
    ifstream myFile;

    double look[1000], eye;
    int tot = 0;
    string date[1000];
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );


    myFile.open((id + "depohistory.txt").c_str());

    if(!myFile)
    {
        ofstream wtf;
        wtf.open((id + "depohistory.txt").c_str());
        wtf.close();

        myFile.open((id + "depohistory.txt").c_str());

    }

    while(!myFile.eof())
    {
        myFile >> eye;
        getline(myFile,date[tot]);
        look[tot] = eye;
        tot++;

    }

    myFile.close();

    file.open((id + "depohistory.txt").c_str());

    for(int i = 0; i < tot-1 ; i++)
    {
        file << look[i] << date[i] << endl;
    }

    file << a << " " << setw(2) << setfill('0') << now->tm_mday << '.'
    << setw(2) << setfill('0') << (now->tm_mon + 1) << '.'
    << setw(4) << setfill('0') << (now->tm_year + 1900) << endl;

    file.close();

}

void history :: savingWith(double a)
{
    ofstream file;
    ifstream myFile;

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    string date[1000];
    double look[100], eye;
    int tot = 0;

    myFile.open((id + "withhistory.txt").c_str());

    if(!myFile)
    {
        ofstream wtf;
        wtf.open((id + "withhistory.txt").c_str());
        wtf.close();

        myFile.open((id + "withhistory.txt").c_str());

    }

    while(!myFile.eof())
    {
        myFile >> eye;
        getline(myFile,date[tot]);
        look[tot] = eye;
        tot++;

    }

    myFile.close();

    file.open((id + "withhistory.txt").c_str());

    for(int i = 0; i < tot-1 ; i++)
    {
        file << look[i] << date[i] << endl;
    }

    file << a<< " " << setw(2) << setfill('0') << now->tm_mday << '.'
    << setw(2) << setfill('0') << (now->tm_mon + 1) << '.'
    << setw(4) << setfill('0') << (now->tm_year + 1900) << endl;;;

    file.close();
}

void history :: dispTotalDepo()
{
    ifstream file;
    string an;
    double TotalDepo = 0;
    file.open ((id + "depohistory.txt").c_str());

    while (!file.eof())
    {
        file >> depoSum >> an;
        TotalDepo = TotalDepo + depoSum;
    }

    TotalDepo = TotalDepo - depoSum;

    cout << fixed << setprecision(2);
    cout << "\nTOTAL DEPOSIT OF THIS YEAR IS = RM " << TotalDepo;

    file.close();


}

void history :: dispTotalWith()
{
    ifstream file;
    string an;
    double TotalWith = 0;
    file.open ((id + "withhistory.txt").c_str());

    while (!file.eof())
    {
        file >> withSum >> an;
        TotalWith = TotalWith + withSum;
    }

    TotalWith = TotalWith - withSum;

    cout << fixed << setprecision(2);
    cout << "\nTOTAL OF WITHDRAWAL OF THIS YEAR IS = RM " << TotalWith;

    file.close();
}

void history :: dispStatDepo()
{
    ifstream ka;

    ka.open((id+ "depohistory.txt").c_str());
    double x[1000];
    string y[1000];
    int ass = 0;

    while(!ka.eof())
    {
        ka >> x[ass];
        ka >> y[ass];
        ass++;
    }

    ka.close();

    string month[1000];
    int tryDate[1000];
    int jan[1000],feb[1000],mar[1000],apr[1000],may[1000],jun[1000],jul[1000],aug[1000],sep[1000];
    int oct[1000],nov[1000],dis[1000];
    int susun[1000][12];

    cout << "\n\n========================================\n";
    cout << "STATISTIC FOR DEPOSIT FOR THE WHOLE YEAR\n";
    cout << "========================================\n\n\n";
    cout << "JAN   FEB   MAR   APR   MAY   JUN   JUL   AUG   SEP   OCT   NOV   DIS\n\n";
    for(int i = 0; i< ass-1; i++)
    {
        month[i] += y[i][3];
        month[i] += y[i][4];
        tryDate[i] = atoi((month[i]).c_str());
        switch (tryDate[i])
        {
            case 1:
                jan[i] = x[i];
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 2:
                jan[i] = 0;
                feb[i] = x[i];
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 3:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = x[i];
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 4:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = x[i];
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;


            case 5:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = x[i];
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;


            case 6:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = x[i];
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;


            case 7:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = x[i];
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 8:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = x[i];
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 9:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = x[i];
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 10:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = x[i];
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 11:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = x[i];
                dis[i] = 0;
                break;
            case 12:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = x[i];
                break;

        }
        cout << setw(3) << setfill('0');
        cout<< jan[i] << "   " << setw(3) << setfill('0') << feb[i] << "   " << setw(3) << setfill('0') << mar[i] << "   " << setw(3) << setfill('0') << apr[i] << "   " << setw(3) << setfill('0') << may[i] << "   ";
        cout << setw(3) << setfill('0') << jun[i] << "   " << setw(3) << setfill('0') << jul[i] << "   " << setw(3) << setfill('0') << aug[i] << "   " << setw(3) << setfill('0') << sep[i] << "   " << setw(3) << setfill('0') << oct[i] << "   " ;
        cout << setw(3) << setfill('0') << nov[i] << "   " << setw(3) << setfill('0') << dis[i] << endl << endl;

     }

     cout << "\n\nFIRST TIME DEPOSIT = RM"<< fixed << setprecision(2) << x[0] << "\n\n\n";
}

void history :: dispStatWith()
{
    ifstream ka;

    ka.open((id+ "withhistory.txt").c_str());
    double x[1000];
    string y[1000];
    int ass = 0;

    while(!ka.eof())
    {
        ka >> x[ass];
        ka >> y[ass];
        ass++;
    }

    ka.close();

    string month[1000];
    int tryDate[1000];
    int jan[1000],feb[1000],mar[1000],apr[1000],may[1000],jun[1000],jul[1000],aug[1000],sep[1000];
    int oct[1000],nov[1000],dis[1000];
    int susun[1000][12];

    cout << "=========================================\n";
    cout << "STATISTIC FOR WITHDRAW FOR THE WHOLE YEAR\n";
    cout << "=========================================\n\n";
    cout << "JAN   FEB   MAR   APR   MAY   JUN   JUL   AUG   SEP   OCT   NOV   DIS\n\n";
    for(int i = 0; i< ass-1; i++)
    {
        month[i] += y[i][3];
        month[i] += y[i][4];
        tryDate[i] = atoi((month[i]).c_str());
        switch (tryDate[i])
        {
            case 1:
                jan[i] = x[i];
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 2:
                jan[i] = 0;
                feb[i] = x[i];
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 3:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = x[i];
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 4:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = x[i];
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;


            case 5:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = x[i];
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;


            case 6:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = x[i];
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;


            case 7:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = x[i];
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 8:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = x[i];
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 9:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = x[i];
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 10:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = x[i];
                nov[i] = 0;
                dis[i] = 0;
                break;

            case 11:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = x[i];
                dis[i] = 0;
                break;
            case 12:
                jan[i] = 0;
                feb[i] = 0;
                mar[i] = 0;
                apr[i] = 0;
                may[i] = 0;
                jun[i] = 0;
                jul[i] = 0;
                aug[i] = 0;
                sep[i] = 0;
                oct[i] = 0;
                nov[i] = 0;
                dis[i] = x[i];
                break;

        }
        cout << setw(3) << setfill('0');
        cout<< jan[i] << "   " << setw(3) << setfill('0') << feb[i] << "   " << setw(3) << setfill('0') << mar[i] << "   " << setw(3) << setfill('0') << apr[i] << "   " << setw(3) << setfill('0') << may[i] << "   ";
        cout << setw(3) << setfill('0') << jun[i] << "   " << setw(3) << setfill('0') << jul[i] << "   " << setw(3) << setfill('0') << aug[i] << "   " << setw(3) << setfill('0') << sep[i] << "   " << setw(3) << setfill('0') << oct[i] << "   " ;
        cout << setw(3) << setfill('0') << nov[i] << "   " << setw(3) << setfill('0') << dis[i] << endl << endl;

     }
}
