#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, mod=998244353;
int fact[sz], rev[sz];
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=1ll*re*x%mod;
        y>>=1;
        x=1ll*x*x%mod;
    }
    return re;
}
int c(int n, int k)
{
    return 1ll*fact[n]*rev[n-k]%mod*rev[k]%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size();
    fact[0]=1, rev[0]=1;
    for(int a=1; a<=n; a++)
    {
        fact[a]=1ll*fact[a-1]*a%mod;
        rev[a]=po(fact[a], mod-2);
    }
    int l=0, oq=0, r=0, cq=0;
    for(int a=0; a<n; a++)
    {
        if(s[a]==')') cq++;
        if(s[a]=='?') r++;
    }
    vector <int> pref[2];
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<=r-i; a++)
        {
            pref[i].push_back(c(r-i, a));
            if(a) pref[i][a]=(pref[i][a]+pref[i][a-1])%mod;
        }
    }
    int an=0;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='(')
        {
            if(r+cq-oq>0) an=(an+pref[0][min(l+r, r+cq-oq-1)])%mod;
            oq++;
        }
        else if(s[a]=='?')
        {
            r--;
            if(r+cq-oq>0) an=(an+pref[1][min(l+r, r+cq-oq-1)])%mod;
            l++;
        }
        else cq--;
    }
    cout<<an;
}