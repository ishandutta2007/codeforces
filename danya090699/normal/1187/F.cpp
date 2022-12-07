#include <bits/stdc++.h>
#define div DIV
using namespace std;
const int mod=1e9+7, sz=2e5+10;
int n, l[sz], r[sz], pr[sz], su=1, an;
int po(int x, int y)
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
inline int sum(int a, int b)
{
    return (a+b<mod) ? a+b : a+b-mod;
}
inline int dif(int a, int b)
{
    return (a-b>=0) ? a-b : a-b+mod;
}
inline int mul(int a, int b)
{
    return (1ll*a*b)%mod;
}
inline int div(int a, int b)
{
    return (1ll*a*po(b, mod-2))%mod;
}
void f(int i)
{
    int re=0, lg=max(l[i], l[i-1]), rg=min(r[i], r[i-1]);
    int q1=r[i-1]-l[i-1]+1, q2=r[i]-l[i]+1, q3=r[i+1]-l[i+1]+1;

    if(lg<=rg) re=div(rg-lg+1, mul(q1, q2));

    lg=max(l[i], l[i+1]), rg=min(r[i], r[i+1]);

    if(lg<=rg) re=sum(re, div(rg-lg+1, mul(q2, q3)));

    lg=max(lg, l[i-1]), rg=min(rg, r[i-1]);

    if(lg<=rg) re=dif(re, div(rg-lg+1, mul(q1, mul(q2, q3))));

    an=sum(an, dif(1, re));
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++) scanf("%d", &l[a]);
    for(int a=0; a<n; a++) scanf("%d", &r[a]);
    int su=1;
    for(int a=0; a+1<n; a++)
    {
        int lg=max(l[a], l[a+1]), rg=min(r[a], r[a+1]), q1=r[a]-l[a]+1, q2=r[a+1]-l[a+1]+1;
        if(lg<=rg) pr[a]=dif(1, div(rg-lg+1, mul(q1, q2)));
        else pr[a]=1;
        su=sum(su, pr[a]);
    }
    an=su;
    for(int a=0; a+1<n; a++)
    {
        su=dif(su, pr[a]);
        if(a) su=dif(su, pr[a-1]), f(a);
        if(a+2<n) su=dif(su, pr[a+1]), f(a+1);

        an=sum(an, mul(su, pr[a]));
        an=sum(an, pr[a]);

        su=sum(su, pr[a]);
        if(a) su=sum(su, pr[a-1]);
        if(a+2<n) su=sum(su, pr[a+1]);
    }
    cout<<an;
}