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

struct knapsack
{
    vector<ll> dp;
    stack<vector<ll>> versions;
    int k;

    knapsack() {}
    knapsack(int _k)
    {
        k = _k;
        dp = vector<ll>(k + 1);
    }

    ll max()
    {
        return dp[k];
    }

    void add(int w, ll v)
    {
        versions.push(dp);
        for (int i = k; i >= w; i--)
            if (dp[i - w] + v > dp[i])
                dp[i] = dp[i - w] + v;
    }

    void undo()
    {
        for (int i = 0; i <= k; i++)
            dp[i] = versions.top()[i];
        versions.pop();
    }
};

template <class DS, typename T>
struct queue_like_undo
{
    DS d;
    vector<pair<bool, T>> stk;
    queue_like_undo() {}
    void push_back(T x)
    {
        stk.push_back({true, x});
        d.add(x.first, x.second);
    }

    void pop_front()
    {
        auto i = stk.end();
        for (int c = 0;;)
        {
            c += (--i)->first ? -1 : +1;
            d.undo();
            if (c >= 0 || i == stk.begin())
                break;
        }
        auto j = stable_partition(i, stk.end(), [](auto &x)
                                  { return x.first; });
        if (i == stk.begin())
            reverse(i, j), for_each(i, j, [](auto &x)
                                    { x.first = false; });
        for_each(i, prev(stk.end()), [&](auto &x)
                 { d.add(x.second.first, x.second.second); });
        stk.pop_back();
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<ll> a[n];
    for (int i = 0; i < n; i++)
    {
        int cant;
        cin >> cant;
        a[i].push_back(0);
        for (int j = 0; j < cant; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(a[i].back() + x);
        }
        while (a[i].size() > k + 1)
            a[i].pop_back();
    }

    knapsack dp(k);
    queue_like_undo<knapsack, pii> eltipo;
    eltipo.d = dp;
    for (int i = 0; i < n; i++)
        eltipo.push_back(pii(a[i].size() - 1, a[i].back()));

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        eltipo.pop_front();
        for (int j = 0; j < a[i].size(); j++)
            ans = max(a[i][j] + eltipo.d.dp[k - j], ans);
        eltipo.push_back(pii(a[i].size() - 1, a[i].back()));
    }
    cout << ans << '\n';

    return 0;
}