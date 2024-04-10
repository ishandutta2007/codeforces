#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 998244353;

int add_MOD(int a, int b)
{
    a += b;
    if (a >= MOD)
    {
        return a - MOD;
    }
    if (a < 0)
    {
        return a + MOD;
    }
    return a;
}

int mul_MOD(int a, int b)
{
    return a * (ll) b % MOD;
}

const int N = (int) 2e5 + 7;
int n;
int q;
int brute[N];
vector<vector<int>> queries;
vector<pair<int, int>> segments[N];
vector<bool> is[N];
vector<int> urm[N];
map<int, int> who_l[N];
map<int, int> who_r[N];
map<int, int> id[N];
set<int> changes[N];

struct T
{
    int a;
    int b;
    int val;
};

T segt[4 * N];

void push(int v, int tl, int tr)
{
    segt[v].val = add_MOD(mul_MOD(tr - tl + 1, segt[v].b), mul_MOD(segt[v].val, segt[v].a));
    if (tl < tr)
    {
        segt[2 * v].a = mul_MOD(segt[2 * v].a, segt[v].a);
        segt[2 * v + 1].a = mul_MOD(segt[2 * v + 1].a, segt[v].a);
        segt[2 * v].b = add_MOD(segt[v].b, mul_MOD(segt[2 * v].b, segt[v].a));
        segt[2 * v + 1].b = add_MOD(segt[v].b, mul_MOD(segt[2 * v + 1].b, segt[v].a));
    }
    segt[v].a = 1;
    segt[v].b = 0;
}


void add(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        segt[v].b = 1;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    add(2 * v, tl, tm, l, r);
    add(2 * v + 1, tm + 1, tr, l, r);
    segt[v].val = add_MOD(segt[2 * v].val, segt[2 * v + 1].val);
}

void mult(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        segt[v].a = 2;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    mult(2 * v, tl, tm, l, r);
    mult(2 * v + 1, tm + 1, tr, l, r);
    segt[v].val = add_MOD(segt[2 * v].val, segt[2 * v + 1].val);
}

int get(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return 0;
    }
    if (l <= tl && tr <= r)
    {
        return segt[v].val;
    }
    else
    {
        int tm = (tl + tr) /2;
        return add_MOD(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
    }

}

void add_brute(int l, int r)
{
    add(1, 1, n, l, r);
    return;
    for (int i = l; i <= r; i++)
    {
        brute[i] = add_MOD(brute[i], 1);
    }
}

void mult_brute(int l, int r)
{
    mult(1, 1, n, l, r);
    return;
    for (int i = l; i <= r; i++)
    {
        brute[i] = mul_MOD(brute[i], 2);
    }
}

int get_brute(int l, int r)
{
    return get(1, 1, n, l, r);
    int sol = 0;
    for (int i = l; i <= r; i++)
    {
        sol = add_MOD(sol, brute[i]);
    }
    return sol;
}

void add(int l, int r, int x)
{
    /// pe l...r adaug x
    int p = who_l[x][l];
    int p2 = who_r[x][r];
    while (p <= p2)
    {
        if (is[x][p])
        {
            int until = urm[x][p];
            if (until > p2)
            {
                until = p2;
            }
            mult_brute(segments[x][p].first, segments[x][until].second);
            int ant_p = p;
            p = urm[x][p] + 1;
            urm[x][ant_p] = max(urm[x][ant_p], p2);
        }
        else
        {
            is[x][p] = 1;
            add_brute(segments[x][p].first, segments[x][p].second);
            urm[x][p] = p2;
            p++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4 * N; i++)
    {
        segt[i].a = 1;
    }

    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            int x;
            cin >> x;
            queries.push_back({l, r, x});
            changes[x].insert(l);
            changes[x].insert(r + 1);
        }
        else
        {
            queries.push_back({l, r});
        }
    }
    for (int x = 1; x <= n; x++)
    {
        changes[x].insert(1);
        changes[x].insert(n + 1);
        int j = -1;
        for (auto &i : changes[x])
        {
            if (j != -1)
            {
                segments[x].push_back({j, i - 1});
            }
            j = i;
        }
        is[x].resize((int) segments[x].size(), 0);
        urm[x].resize((int) segments[x].size());
        for (int j = 0; j < (int) segments[x].size(); j++)
        {
            who_l[x][segments[x][j].first] = j;
            who_r[x][segments[x][j].second] = j;
        }
    }
    for (auto &vec : queries)
    {
        if ((int) vec.size() == 3)
        {
            add(vec[0], vec[1], vec[2]);
        }
        else
        {
            cout << get_brute(vec[0], vec[1]) << "\n";
        }
    }
}