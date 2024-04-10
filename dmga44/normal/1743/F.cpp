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
const ll mod = (998244353);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(3e5 + 5)

ll qp(ll b, ll e)
{
    ll ans = 1;
    for (; e; e >>= 1, b = (b * b) % mod)
        if (e & 1)
            ans = (ans * b) % mod;
    return ans;
}

vector<int> add[MAXN];
vector<int> quit[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        add[l].push_back(i);
        quit[r + 1].push_back(i);
    }

    set<int> pos;
    ll ans = 0;
    for (int i = 0; i < MAXN; i++)
    {
        for (auto id : add[i])
            pos.insert(-id);
        for (auto id : quit[i])
            pos.erase(-id);
        if (pos.empty())
            continue;
        int last = -(*pos.begin());
        // cout << i << ' ' << last << '\n';
        if (last > 0)
            ans = (ans + qp(3, last - 1) * qp(2, n - last)) % mod;
        else
            ans = (ans + qp(2, n - 1)) % mod;
    }
    cout << ans << '\n';

    return 0;
}