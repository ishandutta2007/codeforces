#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
const int K = 19;
int n;
int p[N];
int dep[N];
int euler_tour[2 * N];
int tour_sz;
int first_time_on_tour[N];
int last_time_on_tour[N];
int lg2[2 * N];
int sol[N];
int l[N];
int r[N];
int tree[N];
int initial[N];
int lr;
pair<int, int> lowest[N];
vector<int> g[N];
pair<int, int> tab_lca[2 * N][K];
pair<int, int> tab_lowest[N][K];
vector<pair<int, int>> op[N];
vector<int> events[N];

void add(int i, int x)
{
    while (i <= n)
    {
        tree[i] += x;
        i += i & (-i);
    }
}

int get(int i)
{
    int sol = 0;
    while (i)
    {
        sol += tree[i];
        i -= i & (-i);
    }
    return sol;
}

int get(int l, int r)
{
    return get(r) - get(l - 1);
}

void dfs_lca(int a)
{
    euler_tour[++tour_sz] = a;
    first_time_on_tour[a] = last_time_on_tour[a] = tour_sz;
    for (auto &b : g[a])
    {
        dep[b] = 1 + dep[a];
        dfs_lca(b);
        euler_tour[++tour_sz] = a;
        last_time_on_tour[a] = tour_sz;
    }
}

void lcaTM()
{
    dfs_lca(1);
    for (int i = 2; i <= tour_sz; i++)
    {
        lg2[i] = 1 + lg2[i / 2];
    }
    for (int i = 1; i <= tour_sz; i++)
    {
        tab_lca[i][0] = {dep[euler_tour[i]], euler_tour[i]};
    }
    for (int k = 1; (1 << k) <= tour_sz; k++)
    {
        for (int i = 1; i + (1 << k) - 1 <= tour_sz; i++)
        {
            tab_lca[i][k] = min(tab_lca[i][k - 1], tab_lca[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int lca(int a, int b)
{
    if (first_time_on_tour[a] > last_time_on_tour[b])
    {
        swap(a, b);
    }
    a = first_time_on_tour[a];
    b = last_time_on_tour[b];
    int k = lg2[b - a + 1];
    return min(tab_lca[a][k], tab_lca[b - (1 << k) + 1][k]).second;
}

void dfs_lowest(int a)
{
    for (auto &b : g[a])
    {
        dfs_lowest(b);
        lowest[a] = min(lowest[a], lowest[b]);
    }
}

void lowestTM()
{
    dfs_lowest(1);
    for (int i = 1; i <= n; i++)
    {
        tab_lowest[i][0] = lowest[i];
    }
    for (int k = 1; k < K; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (tab_lowest[i][k - 1].second != N)
            {
                tab_lowest[i][k] = tab_lowest[tab_lowest[i][k - 1].second][k - 1];
            }
        }
    }
}

void dfs_lr(int a)
{
    l[a] = ++lr;
    for (auto &b : g[a])
    {
        dfs_lr(b);
    }
    r[a] = lr;
}

void dfs_queries(int a)
{
    for (auto &it : op[a])
    {
        int b = it.first;
        int i = it.second;
        initial[i] = get(l[b], r[b]);
    }
    for (auto &i : events[a])
    {
        add(l[i], 1);
    }
    for (auto &b : g[a])
    {
        dfs_queries(b);
    }
    for (auto &it : op[a])
    {
        int b = it.first;
        int i = it.second;
        if (get(l[b], r[b]) > initial[i])
        {
            sol[i]--;
        }
    }
}

void queriesTM()
{
    dfs_lr(1);
    dfs_queries(1);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin>> p[i];
        g[p[i]].push_back(i);
    }
    lcaTM();
    int m;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        lowest[i] = {N, N};
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b;
        events[a].push_back(b);
        events[b].push_back(a);
        c = lca(a, b);
        lowest[a] = min(lowest[a], {dep[c], c});
        lowest[b] = min(lowest[b], {dep[c], c});
    }
    lowestTM();
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int a, b, c;
        cin >> a >> b;
        c = lca(a, b);
        int cost = 0;
        for (int k = K - 1; k >= 0; k--)
        {
            if (tab_lowest[a][k].first != N && tab_lowest[a][k].first > dep[c])
            {
                a = tab_lowest[a][k].second;
                cost += (1 << k);
            }
        }
        for (int k = K - 1; k >= 0; k--)
        {
            if (tab_lowest[b][k].first != N && tab_lowest[b][k].first > dep[c])
            {
                b = tab_lowest[b][k].second;
                cost += (1 << k);
            }
        }
        if (lowest[a].first > dep[c] || lowest[b].first > dep[c])
        {
            sol[i] = -1;
            continue;
        }
        cost += 2;
        if (c == a || c == b)
        {
            sol[i] = cost - 1;
            continue;
        }
        op[a].push_back({b, i});
        sol[i] = cost;
    }
    queriesTM();
    for (int i = 1; i <= q; i++)
    {
        cout << sol[i] << "\n";
    }
}
/// to do : compute Lowest common ancestor
/// I forgot to complete the to do list :))) and ended up writing the code without any to do list
/// I love this kind of problems :>>