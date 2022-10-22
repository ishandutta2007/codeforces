#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX

/// UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll, ll> pii;
typedef pair<ld, ll> pdi;
typedef pair<ld, ld> pdd;
typedef pair<ld, pdd> pdp;
typedef pair<string, ll> psi;
typedef pair<ll, string> pls;
typedef pair<string, string> pss;
typedef pair<ll, pii> pip;
typedef pair<pii, pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point, int> ppi;
#define prec(n)        \
    cout.precision(n); \
    cout << fixed
const ll mod = (1e9 + 7);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(1e6 + 5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pip> edges;
        vector<vector<int>> d(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++)
            d[i][i] = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            d[u][v] = d[v][u] = 1;
            edges.push_back(pip(w, pii(u, v)));
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        ll ans = 1e18;
        for (int i = 0; i < m; i++)
        {
            // cout << i << ' ' << (d[0][edges[i].second.first] + d[n - 1][edges[i].second.second] + 1) << ' ' << edges[i].first << '\n';
            ans = min(ans, edges[i].first * min({(d[0][edges[i].second.first] + d[n - 1][edges[i].second.second] + 1),
                                                 (d[n - 1][edges[i].second.first] + d[0][edges[i].second.second] + 1)}));
            for (int j = 0; j < n; j++)
                ans = min(ans, edges[i].first * (d[0][j] + d[j][n - 1] + min(d[j][edges[i].second.first], d[j][edges[i].second.second]) + 2));
        }
        cout << ans << '\n';
    }

    return 0;
}