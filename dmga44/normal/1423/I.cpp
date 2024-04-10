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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

template <typename T>
struct ST{
    vector< T > st,lazy;
    int sz;
    T neutroL;

    ST (int n,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return v1|v2;
    }

    void up(int p,int l,int r,T v)
    {
        st[p]|=v;
        lazy[p]|=v;
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
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k,q;
    cin >> k >> q;
    vector<int> ini(1<<k);
    ST<int> high(1<<k,0),low(1<<k,0);
    high.build(ini);
    low.build(ini);
    vector<pip> qs;
    for(int i=0;i<q;i++)
    {
        ll l,r,v;
        cin >> l >> r >> v;
        qs.push_back(pip(v,pii(l,r)));
        ll lh=l>>k;
        ll rh=r>>k;
        high.update(lh,rh,v);
        ll pl=l&((1<<k)-1);
        ll pr=r&((1<<k)-1);
        if(lh==rh)
            low.update(pl,pr,v);
        else
        {
            if(lh+1==rh)
            {
                low.update(pl,(1<<k)-1,v);
                low.update(0,pr,v);
            }
            else
                low.update(0,(1<<k)-1,v);
        }
    }

    bool ok=1;
    for(int i=0;i<q;i++)
    {
        ll v=qs[i].f;
        ll l=qs[i].s.f;
        ll r=qs[i].s.s;

        ll lh=l>>k;
        ll rh=r>>k;
        ll pl=l&((1<<k)-1);
        ll pr=r&((1<<k)-1);
        if(lh==rh)
            ok=(ok&(((high.query(lh,lh))&(low.query(pl,pr)))==v));
        else
        {
            ok=(ok&(((high.query(lh,lh))&(low.query(pl,(1<<k)-1)))==v));
            ok=(ok&(((high.query(rh,rh))&(low.query(0,pr)))==v));
            if(lh+1<rh)
                ok=(ok&(((high.query(lh+1,rh-1))&(low.query(0,(1<<k)-1)))==v));
        }
    }

    if(!ok)
        db("impossible")
    else
    {
        db("possible")
        for(int i=0;i<(1<<k);i++)
            cout << low.query(i,i) << '\n';
        for(int i=0;i<(1<<k);i++)
            cout << high.query(i,i) << '\n';
    }

    return 0;
}