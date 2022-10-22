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
typedef unsigned long long ull;
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
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int p[MAXN];
vector<pii> vp[MAXN];
stack<pii> sp[MAXN];
ll inv[MAXN];
ll a[MAXN];

void criba()
{
    for(int i=2;i<MAXN;i++)
        if(!p[i])
            for(int j=i;j<MAXN;j+=i)
                p[j]=i;
}

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
        vector<pii> res;
        int p1=0;
        int p2=0;
        while(p1<v1.size() && p2<v2.size())
        {
            if(v1[p1].f<=v2[p2].f)
            {
                res.push_back(v1[p1]);
                p1++;
            }
            else
            {
                res.push_back(v2[p2]);
                p2++;
            }
        }
        while(p1<v1.size())
        {
            res.push_back(v1[p1]);
            p1++;
        }
        while(p2<v2.size())
        {
            res.push_back(v2[p2]);
            p2++;
        }

        return res;
    }

    void build(T *arr)
    {
        build(1,0,sz-1,arr);

        for(int i=0;i<4*sz;i++)
        {
            for(int j=1;j<st[i].size();j++)
                st[i][j].s=(st[i][j-1].s*st[i][j].s)%mod;
        }
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

    ll query(int L,int R) { return query(1,0,sz-1,L,R); }

    ll query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
        {
            int pos=upper_bound(all(st[p]),pii(-L,mod))-st[p].begin();
            if(pos==0)
                return 1;
            return st[p][pos-1].s;
        }
        int mid=(l+r)>>1;

        if(R<=mid)
            return query(p<<1,l,mid,L,R);
        if(L>mid)
            return query((p<<1)+1,mid+1,r,L,R);
        return (query(p<<1,l,mid,L,R)*query((p<<1)+1,mid+1,r,L,R))%mod;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<MAXN;i++)
        inv[i]=qp(i,mod-2);

    criba();

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        vp[i].push_back(pii(-i,a[i]));
        map<int,int> fs;
        int d=a[i];
        while(d!=1)
        {
            fs[p[d]]++;
            d/=p[d];
        }
//        db(i)

        for(auto y : fs)
        {
            int p=y.f;
            int e=y.s;
            ll act=0;
            while(!sp[p].empty() && sp[p].top().f<=e)
            {
                ll c=sp[p].top().f-act;
                act=sp[p].top().f;
                vp[i].push_back(pii(-sp[p].top().s,inv[qp(p,c)]));
                sp[p].pop();
            }
            if(!sp[p].empty() && act!=e)
                vp[i].push_back(pii(-sp[p].top().s,inv[qp(p,e-act)]));

            sp[p].push(pii(e,i));
        }

        sort(all(vp[i]));

//        db("")
//        db(i)
//        for(auto y : vp[i])
//        {
//            cout << y.f << ' ' << y.s << '\n';
//        }
    }

//    db("xxx")
    ST<vector<pii> > st(n);
    st.build(vp);

    int q;
    cin >> q;
    ll last=0;
    while(q--)
    {
        ll l,r;
        cin >> l >> r;
        l=(l+last)%n;
        r=(r+last)%n;
        if(l>r)
            swap(l,r);
//        cout << l << ' ' << r << '\n';
        ll res=st.query(l,r);
        db(res)
        last=res;
    }

    return 0;
}
/**
3
2 3 5
4
1 3
3 3
2 3
2 3

5
1 2 4 8 16
3
1 3
1 3
2 4
**/