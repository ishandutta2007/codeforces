#include <iostream>
using namespace std;
int main()
{
    int lu=0,ld,ll,lr=0,n,m,i,j,s=0;
    cin>>n>>m;
    ll=m;
    for(i=1;i<=n;i++)
    {
        cin.get();
        char ch;
        for(j=1;j<=m;j++)
        {
            ch=cin.get();
            if(ch=='B')
            {
            ld=i;
            if(lu==0)
                lu=i;
            if(j<ll)
                ll=j;
            if(j>lr)
                lr=j;
            s++;
            }
        }
    }
    if(s==0)
    {
        cout<<1;
        return 0;
    }
    if(ld-lu>lr-ll)
    {
        int d=ld-lu;
        d=d-(lr-ll);
        ll-=d;
        d=0;
        if(ll<1)
        {
            d=1-ll;
            ll=1;
        }
        lr+=d;
        if(lr>m)
        {
            cout<<-1;
            return 0;
        }
    }
    if(ld-lu<lr-ll)
    {
        int d=lr-ll;
        d=d-(ld-lu);
        lu-=d;
        d=0;
        if(lu<1)
        {
            d=1-lu;
            lu=1;
        }
        ld+=d;
        if(ld>n)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<(lr-ll+1)*(lr-ll+1)-s;
    return 0;
}