#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10, mod=998244353;
int c[sz][sz], pref[sz][sz];
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), q[n+1];
    for(int a=0; a<=n; a++)
    {
        q[a]=0;
        c[a][0]=1, c[a][a]=1;
        for(int b=1; b<a; b++) c[a][b]=(c[a-1][b-1]+c[a-1][b])%mod;
        pref[a][0]=1;
        for(int b=1; b<=a; b++) pref[a][b]=(pref[a][b-1]+c[a][b])%mod;
    }
    int oq=0, cq=0, l=0, r=0;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='?') r++;
        if(s[a]==')') cq++;
    }
    for(int a=0; a<n; a++)
    {
        if(s[a]!=')')
        {
            oq++;
            if(s[a]=='?') r--;

            for(int b=oq; b<=oq+l; b++)
            {
                if(b<=cq+r)
                {
                    q[b]=(q[b]+1ll*c[l][b-oq]*pref[r][min(r, r-(b-cq))])%mod;
                }
            }

            if(s[a]=='?') oq--, l++;
        }
        else cq--;
    }
    int an=0;
    for(int a=1; a<n; a++)
    {
        q[a]-=q[a+1];
        if(q[a]<0) q[a]+=mod;
        an=(an+1ll*q[a]*a)%mod;
    }
    cout<<an;
}