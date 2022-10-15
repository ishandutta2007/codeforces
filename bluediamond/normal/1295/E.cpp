#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
const ll INF = (ll) 1e18;
int n, a[N], cost[N], pos[N];
ll segt[4 * N], surp[4 * N];

void push(int v, int tl, int tr)
{
        if (surp[v])
        {
                segt[v] += surp[v];
                if (tl < tr)
                {
                        surp[2 * v] += surp[v];
                        surp[2 * v + 1] += surp[v];
                }
                surp[v] = 0;
        }
}

void add(int v, int tl, int tr, int l, int r, ll x)
{
        push(v, tl, tr);
        if (tr < l || r < tl)
                return;
        if (l <= tl && tr <= r)
        {
                surp[v] += x;
                push(v, tl, tr);
        }
        else
        {
                int tm = (tl + tr) / 2;
                add(2 * v, tl, tm, l, r, x);
                add(2 * v + 1, tm + 1, tr, l, r, x);
                segt[v] = min(segt[2 * v], segt[2 * v + 1]);
        }
}

void add(int l, int r, ll x)
{
        add(1, 1, n, l, r, x);
}

ll get()
{
        push(1, 1, n);
        return segt[1];
}

ll get(int v, int tl, int tr, int l, int r)
{
        push(v, tl, tr);
        if (tr < l || r < tl)
                return INF;
        if (l <= tl && tr <= r)
                return segt[v];
        else
        {
                int tm = (tl + tr) / 2;
                return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
        }
}

ll get(int l, int r)
{
        return get(1, 1, n, l, r);
}

void read()
{
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
                cin >> a[i];
                pos[a[i]] = i;
        }
        for (int i = 1; i <= n; i++)
                cin >> cost[i];
}

ll solve()
{
        ll pref = 0;
        for (int i = 1; i <= n; i++)
        {
                pref += cost[i];
                add(i, i, pref);
        }
        ll sol = get(1, n);
        for (int val = 1; val <= n; val++)
        {
                add(1, pos[val] - 1, cost[pos[val]]);
                add(pos[val], n, -cost[pos[val]]);
                sol = min(sol, get(1, n - 1));
        }
        return sol;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        read();
        cout << solve() << "\n";
}