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

// template <typename T>
struct ST
{
    using T = pii;
    vector<T> st, lazy;
    int sz;
    T neutroL;

    ST(int n, T neutrol) : sz(n), st(4 * n), lazy(4 * n), neutroL(neutrol) {}

    T merge(T v1, T v2)
    {
        return pii(v1.first + v2.first, 0);
    }

    void up(int p, int l, int r, T v)
    {
        if (v.first != -1)
        {
            st[p].first = v.first * (r - l + 1);
            lazy[p].first = v.first;
            lazy[p].second = 0;
            v.first = -1;
        }
        st[p].first += v.second * (r - l + 1);
        lazy[p].second += v.second;
    }

    void push(int p, int l, int r)
    {
        if (l == r)
        {
            lazy[p] = neutroL;
            return;
        }
        if (lazy[p] == neutroL)
            return;
        ///(basic) up to code
        T v = lazy[p];
        up((p << 1), l, (l + r) >> 1, v);
        up((p << 1) + 1, ((l + r) >> 1) + 1, r, v);
        lazy[p] = neutroL;
    }

    void build(vector<T> &arr) { build(1, 0, sz - 1, arr); }

    void build(int p, int l, int r, vector<T> &arr)
    {
        if (l == r)
        {
            st[p] = arr[l];
            lazy[p] = neutroL;
            return;
        }
        int mid = (l + r) >> 1;

        build(p << 1, l, mid, arr);
        build((p << 1) + 1, mid + 1, r, arr);

        st[p] = merge(st[p << 1], st[(p << 1) + 1]);
        lazy[p] = neutroL;
    }

    void build(T *arr) { build(1, 0, sz - 1, arr); }

    void build(int p, int l, int r, T *arr)
    {
        if (l == r)
        {
            st[p] = arr[l];
            lazy[p] = neutroL;
            return;
        }
        int mid = (l + r) >> 1;

        build(p << 1, l, mid, arr);
        build((p << 1) + 1, mid + 1, r, arr);

        st[p] = merge(st[p << 1], st[(p << 1) + 1]);
        lazy[p] = neutroL;
    }

    void update(int L, int R, T v) { update(1, 0, sz - 1, L, R, v); }

    void update(int p, int l, int r, int L, int R, T v)
    {
        if (L <= l && r <= R)
        {
            up(p, l, r, v);
            return;
        }
        push(p, l, r);

        int mid = (l + r) >> 1;

        if (L <= mid)
            update(p << 1, l, mid, L, R, v);
        if (R > mid)
            update((p << 1) + 1, mid + 1, r, L, R, v);

        st[p] = merge(st[p << 1], st[(p << 1) + 1]);
    }

    T query(int L, int R) { return query(1, 0, sz - 1, L, R); }

    T query(int p, int l, int r, int L, int R)
    {
        if (L <= l && r <= R)
            return st[p];
        push(p, l, r);

        int mid = (l + r) >> 1;

        if (R <= mid)
            return query(p << 1, l, mid, L, R);
        if (L > mid)
            return query((p << 1) + 1, mid + 1, r, L, R);
        return merge(query(p << 1, l, mid, L, R), query((p << 1) + 1, mid + 1, r, L, R));
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    ll base = (n * (n + 1)) / 2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = min((int)a[i], i + 1);
        a[i] = a[i] - i - 1;
    }

    vector<ll> ac(n + 1);
    vector<ll> ac1(n + 1);
    for (int i = 0; i < n; i++)
        ac1[i + 1] = a[i];
    for (int i = 0; i < n; i++)
        ac1[i + 1] = min(ac1[i + 1], ac1[i]);
    for (int i = 0; i < n; i++)
        ac[i + 1] = ac[i] - ac1[i + 1];

    vector<vector<pii>> qs(n);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int p, x;
        cin >> p >> x;
        x = min(x, p);
        x -= p;
        p--;
        qs[p].push_back(pii(x, i));
    }

    ST st(n, pii(-1, 0));

    vector<ll> ans(q);
    for (int i = n - 1; i >= 0; i--)
    {
        for (auto q : qs[i])
        {
            int v = q.first;
            int id = q.second;
            v = min((ll)v, ac1[i]);
            // cout << -v << ' ' << id << ' ' << i << '\n';
            ll x = ac[i] + st.query(0, -v).first - v;
            // cout << x << '\n';
            ans[id] = base - x;
        }

        ll s = st.query(0, -a[i]).first - a[i];
        // cout << -a[i] << ' ' << i << ' ' << s << " fin\n";
        st.update(0, -a[i], pii(0, 0));
        // st.update(-a[i], -a[i], pii(-1, s));
        base -= s;
        s = st.query(0, -a[i]).first;
        // cout << -a[i] << ' ' << i << ' ' << s << " fin\n";
        if (-a[i] != n - 1)
            st.update(-a[i] + 1, n - 1, pii(-1, 1));
        // cout << st.query(0, 0).first << '\n';
        // cout << st.query(0, 1).first << '\n';
        // cout << st.query(0, 2).first << '\n';
        // cout << st.query(0, 3).first << '\n';
        // cout << "\n";
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';

    return 0;
}