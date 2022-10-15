#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e5 + 7;
int n;
vector<int> g2[N];
vector<int> g[N];
vector<int> vals[N];
bool u[N];

void dfs(int a)
{
    u[a] = 1;
    for (auto &b : g2[a])
    {
        if (u[b] == 0)
        {
            g[a].push_back(b);
            dfs(b);
        }
    }

}

void dfs2(int a, int cur, int dist)
{
    if ((int) g[a].size() == 0)
    {
        vals[cur].push_back(dist);
    }
    else
    {
        for (auto &b : g[a])
        {
            dfs2(b, cur, dist + 1);
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
        int a, b;
        cin >> a >> b;
        g2[a].push_back(b);
        g2[b].push_back(a);
    }
    dfs(1);
    int ans = 0;
    for (auto &a : g[1])
    {
        dfs2(a, a, 0);
        sort(vals[a].begin(), vals[a].end());
        for (int i = 1; i < (int) vals[a].size(); i++)
        {
            if (vals[a][i] <= vals[a][i - 1])
            {
                vals[a][i] = vals[a][i - 1] + 1;
            }
        }
        ans = max(ans, vals[a].back() + 1);
    }
    cout << ans << "\n";
}