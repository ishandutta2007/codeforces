#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
const int K = 18;
int n;
int q;
int w[N];
int first[N];
int last[N];
int euler[2 * N];
int dep[N];
int top;
int lg[2 * N];
int rad;
pair<int, int> tab[K][2 * N];
vector<int> g[N];
int l[N];
int r[N];
int v[2 * N];
int y;
int f[2][N];
int cnt;
bool act[N];
ll sol;
int sex[N];

void dfs1(int a, int p)
{
    euler[++top] = a;
    first[a] = last[a] = top;
    for (auto &b : g[a])
    {
        if (b != p)
        {
            dep[b] = 1 + dep[a];
            dfs1(b, a);
            euler[++top] = a;
            last[a] = top;
        }
    }
}

int lca(int a, int b)
{
    if (first[a] > last[b])
    {
        swap(a, b);
    }
    a = first[a];
    b = last[b];
    int k = lg[b - a + 1];
    return min(tab[k][a], tab[k][b - (1 << k) + 1]).second;
}

void dfs2(int a, int p)
{
    l[a] = ++y;
    v[y] = a;
    for (auto &b : g[a])
    {
        if (b != p)
        {
            dfs2(b, a);
        }
    }
    r[a] = ++y;
    v[y] = a;
}

struct T
{
    int l;
    int r;
    int extra_node;
    int i;
};

bool operator < (T a, T b)
{
    if (a.l / rad != b.l / rad)
    {
        return a.l < b.l;
    }
    else
    {
        return a.r < b.r;
    }
}

void op(int node)
{
    if (act[node] == 0) /// add
    {
        sol += f[sex[node] ^ 1][w[node]];
        f[sex[node]][w[node]]++;
    }
    else /// delete
    {
        sol -= f[sex[node] ^ 1][w[node]];
        f[sex[node]][w[node]]--;
    }
    act[node] ^= 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> norm;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> sex[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        norm[w[i]] = 0;
    }
    int cid = 0;
    for (auto &it : norm)
    {
        it.second = ++cid;
    }
    for (int i = 1; i <= n; i++)
    {
        w[i] = norm[w[i]];
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for (int i = 2; i <= top; i++)
    {
        lg[i] = 1 + lg[i / 2];
    }
    for (int i = 1; i <= top; i++)
    {
        tab[0][i] = {dep[euler[i]], euler[i]};
    }
    for (int k = 1; (1 << k) <= top; k++)
    {
        for (int i = 1; i + (1 << k) - 1 <= top; i++)
        {
            tab[k][i] = min(tab[k - 1][i], tab[k - 1][i + (1 << (k - 1))]);
        }
    }
    rad = sqrt(2 * n);
    int q;
    cin >> q;
    vector<T> qs(q);
    vector<ll> print(q, -1);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        int c = lca(a, b);
        if (c == b)
        {
            swap(a, b);
        }
        if (c == a)
        {
            qs[i] = {l[a], l[b], -1, i};
        }
        else
        {
            if (r[a] > l[b])
            {
                swap(a, b);
            }
            qs[i] = {r[a], l[b], c, i};
        }
    }
    sort(qs.begin(), qs.end());
    int l = 1, r = 1;
    op(v[1]);
    for (auto &it : qs)
    {
        for (int step = 0; step < 2; step++)
        {
            while (l < r && l < it.l) op(v[l++]);
            while (l > it.l) op(v[--l]);
            while (r < it.r) op(v[++r]);
            while (r > it.r && r > l) op(v[r--]);
        }
        if (it.extra_node != -1) op(it.extra_node);
        print[it.i] = sol;
        if (it.extra_node != -1) op(it.extra_node);
    }
    for (int i = 0; i < q; i++)
    {
        cout << print[i] << "\n";
    }
}