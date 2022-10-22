#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

pii lims[MAXN];
int d[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

bool join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return 0;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    lims[u].f=min(lims[v].f,lims[u].f);
    lims[u].s=max(lims[v].s,lims[u].s);
    return 1;
}

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
        return __gcd(v1,v2);
    }

    void up(int p,T v)
    {
        st[p]=v;
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

ll solve(vector<int>& a,ll pp)
{
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        d[i]=-1;
        lims[i]=pii(i,i);
    }
    vector<pii> ts;
    for(int i=0;i<n;i++)
        ts.push_back(pii(a[i],i));
    sort(all(ts));
    ST<int> st(n);
    st.build(a);

    ll comps=n;
    ll ans=0;
//    db("")
    for(int i=0;i<n;i++)
    {
        int p=ts[i].s;
        int v=ts[i].f;
//        db(v)
        if(v>=pp)
            continue;
//        cout <<
        int l=p;
        int r=p;
        for(int po=(1<<17);po;po>>=1)
            if(l-po>=0 && st.query(l-po,p)==v)
                l-=po;
        for(int po=(1<<17);po;po>>=1)
            if(r+po<n && st.query(p,r+po)==v)
                r+=po;
//        cout << l << ' ' << r << '\n';
        while(l<p)
        {
            int l2=lims[find(l)].s;
            if(join(p,l))
            {
                comps--;
                ans+=v;
            }
            else
                break;
            l=l2+1;
        }
        while(r>p)
        {
            int r2=lims[find(r)].f;
            if(join(p,r))
            {
                comps--;
                ans+=v;
            }
            else
                break;
            r=r2-1;
        }
    }
//    cout << ans << ' ' << comps << '\n';
//    db("xxx")
    return ans+(comps-1)*pp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,p;
        cin >> n >> p;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin >> a[i];
        db(solve(a,p))
    }

    return 0;
}