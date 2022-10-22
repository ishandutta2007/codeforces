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
typedef pair<int, int> pii;
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
        vector<int> d1(n), d2(n);
        for (int i = 0; i < n; i++)
            cin >> d1[i];
        for (int i = 0; i < n; i++)
            cin >> d2[i];
        set<int> f;
        for (int i = 0; i < n; i++)
        {
            f.insert(abs(d1[0] - d2[i]));
            f.insert(abs(d1[0] + d2[i]));
        }

        sort(all(d1));
        sort(all(d2));

        bool ok = 0;
        for (auto v : f)
        {
            if (!v)
            {
                bool okk = 1;
                for (int i = 0; i < n; i++)
                    okk &= (d1[i] == d2[i]);
                if (okk)
                {
                    cout << "YES\n";
                    for (int i = 0; i < n; i++)
                        cout << d1[i] << ' ';
                    cout << '\n';
                    cout << 0 << ' ' << 0 << '\n';
                    ok = 1;
                    break;
                }
                continue;
            }
            vector<int> ans(n);
            int mi = 0;

            set<pii> s1, s2;
            for (int i = 0; i < n; i++)
            {
                s1.insert(pii(-d1[i], i));
                s2.insert(pii(-d2[i], i));
            }

            while (!s1.empty())
            {
                pii p1 = *s1.begin();
                pii p2 = *s2.begin();
                p1.first *= -1;
                p2.first *= -1;
                if (p1.first < p2.first)
                {
                    int tar = abs(p2.first - v);
                    auto it = s1.lower_bound(pii(-tar, 0));
                    if (it == s1.end() || (*it).first != -tar)
                        break;
                    if (tar + v == p2.first)
                        ans[(*it).second] = (*it).first;
                    else
                        ans[(*it).second] = -(*it).first;

                    mi = min(ans[(*it).second], mi);
                    p2.first *= -1;
                    s2.erase(p2);
                    s1.erase(*it);
                }
                else
                {
                    int tar = abs(p1.first - v);
                    auto it = s2.lower_bound(pii(-tar, 0));
                    if (it == s2.end() || (*it).first != -tar)
                        break;
                    ans[p1.second] = p1.first;

                    mi = min(ans[p1.second], mi);
                    p1.first *= -1;
                    s1.erase(p1);
                    s2.erase(*it);
                }
            }

            if (!s1.empty())
                continue;
            // this is it
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << ans[i] - mi << ' ';
            cout << '\n';
            cout << -mi << ' ' << v - mi << '\n';
            ok = 1;
            break;
        }
        if (!ok)
            cout << "NO\n";
    }

    return 0;
}