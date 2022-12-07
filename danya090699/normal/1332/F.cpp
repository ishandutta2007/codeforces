#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353, sz=3e5+10;
vector <int> sv[sz];
int dp[sz][3];
void dfs(int v, int pr)
{
    int q0=1, q1=1, q2=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v);
            q0=q0*(dp[ne][0]+dp[ne][1]+dp[ne][2])%mod;
            q1=q1*(dp[ne][0]+dp[ne][2])%mod;
            q2=q2*dp[ne][2]%mod;
        }
    }
    dp[v][0]=q0;
    dp[v][1]=q1;
    dp[v][2]=(q0+q1)%mod;
    dp[v][2]-=q2;
    if(dp[v][2]<0) dp[v][2]+=mod;
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
    int an=dp[0][2]-1;
    if(an<0) an+=mod;
    cout<<an;
}