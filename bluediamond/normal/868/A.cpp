#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    char ch;
    int a,b,f1=0,f2=0,n,ok=0;
    ch=cin.get();
    a=ch;
    ch=cin.get();
    b=ch;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin.get();
        int c,d;
        ch=cin.get();
        c=ch;
        ch=cin.get();
        d=ch;
        if(c==a and d==b)
            ok=1;
        if(c==b and d==a)
            ok=1;
        if(d==a)
            f1=1;
        if(c==b)
            f2=1;
    }
    if(f1+f2==2 or ok==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}