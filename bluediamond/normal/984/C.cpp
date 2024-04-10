#include <iostream>

using namespace std;

long long cmmdc(long long a,long long b)
{
    long long r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

long long x,y,b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        cin>>x>>y>>b;
        y/=cmmdc(x,y);
        x=cmmdc(y,b);
        while(x!=1 && y!=1)
        {
            y/=x;
            x=cmmdc(x,y);
        }
        if(y==1)
            cout<<"Finite\n";
        else cout<<"Infinite\n";
    }
    return 0;
}