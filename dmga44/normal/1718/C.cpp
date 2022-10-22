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
struct ST{
    vector< T > st;
    int sz;

    ST () : sz(0),st(0) {}
    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
    	return max(v1,v2);
    }

    void up(int p,T v)
    {
    	st[p]+=v;
    }

    void build(T *arr)
    {
        for(int i=0;i<sz;i++)
            st[i+sz]=arr[i];
        for(int i=sz-1;i>=1;i--)
            st[i]=merge(st[i*2],st[i*2+1]);
    }

    void update(int pos,T v)
    {
        pos+=sz;
        up(pos,v);
        pos>>=1;
        while(pos)
        {
            st[pos]=merge(st[(pos<<1)],st[(pos<<1)+1]);
            pos>>=1;
        }
    }

    T query(int l,int r)
    {
        int ma=st[l];
        l+=sz;
        r+=sz;
        while(l<=r)
        {
            ma=merge(ma,st[l]);
            ma=merge(ma,st[r]);
            l=(l>>1)+(l&1);
            r=(r>>1)-(!(r&1));
        }
        return ma;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin >> n >> q;
        vector<int> divs;
        vector<vector<ll>> sums(n);
        vector<ST<ll>> sts(n);
        for(int i=1;i<n;i++)
            if(n%i==0)
            {
                divs.push_back(i);
                sums[i]=vector<ll>(i);
                sts[i]=ST<ll>(i);
            }

        vector<ll> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            for(auto y : divs)
                sums[y][i%y]+=a[i];
        }

        ll ans=0;
        for(auto d : divs)
        {
            sts[d].build(sums[d].data());
            ans=max(ans,sts[d].st[1]*d);
        }

        cout << ans << '\n';
        for(int i=0;i<q;i++)
        {
            ll p,x;
            cin >> p >> x;
            p--;
            ll v=x-a[p];

            ll ans=0;
            for(auto d : divs)
            {
                sts[d].update(p%d,v);
                ans=max(ans,sts[d].st[1]*d);
            }
            a[p]=x;
            cout << ans << '\n';
        }
    }

    return 0;
}