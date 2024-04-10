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

ll qp(ll b, ll e)
{
    ll ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (ans * b) % mod;
        e >>= 1;
        b = (b * b) % mod;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> ans(n);
        ll sum = 0;
        ll act = n;
        for (int i = n - 1; i >= 0; i--)
        {
            int cant = i / 2;
            if (i == n - 1)
            {
                ans[i] = qp(qp(2, mod - 2), cant);
                continue;
            }
            if ((i + 1) * 2 <= n)
            {
                while (act != (i + 1) * 2 - 1)
                {
                    act--;
                    sum = (sum + ans[act]) % mod;
                }
            }
            ans[i] = (qp(qp(2, mod - 2), cant + 1) * (1 - sum + mod)) % mod;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << '\n';
    }

    return 0;
}