#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int sq[26];
int po(int x, int y)
{
    if(y==0) return 1;
    else
    {
        if(y%2) return (1ll*x*po(x, y-1))%mod;
        else
        {
            int x2=po(x, y/2);
            return (1ll*x2*x2)%mod;
        }
    }
}
int f(string &s)
{
    int n=s.size(), q[26], su=1, an=0;
    for(int a=1; a<=n; a++) su=(1ll*su*a)%mod;
    for(int a=0; a<26; a++)
    {
        q[a]=sq[a];
        int fact=1;
        for(int b=1; b<=q[a]; b++) fact=(1ll*fact*b)%mod;
        su=(1ll*su*po(fact, mod-2))%mod;
    }
    for(int a=0; a<n; a++)
    {
        int sy=s[a]-'a', re=po(n-a, mod-2);
        for(int b=0; b<sy; b++)
        {
            if(q[b]>0)
            {
                int nsu=(1ll*su*re)%mod;
                nsu=(1ll*nsu*q[b])%mod;
                an+=nsu;
                if(an>=mod) an-=mod;
            }
        }
        if(q[sy]==0) break;
        su=(1ll*su*re)%mod;
        su=(1ll*su*q[sy])%mod;
        q[sy]--;
    }
    return an;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string s, t;
    cin>>s>>t;
    for(int a=0; a<s.size(); a++) sq[s[a]-'a']++;
    int an=f(t)-f(s);
    if(an<0) an+=mod;
    an--;
    if(an<0) an+=mod;
    cout<<an;
}