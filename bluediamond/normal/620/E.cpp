#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cnt_bits(ll x)
{
    int r = 0;
    while (x)
    {
        r++;
        x -= x & (-x);
    }
    return r;
}

const int N = (int) 4e5 + 7;
const int M = 650;
int n;
int m;
int rad;
int col[N];
ll or_bucket[M];
int same[M];
int rep[N];
int first[M];
int last[M];

void splay(int bid)
{
    if (same[bid])
    {
        for (int i = first[bid]; i <= last[bid]; i++)
        {
            col[i] = same[bid];
        }
        same[bid] = 0;
    }
}

void upd(int l, int r, int x)
{
    splay(rep[l]);
    splay(rep[r]);
    for (int i = l; i <= last[rep[l]] && i <= r; i++)
    {
        col[i] = x;
    }
    for (int i = r; i >= first[rep[r]] && i >= l; i--)
    {
        col[i] = x;
    }
    or_bucket[rep[l]] = or_bucket[rep[r]] = 0;
    for (int i = first[rep[l]]; i <= last[rep[l]]; i++)
    {
        or_bucket[rep[l]] |= (1LL << col[i]);
    }
    for (int i = first[rep[r]]; i <= last[rep[r]]; i++)
    {
        or_bucket[rep[r]] |= (1LL << col[i]);
    }
    for (int i = rep[l] + 1; i < rep[r]; i++)
    {
        same[i] = x;
        or_bucket[i] = (1LL << x);
    }
}

int xoxo[N];

int get(int l, int r)
{
    splay(rep[l]);
    splay(rep[r]);
    ll ans = 0;
    for (int i = l; i <= last[rep[l]] && i <= r; i++)
    {
        ans |= (1LL << col[i]);
    }
    for (int i = r; i >= first[rep[r]] && i >= l; i--)
    {
        ans |= (1LL << col[i]);
    }
    for (int i = rep[l] + 1; i < rep[r]; i++)
    {
        ans |= or_bucket[i];
    }
    return cnt_bits(ans);
}

vector<int> g[N];
bool u[N];
int cur;
int ff[N];
int ss[N];

void dfs(int a)
{
    cur++;
    ff[a] = cur;
    u[a] = 1;
    for (auto &b : g[a])
    {
        if (u[b] == 0)
        {
            dfs(b);
        }
    }
    ss[a] = cur;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    rad = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        rep[i] = (i - 1) / rad;
        cin >> xoxo[i];
    }
    for (int i = 1; i <= n; i++)
    {
        last[rep[i]] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        first[rep[i]] = i;
    }
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        upd(ff[i], ff[i], xoxo[i]);
    }
    while (m--)
    {
        int tp;
        cin >> tp;
        if (tp == 1)
        {
            int v, c;
            cin >> v >> c;
            upd(ff[v], ss[v], c);
        }
        else
        {
            int v;
            cin >> v;
            cout << get(ff[v], ss[v]) << "\n";
        }
    }
}