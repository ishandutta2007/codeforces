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
#define MAXN (ll)(5e3 + 5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll p1, t1;
    cin >> p1 >> t1;
    ll p2, t2;
    cin >> p2 >> t2;
    ll h, s;
    cin >> h >> s;
    vector<pii> states;
    states.push_back(pii(t1, t2));
    vector<vector<int>> g;
    int fin = 1;
    for (int i = 0; i < states.size() && states.size() < MAXN; i++)
    {
        g.push_back({});
        ll v1 = states[i].first;
        ll v2 = states[i].second;
        g[i].push_back(0);
        ll x = min(v1, v2);
        v1 -= x;
        v2 -= x;
        if (!v1)
            v1 = t1;
        if (!v2)
            v2 = t2;
        if (v1 == t1 && v2 == t2)
        {
            fin = 0;
            continue;
        }
        g[i].push_back(i + 1);
        states.push_back(pii(v1, v2));
    }

    vector<vector<ll>> dp(h + 1, vector<ll>(MAXN, 1e18));
    dp[0] = vector<ll>(MAXN, 0);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j < states.size() - fin; j++)
        {
            // wait
            ll t = max(states[j].first, states[j].second);
            if (p1 + p2 - s >= i)
                dp[i][j] = min(dp[i][j], t);
            else
                dp[i][j] = min(dp[i][j], t + dp[i - (p1 + p2 - s)][0]);

            if (g[j].size() > 1)
            {
                ll t = min(states[j].first, states[j].second);
                ll dam = p1 - s;
                if (states[j].second == t)
                    dam = p2 - s;
                if (dam >= i)
                    dp[i][j] = min(dp[i][j], t);
                else
                    dp[i][j] = min(dp[i][j], t + dp[i - dam][j + 1]);
            }
        }
    }
    cout << dp[h][0] << '\n';

    return 0;
}