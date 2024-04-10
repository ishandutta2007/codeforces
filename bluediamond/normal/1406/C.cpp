#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = (int) 1e5 + 7;
int n;
int s[N];
int par[N];
int x[N];
int y[N];
int mx[N];
vector<int> g[N];
vector<int> nodes;

void dfs(int a, int p)
{
    par[a] = p;
    s[a] = 1;
    for (auto &b : g[a])
    {
        if (b != p)
        {
            dfs(b, a);
            s[a] += s[b];
        }
    }
    mx[a] = n - s[a];
    for (auto &b : g[a])
    {
        if (b != p)
        {
            mx[a] = max(mx[a], s[b]);
        }
    }
}

bool ok()
{
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        g[x[i]].push_back(y[i]);
        g[y[i]].push_back(x[i]);
    }
    dfs(1, -1);
    int cmin = 0, mn = mx[1];
    for (int i = 1; i <= n; i++)
    {
        mn = min(mn, mx[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cmin += (mx[i] == mn);
    }
    return (cmin == 1);
}

void explore(int a, int p)
{
    nodes.push_back(a);
    for (auto &b : g[a])
    {
        if (b != p)
        {
            explore(b, a);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }
        if (ok())
        {
            cout << x[1] << " " << y[1] << "\n";
            cout << x[1] << " " << y[1] << "\n";
            continue;
        }
        while (1)
        {
            int i = rnd() % (n - 1) + 1;
            int a = x[i], b = y[i];
            if (rnd() & 1)
            {
                swap(a, b);
            }
            for (int j = 1; j <= n; j++)
            {
                g[j].clear();
            }
            for (int j = 1; j < n; j++)
            {
                if (j != i)
                {
                    g[x[j]].push_back(y[j]);
                    g[y[j]].push_back(x[j]);
                }
            }
            nodes.clear();
            explore(a, -1);
            int lol = rnd() % (int) nodes.size();
            lol = nodes[lol];
            x[i] = lol;
            y[i] = b;
            if (x[i] != y[i] && ok())
            {
                cout << a << " " << b << "\n";
                cout << x[i] << " " << y[i] << "\n";
                break;
            }
            x[i] = a;
            y[i] = b;
        }
    }
}