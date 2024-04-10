#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int get(string &suf, string &cu, vector <int> &re)
{
    string s=suf+"#"+cu;
    int n=s.size();
    int zf[n], l=0, r=-1;
    zf[0]=0;
    for(int a=1; a<n; a++)
    {
        zf[a]=0;
        if(r>=a) zf[a]=min(zf[a-l], r-a+1);
        while(a+zf[a]<n)
        {
            if(s[zf[a]]==s[a+zf[a]]) zf[a]++;
            else break;
        }
        if(a+zf[a]-1>r) l=a, r=a+zf[a]-1;
        if(a>suf.size()) re.push_back(zf[a]);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string x, l, r;
    cin>>x>>l>>r;
    vector <int> zfl, zfr;
    get(l, x, zfl), get(r, x, zfr);
    int n=x.size();
    int pref[n+1], dp[n+1];
    pref[0]=1, dp[0]=1;
    for(int a=1; a<=n; a++)
    {
        pref[a]=pref[a-1];
        dp[a]=0;
        if(a>=l.size())
        {
            int lg=0, rg=a-l.size();
            if(zfl[rg]<l.size())
            {
                if(x[rg+zfl[rg]]<l[zfl[rg]]) rg--;
            }
            if(a>=r.size())
            {
                lg=a-r.size();
                if(zfr[lg]<r.size())
                {
                    if(x[lg+zfr[lg]]>r[zfr[lg]]) lg++;
                }
            }
            if(lg<=rg)
            {
                dp[a]=pref[rg];
                if(lg) dp[a]-=pref[lg-1];
                if(dp[a]<0) dp[a]+=mod;
            }
            if(l=="0" and x[a-1]=='0') dp[a]=(dp[a]+dp[a-1])%mod;
        }
        if(a==n) cout<<dp[n];
        else if(x[a]!='0') pref[a]=(pref[a]+dp[a])%mod;
    }
}