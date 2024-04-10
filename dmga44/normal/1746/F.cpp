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
#define MAXN (ll)(3e5 + 5)

int abi[60][MAXN];

void update(int p, int v, int b)
{
    while (p < MAXN)
    {
        abi[b][p] += v;
        p += (p & -p);
    }
}

int query(int p, int b)
{
    int ans = 0;
    while (p)
    {
        ans += abi[b][p];
        p -= (p & -p);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mt19937 rng(time(0));
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> vals;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        vals.push_back(a[i]);
    }

    vector<ppp> qs;
    for (int i = 0; i < q; i++)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int p, x;
            cin >> p >> x;
            p--;
            vals.push_back(x);
            qs.push_back(ppp(pii(1, p), pii(x, -1)));
        }
        else
        {
            int l, r, k;
            cin >> l >> r >> k;
            l--, r--;
            qs.push_back(ppp(pii(2, k), pii(l, r)));
        }
    }

    sort(all(vals));
    vals.resize(unique(all(vals)) - vals.begin());

    map<int, ll> bm;
    for (int i = 0; i < vals.size(); i++)
    {
        ll v1 = rng();
        ll v2 = rng();
        ll v3 = rng();
        ll v4 = rng();
        ll m1 = ((abs(v1) << 16) + abs(v2)) % (1 << 30);
        ll m2 = ((abs(v3) << 16) + abs(v4)) % (1 << 30);
        bm[vals[i]] = ((m1 << 30) | m1);
    }

    for (int i = 0; i < n; i++)
    {
        ll mask = bm[a[i]];
        for (int j = 0; j < 60; j++)
            if (mask & (1ll << j))
                update(i + 1, +1, j);
    }

    for (int i = 0; i < q; i++)
    {
        int ty = qs[i].first.first;
        if (ty == 1)
        {
            int p = qs[i].first.second;
            int x = qs[i].second.first;

            ll mask = bm[a[p]];
            for (int j = 0; j < 60; j++)
                if (mask & (1ll << j))
                    update(p + 1, -1, j);

            a[p] = x;

            mask = bm[a[p]];
            for (int j = 0; j < 60; j++)
                if (mask & (1ll << j))
                    update(p + 1, +1, j);
        }
        else
        {
            int k = qs[i].first.second;
            int l = qs[i].second.first;
            int r = qs[i].second.second;

            bool ok = 1;
            for (int j = 0; j < 60; j++)
                ok = ok & ((query(r + 1, j) - query(l, j)) % k == 0);
            if (ok)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}