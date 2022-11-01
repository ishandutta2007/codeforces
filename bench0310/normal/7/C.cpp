#include <iostream>

using namespace std;

long long a,b,c,d,x,y;

void gcd(long long a,long long b,long long &x,long long &y)
{
    if(b==0)
    {
        d=a;
        x=1;
        y=0;
        return;
    }
    gcd(b,a%b,y,x);
    y-=a/b*x;
}

int main()
{
    cin >> a >> b >> c;
    c=-c;
    gcd(a,b,x,y);
    if(c%d) cout << -1 << endl;
    else cout << x*c/d << " " << y*c/d << endl;
    return 0;
}