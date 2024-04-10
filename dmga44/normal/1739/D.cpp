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
#define MAXN (ll)(2e5 + 5)

vector<int> g[MAXN];

pii dfs(int u, int p, int l, int s0)
{
    int sum = 0;
    ll ma = 0;
    for (auto v : g[u])
        if (v != p)
        {
            pii x = dfs(v, u, l, u == 0);
            sum += x.first;
            ma = max(ma, x.second);
        }
    if (ma == l - 1 && u && !s0)
    {
        // cout << u << '\n';
        return pii(sum + 1, 0);
    }
    return pii(sum, ma + 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n - 1; i++)
        {
            int p;
            cin >> p;
            p--;
            g[p].push_back(i + 1);
        }

        // cout << dfs(0,-1,1,0).first << '\n';
        // cout << '\n';
        int ans = 0;
        for (int po = (1 << 17); po; po >>= 1)
            if (dfs(0, -1, ans + po, 0).first > k)
                ans += po;
        ans++;
        cout << ans << '\n';

        for (int i = 0; i < n; i++)
        {
            g[i].clear();
        }
    }

    return 0;
}