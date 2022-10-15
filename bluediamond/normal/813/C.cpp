#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n;
vector<int> g[N];
int dep[N];
int dist_x[N];
int x;

void build(int a, int p)
{
    for (auto &b : g[a])
    {
        if (b != p)
        {
            dep[b] = 1 + dep[a];
            build(b, a);
        }
    }
}

bool u[N];
bool ok[N];

void dfs(int a)
{
    u[a] = 1;
    for (auto &b : g[a])
    {
        if (u[b] == 0 && ok[b])
        {
            dfs(b);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        dist_x[i] = -1;
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    build(1, -1);
    queue<int> q;
    q.push(x);
    dist_x[x] = 0;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (auto &b : g[a])
        {
            if (dist_x[b] == -1)
            {
                dist_x[b] = 1 + dist_x[a];
                q.push(b);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ok[i] = (dist_x[i] < dep[i]);
    }
    dfs(x);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (u[i])
        {
            mx = max(mx, 2 * dep[i]);
        }
    }
    cout << mx << "\n";
}