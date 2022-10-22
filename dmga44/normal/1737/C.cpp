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
        vector<pii> v;
        for (int i = 0; i < 3; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back(pii(x, y));
        }
        int x, y;
        cin >> x >> y;
        sort(all(v));
        bool ok = 0;
        for (int i = 0; i < 3; i++)
            if (((x & 1) == (v[i].first & 1)) && ((y & 1) == (v[i].second & 1)))
                ok = 1;
        if (!ok)
        {
            cout << "NO\n";
            continue;
        }
        vector<pii> corner1;
        vector<pii> corner2;
        vector<pii> corner3;
        vector<pii> corner4;
        corner1.push_back(pii(1, 1));
        corner1.push_back(pii(1, 2));
        corner1.push_back(pii(2, 1));

        corner2.push_back(pii(1, n - 1));
        corner2.push_back(pii(1, n));
        corner2.push_back(pii(2, n));

        corner3.push_back(pii(n - 1, 1));
        corner3.push_back(pii(n, 1));
        corner3.push_back(pii(n, 2));

        corner4.push_back(pii(n - 1, n));
        corner4.push_back(pii(n, n - 1));
        corner4.push_back(pii(n, n));
        bool ok1 = 1;
        for (int i = 0; i < 3; i++)
            ok1 = ok1 & corner1[i] == v[i];
        bool ok2 = 1;
        for (int i = 0; i < 3; i++)
            ok2 = ok2 & corner2[i] == v[i];
        bool ok3 = 1;
        for (int i = 0; i < 3; i++)
            ok3 = ok3 & corner3[i] == v[i];
        bool ok4 = 1;
        for (int i = 0; i < 3; i++)
            ok4 = ok4 & corner4[i] == v[i];
        if (ok1)
        {
            if (x == 1 || y == 1)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
            continue;
        }
        if (ok2)
        {
            if (x == 1 || y == n)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
            continue;
        }
        if (ok3)
        {
            if (x == n || y == 1)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
            continue;
        }
        if (ok4)
        {
            if (x == n || y == n)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }

    return 0;
}