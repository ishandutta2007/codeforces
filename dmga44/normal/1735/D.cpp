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

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            cin >> a[i][j];

    set<ll> vals;
    for (int i = 0; i < n; i++)
    {
        ll v = 0;
        for (int j = 0; j < k; j++)
            v = (v * 3 + a[i][j]);
        vals.insert(v);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll times = 0;
        for (int j = 0; j < n; j++)
        {
            ll v = 0;
            for (int l = 0; l < k; l++)
            {
                int add = a[i][l];
                if (a[i][l] != a[j][l])
                    add = 3 - (a[i][l] + a[j][l]);
                v = (v * 3 + add);
            }
            times += vals.count(v);
        }
        times /= 2;
        ans += ((times) * (times - 1)) / 2;
    }
    cout << ans << '\n';

    return 0;
}