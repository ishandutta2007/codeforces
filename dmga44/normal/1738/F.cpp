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

int ask(int u)
{
    cout << "? " << u + 1 << '\n';
    cout.flush();
    int v;
    cin >> v;
    return v - 1;
}

int32_t main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> d(n);
        vector<pii> ts;
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
            ts.push_back(pii(d[i], i));
        }

        sort(allr(ts));

        vector<int> mk(n);
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
        {
            int u = ts[i].second;
            // cout << u << '\n';
            if (mk[u])
                continue;
            // cout << u << '\n';
            mk[u] = 1;
            int times = 0;
            do
            {
                if (times == d[u])
                    break;
                int v = ask(u);
                g[u].push_back(v);
                g[v].push_back(u);
                if (mk[v])
                    break;
                mk[v] = 1;
                times++;
            } while (1);
        }

        mk = vector<int>(n, 0);
        vector<int> c(n);
        int cont = 1;
        for (int i = 0; i < n; i++)
        {
            if (mk[i])
                continue;
            queue<int> q;
            q.push(i);
            mk[i] = 1;
            while (!q.empty())
            {
                int u = q.front();
                c[u] = cont;
                q.pop();

                for (auto v : g[u])
                {
                    if (!mk[v])
                    {
                        mk[v] = 1;
                        q.push(v);
                    }
                }
            }
            cont++;
        }

        cout << "!";
        for (int i = 0; i < n; i++)
            cout << " " << c[i];
        cout << '\n';
        cout.flush();
    }

    return 0;
}