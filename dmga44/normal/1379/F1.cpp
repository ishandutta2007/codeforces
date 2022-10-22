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
//typedef pair<string,ll> psi;
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
#define MAXN (ll)(2e5+5)

template <typename T>
struct ST{
    vector< T > st;
    int sz;
    bool ty;

    ST (int n,int tyy) : sz(n),st(4*n),ty(tyy) {}

    T merge(T v1,T v2)
    {
        if(ty)
            return min(v1,v2);
        return max(v1,v2);
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

set<int> psi[MAXN];
set<int> psp[MAXN];
map<pii,int> mki;
map<pii,int> mkp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q;
    cin >> n >> m >> q;
    bool ok=1;
    vector<int> ini(n,1e9);
    ST<int> sti(n,1);
    sti.build(ini);
    vector<int> ini2(n,-1);
    ST<int> stp(n,0);
    stp.build(ini2);
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin >> x >> y;
        y=(y-1)/2;
        if(x&1)
        {
            x=(x-1)/2;
//            cout << x << ' ' << y << '\n';
//            db(sti.sz)
            mki[pii(x,y)]=1-mki[pii(x,y)];
            if(mki[pii(x,y)])
                psi[x].insert(y);
            else
                psi[x].erase(y);
            y=1e9;
            if(psi[x].size())
                y=*(psi[x].begin());
            sti.update(x,y);
//            for(int i=0;i<n;i++)
//                cout << sti.query(i,i) << ' ';
//            cout << '\n';
//            cout << stp.query(x,n-1) << '\n';
            ok&=(y>stp.query(x,n-1));
        }
        else
        {
            x=(x-1)/2;
//            cout << x << ' ' << y << '\n';
//            db(stp.sz)
            mkp[pii(x,y)]=1-mkp[pii(x,y)];
            if(mkp[pii(x,y)])
                psp[x].insert(-y);
            else
                psp[x].erase(-y);
            y=-1;
            if(psp[x].size())
                y=-(*(psp[x].begin()));
            stp.update(x,y);
//            for(int i=0;i<n;i++)
//                cout << stp.query(i,i) << ' ';
//            cout << '\n';
//            cout << sti.query(0,x) << '\n';
            ok&=(y<sti.query(0,x));
        }
        if(ok)
            db("YES")
        else
            db("NO")
//        db("")
    }

    return 0;
}
/**
1 3 3
1 1
1 5
2 4

3 2 7
4 2
6 4
1 3
2 2
2 4
4 4
3 1
**/