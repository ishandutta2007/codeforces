#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<array<int,2>> dp(n+1,{0,1});
    vector<array<ll,2>> sum(n+1,{0,0});
    function<void(int,int)> dfs=[&](int a,int p)
    {
        sum[a][1]=v[a].size();
        for(int to:v[a])
        {
            if(to==p) continue;
            dfs(to,a);
            dp[a][0]+=max(dp[to][0],dp[to][1]);
            if(dp[to][0]==dp[to][1]) sum[a][0]+=min(sum[to][0],sum[to][1]);
            else sum[a][0]+=sum[to][(dp[to][0]<dp[to][1])];
            dp[a][1]+=dp[to][0];
            sum[a][1]+=sum[to][0];
        }
    };
    dfs(1,0);
    vector<int> c(n+1,0);
    function<void(int,int,int)> go=[&](int a,int p,int u)
    {
        if(u==0)
        {
            if(dp[a][1]>dp[a][0]) c[a]=1;
            else if(dp[a][0]==dp[a][1]&&sum[a][1]<sum[a][0]) c[a]=1;
        }
        for(int to:v[a]) if(to!=p) go(to,a,c[a]);
    };
    go(1,0,0);
    if(n==2) c={0,1,1};
    vector<int> w(n+1,1);
    int cnt=0;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=c[i];
        if(c[i]==1) w[i]=v[i].size();
        res+=w[i];
    }
    cout << cnt << " " << res << "\n";
    for(int i=1;i<=n;i++) cout << w[i] << " \n"[i==n];
    return 0;
}