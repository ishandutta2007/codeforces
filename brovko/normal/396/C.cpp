#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int Q = 500;
const int MOD = 1e9 + 7;

mt19937 rnd(time(NULL));

int n, p[300005], used[300005], tin[300005], tout[300005], T, d[300005], a[300005], b[300005], used2[300005];
vector <int> g[300005];

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int sub(int x, int y)
{
    return add(x, MOD - y);
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

void dfs(int v)
{
    tin[v] = ++T;

    for(auto to:g[v])
        dfs(to);

    tout[v] = ++T;
}

bool is_anc(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    vector <int> uv;

//    for(int i = 0; i < Q; i++)
//    {
//        int x = rnd() % n;
//
//        if(used[x] == 0)
//        {
//            used[x] = 1;
//            uv.pb(x);
//        }
//    }

    for(int i = 1; i < n; i++)
        g[p[i]].pb(i);

    dfs(0);

    for(int i = 1; i < n; i++)
        d[i] = d[p[i]] + 1;

    int F = 1;

    while(F)
    {
        int x = 0;

        for(int i = 0; i < n; i++)
            if(used2[i] == 0 && d[i] > d[x])
                x = i;

        for(int i = 0; i < Q; i++)
            x = p[x];

        if(x == 0)
        {
            F = 0;
            break;
        }

        used[x] = 1;
        uv.pb(x);

        for(int i = 0; i < n; i++)
            if(is_anc(x, i))
                used2[i] = 1;
    }

//    cout << "!" << uv.size() << endl;
//
//    for(auto x:uv)
//        cout << x << ' ';
//
//    cout << endl;

    int q;
    cin >> q;

    while(q--)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            int v, x, k;
            cin >> v >> x >> k;

            v--;

            if(used[v] == 0)
            {
                a[v] = add(a[v], x);
                b[v] = add(b[v], k);
            }

            for(auto z:uv)
            {
                if(is_anc(v, z))
                {
                    a[z] = add(a[z], sub(x, mul(k, d[z] - d[v])));
                    b[z] = add(b[z], k);
                }
            }
        }
        else
        {
            int v;
            cin >> v;

            v--;

            int u = v;
            int ans = 0;

            while(u != 0 && used[u] == 0)
            {
                ans = add(ans, sub(a[u], mul(b[u], d[v] - d[u])));
                u = p[u];
            }

            ans = add(ans, sub(a[u], mul(b[u], d[v] - d[u])));
            cout << ans << "\n";
        }
    }
}