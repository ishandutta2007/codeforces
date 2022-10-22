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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int tim[MAXN];
int a[MAXN];
int base[MAXN];
vector<int> abi[MAXN];

void update(int p,int w)
{
    while(p<MAXN)
    {
        abi[p].push_back(w);
        p+=(p&-p);
    }
}

int query(int p,int w)
{
    int res=0;
    while(p)
    {
        res+=abi[p].size()-(lower_bound(all(abi[p]),w)-abi[p].begin());
        p-=(p&-p);
    }
    return res;
}

template <typename T>
struct ST{
    vector< T > st,lazy;
    int sz;
    T neutroL;

    ST (int n,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return min(v1,v2);
    }

    void up(int p,int l,int r,T v)
    {
        st[p]+=v;
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
        T v=lazy[p];
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

    void update(int L,int R,T v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,T v)
    {
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

    int nexx()
    {
        return query2(1,0,sz-1);
    }

    int query2(int p,int l,int r)
    {
        push(p,l,r);
        if(l==r)
            return l;

        int mid=(l+r)>>1;

        if(!st[(p<<1)+1])
            return query2((p<<1)+1,mid+1,r);
        else
            return query2(p<<1,l,mid);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int cant=0;
    for(int i=0;i<n;i++)
    {
        base[i]=a[i]-i-1;
        if((!(base[i]<=0 && base[i]+cant>=0)) || base[i]+cant<0)
            base[i]=oo;
        else
        {
            base[i]+=cant;
            cant++;
        }
    }

    ST<int> st(n,0);
    st.build(base);

    for(int i=0;i<n;i++)
        tim[i]=-MAXN;
//
//    for(int i=0;i<n;i++)
//        cout << base[i] << ' ';
//    db("")
    for(int i=0;i<n;i++)
    {
        int v=st.query(i,i);
        if(v)
            continue;

        int p=st.nexx();
        while(p!=i)
        {
            tim[p]=i;
            st.update(p,n-1,-1);
            st.update(p,p,oo);
            p=st.nexx();
        }
        tim[p]=i;
        st.update(p,n-1,-1);
        st.update(p,p,oo);
//        db("")
//        db(i)
//        for(int j=0;j<n;j++)
//            cout << st.query(j,j) << '\n';
    }

//    for(int i=0;i<n;i++)
//    {
//        cout << i << ' ' << tim[i] << '\n';
//    }

    for(int i=0;i<n;i++)
        update(i+1,tim[i]);

    for(int i=0;i<MAXN;i++)
        sort(all(abi[i]));

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        db(query(n-r,l))
    }

    return 0;
}