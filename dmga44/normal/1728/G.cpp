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
const ll mod = (998244353);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(1e6 + 5)

ll qp(ll b, ll e)
{
    ll ans = 1;
    while (e)
    {
        if (e & 1)
            ans = (ans * b) % mod;
        e >>= 1;
        b = (b * b) % mod;
    }
    return ans;
}

vector<pii> ac[16];

ll calc_interval(int l, int r, int i)
{
    int pl = lower_bound(all(ac[i]), pii(l, 0)) - ac[i].begin();
    int pr = lower_bound(all(ac[i]), pii(r, 1e9)) - ac[i].begin();
    pl--;
    pr--;
    return (ac[i][pr].second * qp(ac[i][pl].second, mod - 2)) % mod;
}

ll aux(int i, int j, int ip, int jp)
{
    int mid = (ip + jp) >> 1;
    return (calc_interval(ip, mid, i) * calc_interval(mid + 1, jp, j)) % mod;
}

ll raw_calc(int mask, vector<ll> &p)
{
    int m = p.size();
    int last = -1;
    ll ans = 1;
    for (int i = 0; i < m; i++)
    {
        if (!(mask & (1 << i)))
        {
            if (last == -1)
            {
                ans = (ans * calc_interval(0, p[i], i)) % mod;
            }
            else
            {
                ans = (ans * aux(last, i, p[last], p[i])) % mod;
            }
            last = i;
        }
    }
    ans = (ans * calc_interval(p[last], 1e6, last)) % mod;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll d, n, m;
    cin >> d >> n >> m;
    vector<ll> a(n), p(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> p[i];

    sort(all(a));
    sort(all(p));

    for (int i = 0; i < m; i++)
    {
        ac[i].push_back(pii(-1, 1));
        for (int j = 0; j < n; j++)
            ac[i].push_back(pii(a[j], (ac[i].back().second * abs(a[j] - p[i])) % mod));
    }

    vector<ll> base(1 << m);
    for (int i = 0; i < (1 << m); i++)
    {
        // mask tapados
        if (i + 1 < (1 << m))
            base[i] = raw_calc(i, p);
        else
            base[i] = qp(d + 1, n);
        if(i)
            for (int j = (i - 1) & i; 1; j = (j - 1) & i)
            {
                base[i] = (base[i] - base[j] + mod) % mod;
                if (!j)
                    break;
            }
        // cout << i << ' ' << base[i] << '\n';
    }

    vector<vector<ll>> extr(m, vector<ll>(m));
    vector<ll> single(m);
    ll tot = base[(1 << m) - 1];
    for (int i = 0; i < m; i++)
        single[i] = base[(1 << m) - 1 - (1 << i)];
    for(int i=0;i<(1<<m)-1;i++)
    {
        int cpy=(1<<m)-1-i;
        if((cpy&-cpy)==cpy)
            continue;
        int l=0;
        while(i&(1<<l))
            l++;
        int r=m-1;
        while(i&(1<<r))
            r--;
        extr[l][r]=(extr[l][r]+base[i])%mod;
    }

    // cout << tot << '\n';
    // for(int i=0;i<m;i++)
    //     cout << single[i] << ' ';
    // cout << '\n';
    // cout << '\n';
    // for(int i=0;i<m;i++)
    //     for(int j=i+1;j<m;j++)
    //         cout << i << ' ' << j << ' ' << extr[i][j] << '\n';

    int q;
    cin >> q;
    while(q--)
    {
        ll x;
        cin >> x;
        ll ans=0;
        ans=(ans+tot*(d+1))%mod;
        for(int i=0;i<m;i++)
        {
            ans=(ans+single[i]*(d+1-abs(p[i]-x)))%mod;
            for(int j=i+1;j<m;j++)
            {
                ans=(ans+extr[i][j]*(d+1-max(abs(p[i]-x),abs(p[j]-x))))%mod;
            }
        }
        cout << ans << '\n';
    } 

    return 0;
}