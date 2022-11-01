#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n+1);
    for(int i=2;i<=n;i++)
    {
        int p;
        cin >> p;
        v[p].push_back(i);
    }
    vector dp(n+1,array<int,2>{0,0});
    auto dfs=[&](auto &&self,int a)->void
    {
        dp[a][0]=1;
        for(int to:v[a])
        {
            self(self,to);
            dp[a][0]=max(dp[a][0],dp[to][0]+1);
            dp[a][1]+=max(dp[to][0],dp[to][1]);
        }
    };
    dfs(dfs,1);
    cout << max(dp[1][0],dp[1][1]) << "\n";
    return 0;
}