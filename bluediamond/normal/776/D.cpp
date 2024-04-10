#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
int n, m;
int v[N];
vector<pair<int, int>> g[N];
vector<int> u[N];
int c[N];
bool bad;

void dfs(int a)
{
    for (auto &it : g[a])
    {
        int b = it.first;
        int lol = it.second;
        int wb;
        if (lol == 0)
        {
            wb = 1 - c[a];
        }
        else
        {
            wb = c[a];
        }
        if (c[b] == -1)
        {
            c[b] = wb;
            dfs(b);
        }
        else
        {
            if (c[b] != wb)
            {
                bad = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

  ///  freopen ("hacker.in", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= m; i++)
    {
        int l;
        cin >> l;
        for (int j = 1; j <= l; j++)
        {
            int x;
            cin >> x;
            u[x].push_back(i);
        }
    }

    for (int x = 1; x <= n; x++)
    {
        int a = u[x][0], b = u[x][1];
        g[a].push_back({b, v[x]});
        g[b].push_back({a, v[x]});
    }
    
    for (int i = 1; i <= m; i++)
    {
        c[i] = -1;
    }

    for (int i = 1; i <= m; i++)
    {
        if (c[i] == -1)
        {
            c[i] = 0;
            dfs(i);
        }
    }

    if (bad)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }
}