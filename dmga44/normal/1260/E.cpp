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
typedef unsigned long long ull;
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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
        return min(v1,v2);
    }

    void up(int p,T v)
    {
        st[p]=pii(st[p].f+v.f,st[p].s);
    }

    void build(T *arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,T *arr)
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

    void update(int pos,T v) { update(1,0,sz-1,pos,v); }

    void update(int p,int l,int r,int pos,T v)
    {
        if(pos<=l && r<=pos)
        {
            up(p,v);
            return ;
        }
        int mid=(l+r)>>1;

        if(pos<=mid)
            update(p<<1,l,mid,pos,v);
        if(pos>mid)
            update((p<<1)+1,mid+1,r,pos,v);

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> a(n);
    int p=-1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x==-1)
        {
            p=i+1;
            x=1e9;
        }
        a[i]=pii(x,i);
    }

    ST<pii> st(n);
    st.build(a);

    int act=n;
    ll res=0;
    while(act>p)
    {
        pii r=a[act-1];
        if(act!=n)
            r=min(r,st.query(act,n-1));
        res+=r.f;
        st.update(r.s,pii(1e9,0));
        act/=2;
    }
    db(res)

    return 0;
}