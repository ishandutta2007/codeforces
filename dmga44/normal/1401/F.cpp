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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

template <typename T>
struct ST{
    vector< T > st;
    int sz;
    int keep;

    ST (int n) : sz(n),st(4*n),keep(0) {}

    T merge(T v1,T v2)
    {
        return v1+v2;
    }

    void up(int p,T v)
    {
        st[p]=v;
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


        int sz=(r-l+1);
        int ls=p<<1;
        int rs=(p<<1)+1;
        if((keep*2)&sz)
            swap(ls,rs);
        if(pos<=mid)
            update(ls,l,mid,pos,v);
        if(pos>mid)
            update(rs,mid+1,r,pos,v);

        st[p]=merge(st[ls],st[rs]);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
        {
//            cout << p << ' ' << l << ' ' << r << ' ' << st[p] << '\n';
            return st[p];
        }
        int mid=(l+r)>>1;

        int sz=(r-l+1);
        int ls=p<<1;
        int rs=(p<<1)+1;
        if((keep*2)&sz)
            swap(ls,rs);
        if(R<=mid)
            return query(ls,l,mid,L,R);
        if(L>mid)
            return query(rs,mid+1,r,L,R);
        return merge(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k,q;
    cin >> k >> q;
    vector<ll> ini(1<<k);
    for(int i=0;i<(1<<k);i++)
        cin >> ini[i];
    ST<ll> st((1<<k));
    st.build(ini);

    int kk=k;
    while(q--)
    {
//        db(q)
        int x,l,r;
        int ty;
        cin >> ty;
        if(ty==1)
        {
            cin >> x >> k;
            x--;
            st.update(x,k);
        }
        if(ty==2)
        {
            cin >> k;
            st.keep^=((1<<k)-1);
        }
        if(ty==3)
        {
            cin >> k;
            st.keep^=(1<<k);
        }
        if(ty==4)
        {
            cin >> l >> r;
            l--,r--;
            db(st.query(l,r))
        }
//        db("")
//        for(int i=0;i<(1<<kk);i++)
//            cout << st.query(i,i) << ' ';
//        cout << '\n';
    }

    return 0;
}
/**
2 3
7 4 9 9
1 2 8
3 1
4 2 4
**/