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
        string s;
        cin >> s;
        int n = s.size();
        int w, q;
        cin >> w >> q;
        vector<int> ac(n + 1);
        for (int i = 0; i < n; i++)
            ac[i + 1] = (ac[i] + s[i] - '0') % 9;
        vector<int> pos[9];
        for (int i = 0; i + w <= n; i++)
            pos[(ac[i + w] - ac[i] + 9) % 9].push_back(i + 1);
        // cout << "xxxx\n"
        //      << flush;
        while (q--)
        {
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            ll v = (ac[r + 1] - ac[l] + 9) % 9;
            pii ans = pii(-1, -1);
            for (int i = 0; i < 9; i++)
            {
                // cout << i << ' ' << l << ' ' << r << '\n'
                //      << flush;
                if (pos[i].empty())
                    continue;
                int l1 = pos[i][0];
                // cout << l1 << '\n' << flush;
                int v2 = (k - ((v * i) % 9) + 9) % 9;
                // cout << v2 << '\n' << flush;
                int l2;
                if (v2 == i)
                {
                    if (pos[i].size() == 1)
                        continue;
                    l2 = pos[i][1];
                }
                else
                {
                    if (pos[v2].empty())
                        continue;
                    l2 = pos[v2][0];
                }
                if (ans.first == -1)
                {
                    ans = pii(l1, l2);
                }
                else
                {
                    ans = min(pii(l1, l2), ans);
                }
            }
            cout << ans.first << ' ' << ans.second << '\n'
                 << flush;
            ;
        }
    }

    return 0;
}