#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, a[400005], used[400005], Min[400005], Max[400005], T, t[4000005], tx[4000005];
vector <int> g[400005];

void push(int v, int l, int r)
{
    tx[2 * v + 1] = tx[v];
    tx[2 * v + 2] = tx[v];
    t[2 * v + 1] = tx[v];
    t[2 * v + 2] = tx[v];
    tx[v] = 0;
}

int get(int v, int l, int r, int L, int R)
{
    if(L >= R)
        return 0;

    if(tx[v] > 0)
        return tx[v];

    if(L == l && R == r)
        return t[v];

    int m = (l + r) / 2;

    return (get(2 * v + 1, l, m, L, min(m, R)) | get(2 * v + 2, m, r, max(m, L), R));
}

void update(int v, int l, int r, int L, int R, int val)
{
    if(L >= R)
        return;

    if(L == l && R == r)
    {
        tx[v] = val;
        t[v] = val;
        return;
    }

    if(tx[v] > 0)
        push(v, l, r);

    int m = (l + r) / 2;

    update(2 * v + 1, l, m, L, min(m, R), val);
    update(2 * v + 2, m, r, max(L, m), R, val);

    t[v] = (t[2 * v + 1] | t[2 * v + 2]);
}

void dfs(int v)
{
    used[v] = 1;

    Min[v] = T;
    T++;

    for(auto to:g[v])
        if(used[to] == 0)
            dfs(to);

    Max[v] = T;
    T++;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = (1ll << a[i]);
    }

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0);
    T++;

    for(int i = 0; i < n; i++)
    {
        update(0, 0, T, Min[i], Min[i] + 1, a[i]);
        update(0, 0, T, Max[i], Max[i] + 1, a[i]);
    }

    while(m--)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            int v, c;
            cin >> v >> c;
            v--;
            c = (1ll << c);

            update(0, 0, T, Min[v], Max[v] + 1, c);
        }
        else
        {
            int v;
            cin >> v;
            v--;

            int x = get(0, 0, T, Min[v], Max[v] + 1);
            int ans = 0;

            while(x)
            {
                ans += x % 2;
                x /= 2;
            }

            cout << ans << "\n";
        }
    }
}