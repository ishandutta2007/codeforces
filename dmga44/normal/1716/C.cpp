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
        int n;
        cin >> n;
        vector<ll> a[2];
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[0].push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a[1].push_back(x);
        }

        vector<ll> prec[2][2];
        prec[0][0].push_back(a[0][n - 1] + (n - 1));
        prec[0][1].push_back(a[0][n - 1] - (n - 1));
        prec[1][0].push_back(a[1][n - 1] + (n - 1));
        prec[1][1].push_back(a[1][n - 1] - (n - 1));
        for (int i = n - 2; i >= 0; i--)
        {
            {
                ll v = a[0][i];
                prec[0][0].push_back(max(prec[0][0].back(), v + i));
                prec[0][1].push_back(max(prec[0][1].back(), v - i));
            }
            {
                ll v = a[1][i];
                prec[1][0].push_back(max(prec[1][0].back(), v + i));
                prec[1][1].push_back(max(prec[1][1].back(), v - i));
            }
        }
        reverse(all(prec[0][0]));
        reverse(all(prec[0][1]));
        reverse(all(prec[1][0]));
        reverse(all(prec[1][1]));
        prec[0][0].push_back(-1e9);
        prec[0][1].push_back(-1e9);
        prec[1][0].push_back(-1e9);
        prec[1][1].push_back(-1e9);

        ll act = 0;
        ll ans = 2e9;
        pii pos = pii(0, 0);
        while (pos.second < n)
        {
            int c = pos.second;
            if (pos.first == 0)
            {
                ll time1 = max(act - c - 1, (ll)prec[0][1][c + 1]) + n;
                ll time2 = max((ll)a[1][n - 1] + 1, time1 + 1);
                time2 = max(time2 + (n - 1) - 1, prec[1][0][c]) - (c - 1);
                ans = min(ans, time2);
                if (c + 1 < n)
                    act = max({act + 2, a[1][c] + 2, a[1][c + 1] + 1});
                pos = pii(1, c + 1);
                //vdfbgfh
            }
            else
            {
                ll time1 = max(act - c - 1, (ll)prec[1][1][c + 1]) + n;
                ll time2 = max((ll)a[0][n - 1] + 1, time1 + 1);
                time2 = max(time2 + (n - 1) - 1, prec[0][0][c]) - (c - 1);
                ans = min(ans, time2);

                if (c + 1 < n)
                    act = max({act + 2, a[0][c] + 2, a[0][c + 1] + 1});
                pos = pii(0, c + 1);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}