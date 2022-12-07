#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int mod=1e9+rand(), al=29;
    while(1)
    {
        int fo=0;
        for(int a=2; a*a<=mod; a++)
        {
            if(mod%a==0)
            {
                fo=1;
                break;
            }
        }
        if(fo) mod--;
        else break;
    }

    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    int n=t.size(), q0=0, q1=0, an=0;
    int pref[n+1], st[n];
    pref[0]=0, st[0]=1;
    for(int a=1; a<n; a++) st[a]=(1ll*al*st[a-1])%mod;
    for(int a=1; a<=n; a++) pref[a]=(pref[a-1]+1ll*(t[a-1]-'a'+1)*st[a-1])%mod;
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]=='0') q0++;
        else q1++;
    }
    for(int l0=1; l0<=n; l0++)
    {
        if(1ll*l0*q0<n)
        {
            if((n-l0*q0)%q1==0)
            {
                int l1=(n-l0*q0)/q1, yk=0;
                int hash0=-1, hash1=-1, ok=1;
                for(int a=0; a<s.size(); a++)
                {
                    int l=l0;
                    if(s[a]=='1') l=l1;
                    int chash=pref[yk+l]-pref[yk];
                    if(chash<0) chash+=mod;
                    chash=(1ll*chash*st[n-1-yk])%mod;

                    if(s[a]=='0')
                    {
                        if(hash0==-1) hash0=chash;
                        else if(hash0!=chash) ok=0;
                    }
                    else
                    {
                        if(hash1==-1) hash1=chash;
                        else if(hash1!=chash) ok=0;
                    }

                    if(ok==0) break;

                    yk+=l;
                }
                //cout<<hash0<<" "<<hash1<<"\n";
                if(hash0!=hash1) an+=ok;
            }
        }
    }
    cout<<an;
}