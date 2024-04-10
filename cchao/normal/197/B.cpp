#include <iostream>
#include <cstdlib>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}
int main()
{
    int da,db;
    cin >> da >> db;
    if(db > da)
    {
        cout << "0/1" << endl;
    }
    else
    {
        int a,b,tmp;
        cin >> a; for(int k = 0; k < da; k++) cin >> tmp;
        cin >> b; for(int k = 0; k < db; k++) cin >> tmp;
        if(da == db)
        {
            int f = 0;
            if(a*b < 0) f = 1;
            a = abs(a);
            b = abs(b);
            int g = gcd(a,b);
            a/= g;
            b/= g;
            if(f) cout << "-";
            cout << a << "/" << b << endl;
        }
        else
        {
            if(a * b < 0) cout << "-";
            cout << "Infinity" << endl;
        }
    }
    return 0;
}