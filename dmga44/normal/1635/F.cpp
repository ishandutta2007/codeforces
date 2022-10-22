#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t int128;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int d[MAXN];    

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

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
        st[p]=min(st[p],v);
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

    int n,q;
    cin >> n >> q;
    vector<ll> xs(n),ws(n);
    vector<pii> ts;
    for(int i=0;i<n;i++)
    {
        cin >> xs[i] >> ws[i];
        ts.push_back(pii(ws[i],i));
    }
    // db("xxxx")
    sort(allr(ts));

    for(int i=0;i<n;i++)
        d[i]=n;
    
    vector<pii> intervals;
    for(int i=0;i<n;i++)
    {
        int pos=ts[i].second;
        int l=-1,r=n;
        if(pos)
        {
            if(d[pos-1]!=n)
                l=pos+d[find(pos-1)]-1;
            else
                l=pos-1;
        }
        if(pos+1<n)
        {
            if(d[pos+1]!=n)
                r=pos-d[find(pos+1)]+1;
            else
                r=pos+1;
        }
        if(l!=-1)
            intervals.push_back(pii(l,pos));
        if(r!=n)
            intervals.push_back(pii(pos,r));

        d[pos]=-1;

        // cout << pos << ' ' << l << ' ' << r << '\n';

        if(pos && d[pos-1]!=n)
            join(pos,pos-1);
        if(pos+1<n && d[pos+1]!=n)
            join(pos,pos+1);
    }

    // for(auto y : intervals)
    //     cout << y.first << ' ' << y.second << '\n';

    vector<vector<pii>> to_met(n);
    for(auto p : intervals)
        to_met[p.second].push_back(pii(p.first,(xs[p.second]-xs[p.first])*(ws[p.second]+ws[p.first])));

    // db("xxxx")
    vector<vector<pii>> qs(n);
    vector<ll> ans(q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        qs[r].push_back(pii(l,i));
    }

    ST<ll> st(n);
    vector<ll> base(n,6e18);
    st.build(base);
    for(int i=0;i<n;i++)
    {
        for(auto upd : to_met[i])
            st.update(upd.first,upd.second);
        for(auto q : qs[i])
            ans[q.second]=st.query(q.first,i);
    }

    for(auto y : ans)
        cout << y << '\n';

    return 0;   
}