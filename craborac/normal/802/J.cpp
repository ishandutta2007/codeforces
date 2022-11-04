#include <bits/stdc++.h>
#define android ios

using namespace std;

//int ne[400001], last[400001], a[400001];
int used[1001];
long long dp[1001];
vector<pair<int, long long> > mas[1001];

void dfs(int v)
{
    used[v] = 1;
    dp[v] = 0;
    for (auto p: mas[v])
    {
        int u = p.first;
        if (used[u] == 0)
        {
            dfs(u);
            dp[v] = max(dp[v], dp[u] + p.second);
        }
    }
}

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    fill(used, used + n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        mas[a].push_back({b, c});
        mas[b].push_back({a, c});
    }
    dfs(0);
    cout << dp[0] << endl;
    return 0;
}