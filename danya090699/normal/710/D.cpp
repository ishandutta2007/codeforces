#include <bits/stdc++.h>
#define int long long
using namespace std;
int ef(int x)
{
    int re=x;
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            while(x%a==0) x/=a;
            re-=re/a;
        }
    }
    if(x!=1) re-=re/x;
    return re;
}
int po(int x, int y, int mod)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int f(int a, int b, int mod)
{
    if(a==0)
    {
        if(b==0) return 0;
        else return -1;
    }
    else
    {
        int d=__gcd(a, mod);
        if(b%d==0)
        {
            a/=d, b/=d, mod/=d;
            return (1ll*b*po(a, ef(mod)-1, mod))%mod;
        }
        else return -1;
    }
}
int de(int x, int y){return x/y+(x%y>0);}
main()
{
    //freopen("input.txt", "r", stdin);
    int a1, b1, a2, b2, l, r;
    cin>>a1>>b1>>a2>>b2>>l>>r;
    if(b1>b2) swap(a1, a2), swap(b1, b2);

    if(a1==0)
    {
        if(b1==b2 and b1>=l and b1<=r) cout<<1;
        else cout<<0;
    }
    else if(a2==0)
    {
        if((b2-b1)%a1==0 and b2>=l and b2<=r) cout<<1;
        else cout<<0;
    }
    else
    {
        int x=f(a2%a1, (a1-(b2-b1)%a1)%a1, a1);
        if(x!=-1)
        {
            int p=b2+x*a2, per=a1*a2/__gcd(a1, a2);
            if(p<l) p+=per*de(l-p, per);

            if(p<=r) cout<<(r-p)/per+1;
            else cout<<0;
        }
        else cout<<0;
    }
}