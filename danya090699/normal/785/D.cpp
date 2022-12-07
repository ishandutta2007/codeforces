#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7, sz=1e6;
int po(int x, int st)
{
    if(st==0) return 1;
    else if(st%2==1) return (po(x, st-1)*x)%mod;
    else
    {
        int an=po(x, st/2);
        return (an*an)%mod;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int fact[sz], oq=0, zq=0, ans=0;
    fact[0]=1;
    for(int a=1; a<sz; a++) fact[a]=(fact[a-1]*a)%mod;
    for(int a=0; a<s.size(); a++) if(s[a]==')') zq++;
    for(int a=0; a<s.size(); a++)
    {
        if(s[a]=='(')
        {
            oq++;
            if(zq>0)
            {
                int ch=fact[oq+zq-1], zn=(fact[zq-1]*fact[oq])%mod;
                ans=(ans+ch*po(zn, mod-2))%mod;
            }
        }
        else zq--;
    }
    cout<<ans;
}