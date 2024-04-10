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
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(6e5+5)

template <typename T>
struct ST{
    vector< T > st,lazy;
    int sz;
    T neutroL;

    ST (int n,T neutrol) : sz(n),st(4*n),lazy(4*n),neutroL(neutrol) {}

    T merge(T v1,T v2)
    {
        return max(v1,v2);
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
};

vector<int> pos0[MAXN];
vector<int> pos1[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pip> vp;
    set<int> s;
    map<int,int> trans;
    for(int i=0;i<n;i++)
    {
        int l,r,t;
        cin >> l >> r >> t;
        vp.push_back(pip(t,pii(l,r)));
        s.insert(l);
        s.insert(r);
    }

    int cont=0;
    for(auto y : s)
    {
        trans[y]=cont;
        cont++;
    }

    for(int i=0;i<n;i++)
    {
        vp[i].s.f=trans[vp[i].s.f];
        vp[i].s.s=trans[vp[i].s.s];
        if(vp[i].f==1)
            pos0[vp[i].s.s].push_back(vp[i].s.f);
        if(vp[i].f==2)
            pos1[vp[i].s.s].push_back(vp[i].s.f);
//        cout << vp[i].s.s << ' ' << vp[i].s.f << '\n';
    }

    int ma0=0;
    int ma1=0;
    ST<int> st0(cont+1,0);
    ST<int> st1(cont+1,0);
    for(int i=0;i<=cont;i++)
    {
        for(auto y : pos0[i])
            st0.update(0,y,1);
        for(auto y : pos0[i])
        {
            ll v=st0.query(0,y);
            if(v>ma1)
            {
                st1.update(i+1,cont,v-ma1);
                ma1=v;
            }
        }

        for(auto y : pos1[i])
            st1.update(0,y,1);
        for(auto y : pos1[i])
        {
            ll v=st1.query(0,y);
            if(v>ma0)
            {
                st0.update(i+1,cont,v-ma0);
                ma0=v;
            }
        }
//        db(i)
//        for(int i=0;i<=cont;i++)
//            cout << st0.query(i,i) << ' ';
//        cout << '\n';
//        for(int i=0;i<=cont;i++)
//            cout << st1.query(i,i) << ' ';
//        cout << '\n';
//        db("")
    }
    db(max(ma0,ma1))

    return 0;
}
/**
3
1 3 1
4 6 2
2 5 1
5
5 8 1
1 3 2
3 4 2
6 6 1
2 10 2
**/