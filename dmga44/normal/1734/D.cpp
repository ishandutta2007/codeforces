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

template <typename T>
struct RMQ
{
    vector<vector<T>> rmq;
    vector<int> lg;
    int n;
    bool t;
    RMQ(vector<T> &v, bool t) : n(v.size()), t(t)
    {
        lg.push_back(-1);
        for (int i = 1; i <= n + 5; i++)
            lg.push_back(lg.back() + !(i & (i - 1)));

        for (int i = 0; i <= n; i++)
            rmq.push_back(vector<T>(lg[n] + 1));
        for (int i = 0; i < n; i++)
            rmq[i][0] = v[i];
        for (int j = 1; j <= lg[n]; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                if (!t)
                    rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
                else
                    rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
            }
    }

    T query(int l, int r)
    {
        if (l > r)
            swap(l, r);
        int po = lg[r - l + 1];
        if (!t)
            return min(rmq[l][po], rmq[r - (1 << po) + 1][po]);
        return max(rmq[l][po], rmq[r - (1 << po) + 1][po]);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i < k; i++)
            a[i - 1] = a[i];
        for (int i = n; i > k; i--)
            a[i + 1] = a[i];
        a[k - 1] = a[k + 1] = 0;
        for (int i = k - 1; i >= 1; i--)
            a[i - 1] += a[i];
        for (int i = k + 1; i <= n; i++)
            a[i + 1] += a[i];
        vector<pii> d, u;
        d.push_back(pii(0, k - 1));
        u.push_back(pii(0, k + 1));
        for (int i = k - 2; i >= 0; i--)
            if (d.back().first < a[i])
                d.push_back(pii(a[i], i));
        for (int i = k + 2; i <= n + 1; i++)
            if (u.back().first < a[i])
                u.push_back(pii(a[i], i));
        RMQ<ll> rmq(a, 0);
        auto query = [&](int l, int r, int t)
        {
            if (l == r + 1)
                return 0ll;
            ll x = rmq.query(l + 1, r - 1);
            if (t)
                return a[l] - x;
            return a[r] - x;
        };
        queue<pip> q;
        q.push(pip(0, pii(k - 1, k + 1)));
        q.push(pip(1, pii(k - 1, k + 1)));
        bool ok = 0;
        while (!q.empty() && !ok)
        {
            auto act = q.front();
            q.pop();

            int ty = act.first;
            int l = act.second.first;
            int r = act.second.second;
            ll h = a[k] + a[l] + a[r];
            if (l == 0 || r == n + 1)
            {
                ok = 1;
                break;
            }
            if (query(-1, l, 0) <= h || query(r, n + 2, 1) <= h)
            {
                ok = 1;
                break;
            }
            if (ty == 0) //<-
            {
                int lini = l;
                while (1)
                {
                    int p = lower_bound(all(d), pii(a[l], l)) - d.begin();
                    p++;
                    if (p < d.size() && query(d[p].second, l, 0) <= h)
                    {
                        l = d[p].second;
                        h = a[k] + a[l] + a[r];
                    }
                    else
                        break;
                }
                if (lini != l)
                    q.push(pip(1, pii(l, r)));
            }
            else //->
            {
                int rini = r;
                while (1)
                {
                    int p = lower_bound(all(u), pii(a[r], r)) - u.begin();
                    p++;
                    if (p < u.size() && query(r, u[p].second, 1) <= h)
                    {
                        r = u[p].second;
                        h = a[k] + a[l] + a[r];
                    }
                    else
                        break;
                }
                if (rini != r)
                    q.push(pip(0, pii(l, r)));
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}