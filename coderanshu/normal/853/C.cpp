// RED

#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 200005;

template<typename T=long long>
struct fenwick {
    T a[N],bit[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            a[i] = T(0),bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;j+=j&-j)
                bit[j] += a[i];
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        if(r>n)
            r = n;
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
};

fenwick<ll> fenw;
// call fenw.build(n);

ll ans[N];
int val[N];

struct node
{
    int l,r,d,u;
    int id;
};

int _runtimeTerror_()
{
    int n;
    cin>>n;
    fenw.build(n);
    int Q;
    cin>>Q;
    for(int i=1;i<=n;++i)
        cin>>val[i];

    vector<node> q(Q);

    for(int i=0;i<Q;++i)
    {
        q[i].id = i;
        cin>>q[i].l>>q[i].d>>q[i].r>>q[i].u;
        ans[i] = n*1LL*(n-1)/2;
        ans[i] -= (q[i].l-1)*1LL*(q[i].l-2)/2;
        ans[i] -= (n-q[i].r)*1LL*(n-q[i].r-1)/2;
        ans[i] -= (q[i].d-1)*1LL*(q[i].d-2)/2;
        ans[i] -= (n-q[i].u)*1LL*(n-q[i].u-1)/2;
        // cout<<ans[i]<<"\n";
    }
    sort(all(q),[&](node a,node b)
    {
        return a.l<b.l;
    });
    int cur = 1;
    for(int i=0;i<Q;++i)
    {
        while(cur <=n && cur<q[i].l)
            fenw.update(val[cur],1),++cur;
        ll x = fenw.query(q[i].u+1,n);
        ans[q[i].id] += x*(x-1)/2;
        x = fenw.query(1,q[i].d-1);
        ans[q[i].id] += x*(x-1)/2;
    }
    fenw = fenwick<ll>();
    fenw.build(n);
    sort(all(q),[&](node a,node b)
    {
        return a.r>b.r;
    });
    cur = n;
    for(int i=0;i<Q;++i)
    {
        while(cur>=1 && cur>q[i].r)
            fenw.update(val[cur],1),--cur;
        ll x = fenw.query(q[i].u+1,n);
        ans[q[i].id] += x*(x-1)/2;
        x = fenw.query(1,q[i].d-1);
        ans[q[i].id] += x*(x-1)/2;
    }
    for(int i=0;i<Q;++i)
        cout<<ans[i]<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}