#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, a[N];
vector<pair<int, ll>> g[N];
ll val[N];
ll kek[N];

void build(int v)
{
    for (auto &it : g[v])
    {
        int v2 = it.first;
        ll dist = it.second;

        kek[v2] = dist + kek[v];
        build(v2);
    }
}

priority_queue<ll> vals[N];
int leaf_mx[N], sol[N];

void solve(int v)
{
    if ((int) g[v].size() == 0)
    {
        leaf_mx[v] = v;
        vals[v].push(val[v]);
        return;
    }

    for (auto &it : g[v])
    {
        int v2 = it.first;

        solve(v2);
        int leaf = leaf_mx[v2];

        if ((int) vals[leaf].size() > (int) vals[leaf_mx[v]].size())
        {
            leaf_mx[v] = leaf;
        }
    }

    for (auto &it : g[v])
    {
        int v2 = it.first;
        int leaf = leaf_mx[v2];

        if (leaf != leaf_mx[v])
        {
            while (!vals[leaf].empty())
            {
                vals[leaf_mx[v]].push(vals[leaf].top());
                vals[leaf].pop();
            }
        }
    }

    while (!vals[leaf_mx[v]].empty() && vals[leaf_mx[v]].top() > kek[v])
    {
        vals[leaf_mx[v]].pop();
    }
    sol[v] = (int) vals[leaf_mx[v]].size();

    vals[leaf_mx[v]].push(val[v]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }

    for (int i = 2; i <= n; i++)
    {
        int p;
        ll dist;
        cin >> p >> dist;
        g[p].push_back({i, dist});
    }

    build(1);

    for (int i = 1; i <= n; i++)
    {
        val[i] = kek[i] - val[i];
    }

    solve(1);

    for (int i = 1; i <= n; i++)
    {
        cout << sol[i] << " ";
    }
    cout << "\n";
}