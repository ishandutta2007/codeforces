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
        string s;
        cin >> s;
        s.push_back('0');
        reverse(all(s));
        s.push_back('0');
        reverse(all(s));
        vector<int> a(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<int> dp[3];
        dp[0] = vector<int>(n + 2);
        dp[1] = vector<int>(n + 2);
        dp[2] = vector<int>(n + 2);
        for (int i = 1; i <= n + 1; i++)
        {
            if (s[i] == '1')
            {
                dp[0][i] = max(dp[0][i], dp[0][i - 1] + a[i - 1]);
                dp[1][i] = max(dp[1][i], dp[0][i - 1] + a[i]);
                dp[1][i] = max(dp[1][i], dp[1][i - 1] + a[i]);
                // cout << dp[0][i - 1] << ' ' << dp[1][i - 1] << ' ' << dp[2][i - 1] << '\n';
                // cout << dp[0][i - 1] + a[i + 1] << '\n';
                // cout << dp[1][i - 1] + a[i + 1] << '\n';
                // cout << dp[2][i - 1] + a[i + 1] << '\n';
            }
            else
            {
                dp[0][i] = max(dp[0][i], dp[0][i - 1] + 0);
                dp[0][i] = max(dp[0][i], dp[1][i - 1] + 0);
                dp[1][i] = max(dp[0][i], dp[2][i - 1] + 0);
                dp[2][i] = dp[1][i];
            }
            // cout << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << '\n';
        }
        cout << dp[1][n + 1] << '\n';
    }

    return 0;
}