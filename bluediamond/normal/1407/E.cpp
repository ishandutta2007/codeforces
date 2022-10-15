#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 500000 + 7;
const int INF = (int) 1e9 + 7;

int n;
int m;
int dist[N];
int tp[N];
vector<pair<int, int>> g[N];
vector<pair<int, int>> g_inv[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g_inv[y].push_back({x, z});
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = -1;
        tp[i] = -1;
    }
    queue<int> q;
    dist[n] = 0;
    q.push(n);
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (auto &it : g_inv[a])
        {
            int b = it.first, x = it.second;
            if (tp[b] == -1)
            {
                tp[b] = 1 ^ x;
            }
        }
        for (auto &it : g_inv[a])
        {
            int b = it.first, x = it.second;
            if (dist[b] == -1 && tp[b] == x)
            {
                dist[b] = dist[a] + 1;
                q.push(b);
            }
        }
    }
    cout << dist[1] << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (tp[i] == -1)
        {
            tp[i] = 0;
        }
        cout << tp[i];
    }
    cout << "\n";
    return 0;
}