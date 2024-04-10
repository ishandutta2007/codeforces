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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

vector<int> ps[MAXN];
int a[MAXN];
int n;

template <typename T>
struct ST{
    vector< T > st;
    vector<ll> lazy;
    int sz;
    ll neutroL=0;

    ST (int n) : sz(n),st(4*n),lazy(4*n) {}

    T merge(T v1,T v2)
    {
        ll mi=min(v1.f,v2.f);
        ll f=0;
        if(v1.f==mi)
            f+=v1.s;
        if(v2.f==mi)
            f+=v2.s;
        return pii(mi,f);
    }

    void up(int p,int l,int r,ll v)
    {
        st[p].f+=v;
        lazy[p]+=v;
    }

    void push(int p,int l,int r)
    {
        if(l==r)
        {
            lazy[p]=neutroL;
            return ;
        }
        if(lazy[p]==neutroL)
            return ;
        ///(basic) up to code
        ll v=lazy[p];
        up((p<<1),l,(l+r)>>1,v);
        up((p<<1)+1,((l+r)>>1)+1,r,v);
        lazy[p]=neutroL;
    }

    void build(vector<T> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<T> &arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void build(T *arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,T *arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            lazy[p]=neutroL;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
        lazy[p]=neutroL;
    }

    void update(int L,int R,ll v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,ll v)
    {
//        cout << p << ' ' << l << ' ' << r << ' ' << L << ' ' << R << '\n';
        push(p,l,r);
        if(L<=l && r<=R)
        {
            up(p,l,r,v);
            return ;
        }

        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R,v);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    T query(int p,int l,int r,int L,int R)
    {
        push(p,l,r);
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

void doo(int i,ST<pii>& st,ll f)
{
    if(ps[i].empty())
        return ;
    if(ps[i].size()<3)
    {
        st.update(ps[i].back(),n-1,oo*f);
        return ;
    }
//    db(i)
//    cout << ps[i].back() << ' ' << ps[i][ps[i].size()-3] << '\n';
//    db(n-1)
    st.update(ps[i].back(),n-1,1*f);
//    db("xxx")
    st.update(ps[i][ps[i].size()-3],n-1,-1*f);
//    db("xxx")
    if(ps[i].size()>3)
        st.update(ps[i][ps[i].size()-4],n-1,oo*f);
//    cout << ps[i][ps[i].size()-4] << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        ps[a[i]].push_back(i);
    }

    vector<pii> ini(n,pii(0,1));
    ST<pii> st(n);
    st.build(ini);
    for(int i=0;i<MAXN;i++)
    {
        reverse(all(ps[i]));
        doo(i,st,1);
    }

    ll res=0;
    for(int i=0;i<n;i++)
    {
        pii x=st.query(i,n-1);
        if(!x.f)
            res+=x.s;
        doo(a[i],st,-1);
        ps[a[i]].pop_back();
        doo(a[i],st,1);
    }
    db(res)

    return 0;
}