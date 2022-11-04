#include <bits/stdc++.h>

using namespace std;

long long ans = 0;
vector<pair<int, int> > mas[(int)5e5 + 10], arr[(int)5e5 + 10];
int sz[(int)5e5 + 10], pr[(int)5e5 + 10], used[(int)5e5 + 10];

int get(int v)
{
    if (pr[v] == v)
        return v;
    return pr[v] = get(pr[v]);
}

void add(int a, int b)
{
    a = get(a);
    b = get(b);
    if (sz[a] < sz[b])
        swap(a, b);
    pr[b] = a;
    sz[a] += sz[b];
}

void add(set<pair<int, int> > &se, pair<int, int> p)
{
    if (se.count(p))
        se.erase(p);
    else
        se.insert(p);
}

void dfs(int v, set<pair<int, int> > &se)
{
    used[v] = 1;
    for (auto p: mas[v])
    {
        int u = p.first;
        if (used[u] == 0)
        {
            set<pair<int, int> > nw;
            dfs(u, nw);
            if (p.second)
            {
                if (nw.size() == 0)
                {
                    cout << -1 << endl;
                    exit(0);
                }
                ans += nw.begin()->first;
            }
            if (se.size() < nw.size())
                swap(se, nw);
            for (auto p: nw)
                add(se, p);
        }
    }
    for (auto p: arr[v])
        add(se, p);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
    {
        sz[i] = 1;
        pr[i] = i;
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mas[a].push_back({b, 1});
        mas[b].push_back({a, 1});
        add(a, b);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (get(a) != get(b))
        {
            mas[a].push_back({b, 0});
            mas[b].push_back({a, 0});
            add(a, b);
        }
        else
        {
            arr[a].push_back({c, i});
            arr[b].push_back({c, i});
        }
    }
    set<pair<int, int> > se;
    dfs(0, se);
    cout << ans << endl;
    return 0;
}