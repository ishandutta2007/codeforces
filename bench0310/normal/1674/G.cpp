#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    vector<int> in(n+1,0);
    vector<int> out(n+1,0);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        out[a]++; in[b]++;
    }
    vector<int> dp(n+1,-1);
    int res=1;
    function<void(int)> dfs=[&](int a)
    {
        dp[a]=0;
        if(in[a]>=2) dp[a]=1;
        for(int to:v[a])
        {
            if(dp[to]==-1) dfs(to);
            if(dp[to]>=1)
            {
                if(out[a]>=2) res=max(res,dp[to]+1);
                if(out[a]>=2&&in[a]>=2) dp[a]=max(dp[a],dp[to]+1);
            }
        }
    };
    for(int i=1;i<=n;i++) if(dp[i]==-1) dfs(i);
    cout << res << "\n";
    return 0;
}