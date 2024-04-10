#include <iostream>
#include <vector>
using namespace std;
const int MAX = 300005;
vector<pair<int, int> > w[MAX];
int dp[MAX], tmp[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, len;
        cin >> u >> v >> len;
        w[len].push_back(make_pair(u, v));
    }
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < w[i].size(); j++)
        {
            int u = w[i][j].first, v = w[i][j].second;
            tmp[v] = 0;
        }
        for (int j = 0; j < w[i].size(); j++)
        {
            int u = w[i][j].first, v = w[i][j].second;
            tmp[v] = max(tmp[v], dp[u] + 1);
        }
        for (int j = 0; j < w[i].size(); j++)
        {
            int u = w[i][j].first, v = w[i][j].second;
            dp[v] = max(dp[v], tmp[v]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}