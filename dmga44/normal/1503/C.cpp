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

//template <typename T>
////struct ST{
//    vector< T > st;
//    ll sz;
//    T neutro;
//
//    ST (ll n,T neutro) : sz(n),st(4*n),neutro(neutro) {}
//
//    T merge(T v1,T v2)
//    {
//        return min(v1,v2);
//    }
//
//    void up(int node,T v)
//    {
//        st[node]=v;
//    }
//
//    void build(int p,int l,int r,T *arr)
//    {
//        if(l==r)
//        {
//            st[p]=arr[l];
//            return ;
//        }
//        int mid=(l+r)>>1;
//
//        build(p<<1,l,mid,arr);
//        build((p<<1)+1,mid+1,r,arr);
//
//        st[p]=merge(st[p<<1],st[(p<<1)+1]);
//    }
//
//    void update(int p,int l,int r,int L,int R,T v)
//    {
//        if(L<=l && r<=R)
//        {
//            up(p,v);
//            return ;
//        }
//        int mid=(l+r)>>1;
//
//        if(L<=mid)
//            update(p<<1,l,mid,L,R,v);
//        if(R>mid)
//            update((p<<1)+1,mid+1,r,L,R,v);
//
//        st[p]=merge(st[p<<1],st[(p<<1)+1]);
//    }
//
//    T query(int p,int l,int r,int L,int R)
//    {
//        if(L<=l && r<=R)
//            return st[p];
//        else if(L>r || l>R)
//            return neutro;
//
//        int mid=(l+r)>>1;
//
//        st[p]=merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
//    }
//};

typedef ll T;

vector< ll > st;
ll sz;
ll neutro;

T merge(T v1,T v2)
{
    return min(v1,v2);
}

void up(int node,T v)
{
    st[node]=v;
}

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

void update(int p,int l,int r,int L,int R,T v)
{
    if(L<=l && r<=R)
    {
        up(p,v);
        return ;
    }
    int mid=(l+r)>>1;

    if(L<=mid)
        update(p<<1,l,mid,L,R,v);
    if(R>mid)
        update((p<<1)+1,mid+1,r,L,R,v);

    st[p]=merge(st[p<<1],st[(p<<1)+1]);
}

T query(int p,int l,int r,int L,int R)
{
    if(L<=l && r<=R)
        return st[p];
    else if(L>r || l>R)
        return neutro;

    int mid=(l+r)>>1;

    return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> c(n);
    vector<pii> ts1;
    vector<pii> ts2;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[i]=x;
        c[i]=y;
        ts1.push_back(pii(x,i));
        ts2.push_back(pii(x+y,i));
        sum+=y;
    }

    sort(all(ts1));
    sort(allr(ts2));

    vector<int> p1(n);
    for(int i=0;i<n;i++)
        p1[ts1[i].s]=i;

    st.resize(4*n);
    neutro=oo;
    vector<ll> base(n,oo);
    build(1,0,n-1,base.data());

    update(1,0,n-1,n-1,n-1,0);

    for(int i=0;i<n;i++)
    {
        int lim=ts2[i].f;
        int pos=ts2[i].s;
        int tu=p1[pos];
        if(tu==n-1)
            continue;
//        cout << lim << ' ' << pos << ' ' << tu << '\n';
        int l1=lower_bound(all(ts1),pii(lim,1e6))-ts1.begin();
        l1--;
        ll val=oo;
//        db(l1)
        if(l1>=0)
            val=min(val,query(1,0,n-1,0,l1));
//        db(val)
        if(val>1e17)
        {
            int p2=l1+1;
            for(int po=(1<<16);po;po>>=1)
                if(p2+po-1<n && query(1,0,n-1,p2,p2+po-1)>1e17)
                    p2+=po;
//            db(p2)
            val=min(val,ts1[p2].f-lim+query(1,0,n-1,p2,p2));
        }
//        db(val)
//        db("")
        update(1,0,n-1,tu,tu,val);
    }

//    db(sum)
//    for(int i=0;i<n;i++)
//        cout << st.query(1,0,n-1,i,i) << ' ';
//    db("")

    db(query(1,0,n-1,0,0)+sum)

    return 0;
}
/**
6
4 2
8 4
3 0
2 3
7 1
0 1
**/