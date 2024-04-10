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
        int v1 = min(s[0], s.back()) - 'a';
        int v2 = max(s[0], s.back()) - 'a';
        vector<int> pos[26];
        for (int i = 0; i < n; i++)
        {
            pos[s[i] - 'a'].push_back(i);
        }

        vector<int> ans;
        if (s[0] >= s.back())
        {
            for (int i = s[0] - 'a'; i >= s.back() - 'a'; i--)
                for (auto p : pos[i])
                    ans.push_back(p);
        }
        else
        {
            for (int i = s[0] - 'a'; i <= s.back() - 'a'; i++)
                for (auto p : pos[i])
                    ans.push_back(p);
        }
        cout << abs(v1 - v2) << ' ' << ans.size() << '\n';
        for (auto p : ans)
            cout << p + 1 << ' ';
        cout << '\n';
    }

    return 0;
}