#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+9;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        x=(1ll*x*x)%mod;
        y>>=1;
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b, k;
    cin>>n>>a>>b>>k;
    n++;
    n/=k;
    n--;
    int q=(1ll*po(b, k)*po(po(a, k), mod-2))%mod, an=0;
    for(int i=0; i<k; i++)
    {
        char sy;
        cin>>sy;
        int re;
        if(q!=1)
        {
            int fi=(1ll*po(a, k-1-i+n*k)*po(b, i))%mod, la=(1ll*po(a, k-1-i)*po(b, i+n*k))%mod;
            int ch=fi-(1ll*la*q)%mod, zn=1-q;
            if(ch<0) ch+=mod;
            if(zn<0) zn+=mod;
            re=(1ll*ch*po(zn, mod-2))%mod;
        }
        else re=(1ll * ((1ll*po(a, k-1-i+n*k)*po(b, i))%mod) * (n+1))%mod;
        if(sy=='-') re=mod-re;
        an=(an+re)%mod;
    }
    cout<<an;
}