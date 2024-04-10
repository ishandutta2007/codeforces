#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=1e6+10, mod=1e9+7;
vector <int> sv[sz];
int va[sz], q[sz], q2[sz], dp[sz];
void dfs(int v)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne), va[v]+=va[ne];
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%lld", &va[a]);
    for(int a=1; a<n; a++)
    {
        int pr;
        scanf("%lld", &pr);
        sv[pr-1].push_back(a);
    }
    dfs(0);
    for(int a=0; a<n; a++)
    {
        int k=va[0]/__gcd(va[a], va[0]);
        if(k<=n) q[k]++;
    }
    for(int a=1; a<=n; a++)
    {
        for(int b=a; b<=n; b+=a) if(va[0]%b==0) q2[b]+=q[a];
    }
    for(int a=1; a<=n; a++)
    {
        if(q2[a]==a) dp[a]=1;
        else dp[a]=0;
    }
    int an=0;
    for(int a=n; a>=1; a--)
    {
        if(dp[a])
        {
            for(int b=a+a; b<=n; b+=a) dp[a]=(dp[a]+dp[b])%mod;
        }
    }
    cout<<dp[1];
}