#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    vector<int> all(n+1,0); //sum of dp[i]
    const ll mod=998244353;
    auto add=[&](int &a,int b){a=(a+b)%mod;};
    auto mul=[&](int &a,int b){a=((ll)a*b)%mod;};
    function<void(int,int)> dfs=[&](int a,int p)
    {
        vector<int> ch={0};
        for(int to:v[a])
        {
            if(to==p) continue;
            dfs(to,a);
            ch.push_back(to);
        }
        int sz=(int)ch.size()-1;
        ch.push_back(0);
        vector<vector<int>> pre(sz+1,vector<int>(k+1,0));
        for(int j=0;j<=k;j++) pre[0][j]=1;
        for(int i=1;i<=sz;i++)
        {
            int to=ch[i];
            add(pre[i][0],all[to]);
            for(int j=0;j<k;j++) add(pre[i][j+1],dp[to][j]);
            for(int j=0;j<k;j++) add(pre[i][j+1],pre[i][j]);
            for(int j=0;j<=k;j++) mul(pre[i][j],pre[i-1][j]);
        }
        for(int j=0;j<=k;j++) dp[0][j]=1;
        for(int i=sz;i>=1;i--)
        {
            int to=ch[i];
            for(int mx=1;mx<=k;mx++)
            {
                int now=dp[to][mx-1];
                mul(now,pre[i-1][min(k-mx,mx-1)]);
                mul(now,dp[ch[i+1]][min(k-mx,mx)]);
                add(dp[a][mx],now);
            }
            for(int j=k;j>=1;j--) dp[to][j]=dp[to][j-1];
            dp[to][0]=all[to];
            for(int j=1;j<=k;j++) add(dp[to][j],dp[to][j-1]);
            for(int j=0;j<=k;j++) mul(dp[to][j],dp[ch[i+1]][j]);
        }
        dp[a][0]=1;
        for(int i=1;i<=sz;i++) mul(dp[a][0],all[ch[i]]);
        for(int j=0;j<=k;j++) add(all[a],dp[a][j]);
    };
    dfs(1,0);
    int res=0;
    for(int i=0;i<=k;i++) add(res,dp[1][i]);
    cout << res << "\n";
    return 0;
}