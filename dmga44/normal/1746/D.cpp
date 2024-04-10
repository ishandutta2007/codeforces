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
ll s[MAXN];

pii dfs(int u, ll k)
{
    ll sum = 0;
    vector<ll> adds;
    for (auto v : g[u])
    {
        pii xx = dfs(v, k / (g[u].size()));
        sum += xx.first;
        adds.push_back(xx.second - xx.first);
    }

    sort(allr(adds));
    vector<ll> ac;
    ac.push_back(0);
    for (auto x : adds)
        ac.push_back(ac.back() + x);
    ll v1 = sum + k * s[u];
    ll v2 = sum + (k + 1) * s[u];
    if (g[u].size())
    {
        v1 += ac[k % (g[u].size())];
        v2 += ac[k % (g[u].size()) + 1];
    }
    return pii(v1, v2);
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
        vector<int> p(n);
        for (int i = 1; i < n; i++)
        {
            cin >> p[i];
            p[i]--;
            g[p[i]].push_back(i);
        }
        for (int i = 0; i < n; i++)
            cin >> s[i];
        // cout << "xxx" << flush;

        pii ans = dfs(0, k);
        // cout << "xxx" << flush;
        cout << ans.first << '\n';

        for (int i = 0; i < n; i++)
            g[i].clear();
    }

    return 0;
}