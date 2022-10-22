#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

ll lims[MAXN][2];
ll tar[MAXN][2];

struct info{
    int act;
    int sz;
    pii mi;
    info() : act(0),sz(1),mi(pii(0,0)) {}
    info(ll v,ll p) : act(0),sz(1),mi(pii(v,p)) {}
    void show()
    {
//        cout << act << ' ' << sz << ' ' << mi.f << ' ' << mi.s << '\n';
    }
};

template <typename T>
struct ST{
    vector< T > st,lazy;
    int sz;
    T neutroL;

    ST (int n,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        info res=v1;
        res.sz+=v2.sz;
        res.act+=v2.act;
        pii ok=v1.mi;
        if(v1.sz==v1.act)
        {
            ok=v2.mi;
            if(v2.sz==v2.act)
                ok=pii(oo,oo);
        }
        else
        {
            if(v2.sz!=v2.act)
                ok=min(ok,v2.mi);
        }
        res.mi=ok;
//        v1.show();
//        v2.show();
//        res.show();
//        db("")
        return res;
    }

    void up(int p,int l,int r)
    {
        st[p].act++;
    }

    void up2(int p,int l,int r,ll v)
    {
        st[p].mi.f=min(st[p].mi.f,v);
        lazy[p].mi.f=min(lazy[p].mi.f,v);
    }

    void push(int p,int l,int r)
    {
        if(l==r)
        {
            lazy[p]=neutroL;
            return ;
        }
        if(lazy[p].mi.f==neutroL.mi.f)
            return ;
        ///(basic) up to code
        ll v=lazy[p].mi.f;
        up2((p<<1),l,(l+r)>>1,v);
        up2((p<<1)+1,((l+r)>>1)+1,r,v);
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

    void update(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
        {
            up(p,l,r);
//            cout << l << ' ' << r << '\n';
//            cout << st[p].act << ' ' << st[p].sz << '\n';
            return ;
        }
        push(p,l,r);

        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    void update2(int p,int l,int r,int L,int R,ll v)
    {
        if(L<=l && r<=R)
        {
            up2(p,l,r,v);
            return ;
        }
        push(p,l,r);

        int mid=(l+r)>>1;

        if(L<=mid)
            update2(p<<1,l,mid,L,R,v);
        if(R>mid)
            update2((p<<1)+1,mid+1,r,L,R,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }
};

template <typename T>
struct STt{
    STt (int n) : sz(n),st(4*n),lazy(4*n) {}

    vector< T > st,lazy;
    int sz;

    T merge(T v1,T v2)
    {
        set<int> res;
        for(auto y : v1)
            res.insert(y);
        for(auto y : v2)
            res.insert(y);
        return res;
    }

    void up(int p,int l,int r,int v)
    {
        st[p].insert(v);
    }

    void up2(int p,int l,int r,int v)
    {
        st[p].erase(v);
    }

    void update(int L,int R,int v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,int v)
    {
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
    }

    void update2(int p,int l,int r,int L,int R,int v)
    {
        if(L<=l && r<=R)
        {
            up2(p,l,r,v);
            return ;
        }

        int mid=(l+r)>>1;

        if(L<=mid)
            update2(p<<1,l,mid,L,R,v);
        if(R>mid)
            update2((p<<1)+1,mid+1,r,L,R,v);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    vector<pii> qq(int u)
    {
        set<int> r1=query(1,0,sz-1,u,u);
        for(auto y : r1)
            update2(1,0,sz-1,lims[y][0],lims[y][1],y);
        vector<pii> res;
        for(auto y : r1)
            res.push_back(pii(tar[y][0],tar[y][1]));
        return res;
    }

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
            return st[p];

        int mid=(l+r)>>1;

        if(R<=mid)
            return merge(query(p<<1,l,mid,L,R),st[p]);
        if(L>mid)
            return merge(query((p<<1)+1,mid+1,r,L,R),st[p]);
    }
};

vector<pii> g[MAXN];
vector<pip> g2[MAXN];
info aa[MAXN];
ll res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q,s;
    cin >> n >> q >> s;
    s--;
    STt<set<int> > st2(n);
    for(int i=0;i<n;i++)
    {
        res[i]=oo;
        aa[i].mi=pii(oo,i);
    }
    aa[s].mi.f=0;
    ST<info> st(n,info(oo,oo));
    st.build(aa);
    for(int i=0;i<q;i++)
    {
        int ty;
        cin >> ty;
        if(ty==1)
        {
            int u,v,w;
            cin >> u >> v >> w;
            u--,v--;
            g[u].push_back(pii(w,v));
        }
        if(ty==2)
        {
            int w,l,r,v;
            cin >> v >> l >> r >> w;
            v--,l--,r--;
            g2[v].push_back(pip(w,pii(l,r)));
        }
        if(ty==3)
        {
            int w,l,r,v;
            cin >> v >> l >> r >> w;
            v--,l--,r--;
            lims[i][0]=l;
            lims[i][1]=r;
            tar[i][0]=w;
            tar[i][1]=v;
            st2.update(l,r,i);
        }
    }

    while(1)
    {
        info t=st.st[1];
        if(t.mi.f==oo || t.act==n)
            break;

        ll u=t.mi.s;
        ll w=t.mi.f;
//        db("")
//        db(cont)
//        cout << u << ' ' << w << '\n';
        res[u]=w;
        st.update(1,0,n-1,u,u);
//        db("xxx")
        for(auto y : g[u])
        {
            ll v=y.second;
            ll w1=y.f;
            st.update2(1,0,n-1,v,v,w+w1);
        }
        for(auto y : g2[u])
        {
            ll w1=y.f;
            ll l=y.s.f;
            ll r=y.s.s;
            st.update2(1,0,n-1,l,r,w+w1);
        }
        vector<pii> pl=st2.qq(u);
        for(auto y : pl)
        {
            ll v=y.second;
            ll w1=y.f;
//            cout << v << ' ' << w1 << '\n';
            st.update2(1,0,n-1,v,v,w+w1);
        }
    }

    for(int i=0;i<n;i++)
    {
        if(res[i]==oo)
            cout << "-1 ";
        else
            cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}
/**
3 5 1
2 3 2 3 17
2 3 2 2 16
2 2 2 3 3
3 3 1 1 12
1 3 3 17

4 3 1
3 4 1 3 12
2 2 3 4 10
1 2 4 16
**/