#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int ar[sz];
int ef(int x)
{
    int re=1;
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            int q=1;
            while(x%a==0)
            {
                x/=a, q*=a;
            }
            re*=q-q/a;
        }
    }
    if(x>1) re*=x-1;
    return re;
}
int po(int x, int y, int mod)
{
    int re=1%mod;
    x%=mod;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        x=(1ll*x*x)%mod;
        y>>=1;
    }
    return re;
}
vector <int> f;
int rec(int le, int l, int r)
{
    int mod=f[le];
    if(mod==1) return 1;
    int st=1;
    if(l<r) st=rec(le+1, l+1, r);
    long long real=1;
    if(ar[l]>1)
    {
        for(int a=0; a<st; a++)
        {
            real*=ar[l];
            if(real>=mod) break;
        }
    }
    if(real>=mod) real=mod;
    else real=0;
    return po(ar[l], st, mod)+real;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, mod, q;
    cin>>n>>mod;
    f.push_back(mod);
    while(f.back()>1) f.push_back(ef(f.back()));
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        printf("%d\n", rec(0, l, r)%f[0]);
    }
}