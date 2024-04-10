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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9+5)
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

vector<pii> ps[MAXN];
ll x_sz[MAXN],xx[MAXN];
ll y_sz[MAXN],yy[MAXN];
map<int,int> mpx;
map<int,int> mpy;
set<pii> cs[MAXN];
vector<pii> xord[MAXN];

struct info
{
    ll base_sum,sum;
    ll mi,ma,lazy;
    info() : mi(0),ma(0),lazy(0),sum(0),base_sum(0) {}
};

//template <typename T>
struct ST{
    using T=info;
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
        info res;
        res.sum=(v1.sum+v2.sum)%mod;
        res.base_sum=(v1.base_sum+v2.base_sum)%mod;
        res.mi=min(v1.mi,v2.mi);
        res.ma=max(v1.ma,v2.ma);
        res.lazy=-1;
        return res;
    }

    void up(int p,int l,int r,ll v)
    {
        st[p].sum=(st[p].base_sum*v)%mod;
        st[p].mi=st[p].ma=v;
        st[p].lazy=v;
    }

    void push(int p,int l,int r)
    {
        if(l==r)
        {
            st[p].lazy=-1;
            return ;
        }
        if(st[p].lazy==-1)
            return ;
        ///(basic) up to code
        ll v=st[p].lazy;
        up((p<<1),l,(l+r)>>1,v);
        up((p<<1)+1,((l+r)>>1)+1,r,v);
        st[p].lazy=-1;
    }

    void build(ll *arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,ll *arr)
    {
        if(l==r)
        {
            st[p].base_sum=arr[l];
            st[p].lazy=-1;
            st[p].sum=(oo*arr[l])%mod;
            st[p].mi=st[p].ma=oo;
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    void update(int L,int R,ll v) { update(1,0,sz-1,L,R,v); }

    void update(int p,int l,int r,int L,int R,ll v)
    {
        push(p,l,r);
        if(L<=l && r<=R)
        {
            if(st[p].ma<=v)
                return ;
            if(st[p].mi>=v)
            {
                up(p,l,r,v);
                return ;
            }
            if(l==r)
                return ;

            int mid=(l+r)>>1;

            if(L<=mid)
                update(p<<1,l,mid,L,R,v);
            if(R>mid)
                update((p<<1)+1,mid+1,r,L,R,v);

            st[p]=merge(st[p<<1],st[(p<<1)+1]);
            return ;
        }

        int mid=(l+r)>>1;

        if(L<=mid)
            update(p<<1,l,mid,L,R,v);
        if(R>mid)
            update((p<<1)+1,mid+1,r,L,R,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    void debug(int p,int l,int r)
    {
        db("")
        cout << p << ' ' << l << ' ' << r << '\n';
        cout << st[p].base_sum << ' ' << st[p].sum << '\n';
        cout << st[p].mi << ' ' << st[p].ma << '\n';
        cout << st[p].lazy << '\n';
        if(l==r)
            return ;
        push(p,l,r);

        int mid=(l+r)>>1;

        debug(p<<1,l,mid);
        debug((p<<1)+1,mid+1,r);
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k,l;
    cin >> n >> k >> l;
    set<int> xs,ys;
    xs.insert(l);
    ys.insert(l);
    for(int i=0;i<n;i++)
    {
        int x,y,c;
        cin >> x >> y >> c;
        c--;
        ps[c].push_back(pii(x,y));
        xs.insert(x);
        ys.insert(y);
    }

    int cont=0;
    int last=-1;
    for(auto y : xs)
    {
        x_sz[cont]=y-last;
        last=y;
        mpx[y]=cont;
        xx[cont]=y;
        cont++;
    }
    int cx=cont-1;

    cont=0;
    last=-1;
    for(auto y : ys)
    {
        y_sz[cont]=y-last;
        last=y;
        mpy[y]=cont;
        yy[cont]=y;
        cont++;
    }
    int cy=cont;

    for(int i=0;i<k;i++)
        for(auto p : ps[i])
            xord[mpx[p.f]].push_back(pii(mpy[p.s],i));

    ll res=0;
    for(int i=0;i<cx;i++)
    {
        for(int j=0;j<k;j++)
        {
            cs[j].clear();
            cs[j].insert(pii(mpy[l],i));
        }
        for(int j=i;j<cx;j++)
            for(auto in : xord[j])
                cs[in.s].insert(pii(in.f,j));

        ST st(cy);
        st.build(y_sz);
        for(int j=0;j<k;j++)
        {
            for(auto p : cs[j])
            {
                int lp=0;
                int rp=p.f;
                auto it=cs[j].find(p);
                if(it!=cs[j].begin())
                {
                    it--;
                    lp=(*it).f+1;
                }
                if(lp<=rp)
                    st.update(lp,rp,l-yy[rp]);
            }
        }

//        db("")
//        cout << "xxx " << i << '\n';
//        st.debug(1,0,cy-1);

        for(int j=cx-1;j>=i;j--)
        {
//            db("")
//            cout << "ini " << j << '\n';
            ll m1=(x_sz[i]*x_sz[j+1])%mod;
            ll m2=st.st[1].sum;
//            cout << j << ' ' << m1*m2 << '\n';
            res=(res+m1*m2)%mod;

            if(j!=i)
                for(auto p : xord[j])
                {
                    int c=p.s;
                    pii yx=pii(p.f,j);
//                    cout << j << ' ' << p.f << ' ' << c << '\n';
                    auto it=cs[c].find(yx);
                    int lp=0;
                    int rp=p.f;
                    if(it!=cs[c].begin())
                    {
                        it--;
                        lp=(*it).f+1;
                        it++;
                    }
                    it++;
//                    cout << (*it).f << ' ' << (*it).s << '\n';
                    ll v=l-yy[(*it).f];
//                    cout << lp << ' ' << rp << ' ' << v << '\n';
//                    db("bla")
                    if(lp<=rp)
                    {
                        st.update(lp,rp,v);
                    }
                    cs[c].erase(yx);
                }
        }
    }
    db(res)

    return 0;
}
/**
4 2 4
3 2 2
3 1 1
1 1 1
1 2 1

5 3 10
6 5 3
5 3 1
7 9 1
2 3 2
5 0 2

10 4 10
5 4 4
0 0 3
6 0 1
3 9 2
8 7 1
8 1 3
2 1 3
6 3 2
3 5 3
4 3 4
**/