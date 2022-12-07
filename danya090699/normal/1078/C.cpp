#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=3e5+10, mod=998244353;
vector <int> sv[sz];
int dp[sz][2], dp2[sz];
void dfs(int v, int pr)
{
    dp2[v]=1, dp[v][0]=1, dp[v][1]=0;
    int cu=1;
    vector <int> sp, sp2, pref;
    pref.push_back(1);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            dp2[v]=(1ll*dp2[v]*(dp[ne][1]+dp2[ne]))%mod;
            //if(v==0) cout<<dp[ne][1]<<" "<<dp2[ne]<<" "<<ne<<"\n";
            dp[v][0]=(dp[v][0]*(dp2[ne]+dp[ne][1]*2))%mod;

            sp.push_back((dp2[ne]+dp[ne][1]*2)%mod);
            sp2.push_back((dp2[ne]+dp[ne][0])%mod);
            pref.push_back((pref.back()*sp.back())%mod);
        }
    }
    int suf=1;
    if(sp.size())
    {
        for(int a=sp.size()-1; a>=0; a--)
        {
            dp[v][1]=(dp[v][1]+((sp2[a]*pref[a])%mod)*suf)%mod;
            suf=(suf*sp[a])%mod;
        }
    }
    dp[v][0]-=dp2[v];
    if(dp[v][0]<0) dp[v][0]+=mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0);
    cout<<(dp2[0]+dp[0][1])%mod;
    //cout<<dp2[1];
}