#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
const int A = 2 * N;
int n;
int l[N];
int r[N];
set<int> pts;
map<int, int> trans;
int invp[A];
int x[A];
int mn[4 * A];
int cur;

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        mn[v] = x[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
    }
}

int get(int v, int tl, int tr, int l, int r)
{
    if (tr < l || r < tl)
    {
        return (int) 1e9;
    }
    if (l <= tl && tr <= r)
    {
        return mn[v];
    }
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int get(int l, int r)
{
    return get(1, 1, cur, l, r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        pts.insert(l[i]);
        pts.insert(r[i] + 1);
    }
    for (auto &x : pts)
    {
        trans[x] = ++cur;
        invp[cur] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        l[i] = trans[l[i]];
        r[i] = trans[r[i] + 1] - 1;
        x[l[i]]++;
        x[r[i] + 1]--;
    }
    for (int i = 1; i <= cur; i++)
    {
        x[i] += x[i - 1];
    }
    build(1, 1, cur);
    for (int i = 1; i <= n; i++)
    {
        if (get(l[i], r[i]) >= 2)
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}