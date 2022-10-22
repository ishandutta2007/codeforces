#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (int)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

struct info{
    ll mul,sum;
    info(ll _mul=0,ll _sum=0) : mul(_mul),sum(_sum) {}
};

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
        info res;
        res.mul=(v1.mul*v2.mul)%mod;
        res.sum=(v1.sum*v2.mul+v2.sum)%mod;
        return res;
    }

    void build(vector<T> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<T> &arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
            return st[p];

        int mid=(l+r)>>1;

        if(R<=mid)
            return query(p<<1,l,mid,L,R);
        if(L>mid)
            return query((p<<1)+1,mid+1,r,L,R);
        return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    vector<info> v(n);
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        ll val=(100ll*qp(x,mod-2))%mod;
        v[i].mul=val;
        v[i].sum=val;
    }

    ST<info> st(n);
    st.build(v);

    set<int> cs;
    cs.insert(0);
    cs.insert(n);
    ll sum=st.query(0,n-1).sum;
    for(int i=0;i<q;i++)
    {
        int p;
        cin >> p;
        p--;
        if(cs.find(p)==cs.end())
        {
            cs.insert(p);
            auto it=cs.find(p);
            it--;
            int l=(*it);
            it++;
            it++;
            int r=(*it);
            ll v1=st.query(l,r-1).sum;
            ll v2=st.query(l,p-1).sum;
            ll v3=st.query(p,r-1).sum;
            sum=(sum-v1+v2+v3+mod)%mod;
        }
        else
        {
            auto it=cs.find(p);
            it--;
            int l=(*it);
            it++;
            it++;
            int r=(*it);
            ll v1=st.query(l,r-1).sum;
            ll v2=st.query(l,p-1).sum;
            ll v3=st.query(p,r-1).sum;
            sum=(sum+v1-v2-v3+mod+mod)%mod;
            cs.erase(p);
        }
        db(sum)
    }

    return 0;
}