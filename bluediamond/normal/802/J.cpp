#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;
int n;
int dp[N];
vector<pair<int, int>> g[N];

void dfs(int a, int p)
{
    dp[a] = 0;
    for (auto &it : g[a])
    {
        int b = it.first;
        int c = it.second;
        if (b != p)
        {
            dfs(b, a);
            dp[a] = max(dp[a], dp[b] + c);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    dfs(0, -1);
    cout << dp[0] << "\n";
    return 0;
}