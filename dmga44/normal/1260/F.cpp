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
#define MAXN (ll)(1e5+5)

template <typename T>
struct ABI{
    vector<T> abi1,abi2;
    int n;

    ABI(int _n) : abi1(_n),abi2(_n),n(_n) {}
    ABI() : abi1(0),abi2(0),n(0) {}

    ll query(int l,int r)
    {
        return (query(r)-query(l-1)+mod)%mod;
    }

    ll query(ll p)
    {
        ll res=query(p,abi1)*p;
        res+=query(p,abi2);
        res%=mod;
        return res;
    }

    void update(int l,int r,ll v)
    {
        update(l,v,abi1);
        update(r+1,(mod-v)%mod,abi1);

        update(l,(mod-((v*(l-1))%mod))%mod,abi2);
        update(r+1,(v*r)%mod,abi2);
    }

    ll query(int p,vector<ll>& abi)
    {
        ll res=0;
        while(p)
        {
            res=(res+abi[p])%mod;
            p-=(p&-p);
        }
        return res;
    }

    void update(int p,ll v,vector<ll>& abi)
    {
        while(p<n)
        {
            abi[p]=(abi[p]+v)%mod;
            p+=(p&-p);
        }
    }
};

vector<int> g[MAXN],nodes;
bool mk1[MAXN],mk2[MAXN];
ll sons[MAXN][2];
ll lr[MAXN][2];
ll mul;
ll inv[MAXN];
ll res;
ll add;
ABI<ll> sp,cf;
vector<pii> info;

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

void dfs1(int u)
{
    mk1[u]=1;
    sons[u][0]=1;
    nodes.push_back(u);
    for(auto v : g[u])
        if(!mk1[v] && !mk2[v])
        {
            dfs1(v);
            sons[u][0]+=sons[v][0];
            sons[u][1]=max(sons[v][0],sons[u][1]);
        }
}

void dfs2(int u,int d)
{
    mk1[u]=1;
    ///usually you start coding over here
    nodes.push_back(u);
    info.push_back(pii(u,d));
    for(auto v : g[u])
        if(!mk1[v] && !mk2[v])
            dfs2(v,d+1);
}

void dfs3(int u,ll d,int r)
{
    if(u!=r)
    {
        ll li=max(lr[u][0],lr[r][0]);
        ll ri=min(lr[u][1],lr[r][1]);
        if(ri>=li)
        {
//            cout << u << ' ' << d << ' ' << r << '\n';
            ll f1=((ri-li+1)*mul)%mod;
            ll f2=(inv[r]*inv[u])%mod;
            f1=(f1*d)%mod;
            add=(add+f1*f2)%mod;
        }
    }
    mk1[u]=1;
    for(auto v : g[u])
        if(!mk1[v])
            dfs3(v,d+1,r);
}

void solve(int u)
{
    dfs1(u);

    int cent=-1,cant=nodes.size()/2;
    for(auto v: nodes)
    {
        if(cent==-1 && sons[v][0]>=cant && sons[v][1]<=cant)
            cent=v;
        mk1[v]=sons[v][0]=sons[v][1]=0;
    }
    nodes.clear();

    ///usually you start coding over here
    mk2[cent]=1;
    vector<pip> usf;
    vector<pip> usc;
    usf.push_back(pip(lr[cent][0],pii(lr[cent][1],(mul*inv[cent])%mod)));
    cf.update(lr[cent][0],lr[cent][1],(mul*inv[cent])%mod);
    for(auto v : g[cent])
    {
        if(mk2[v])
            continue;
        ///usually you start coding over here
        dfs2(v,1);

        for(auto y : info)
        {
            int u=y.f;
            ll d=y.s;
            ll s1=cf.query(lr[u][0],lr[u][1]);
            ll s2=sp.query(lr[u][0],lr[u][1]);
            res=(res+s2*inv[u]+((s1*d)%mod)*inv[u])%mod;
        }
        for(auto y : info)
        {
            int u=y.f;
            ll d=y.s;
            ll v1=(mul*inv[u])%mod;
            usf.push_back(pip(lr[u][0],pii(lr[u][1],v1)));
            cf.update(lr[u][0],lr[u][1],v1);
            usc.push_back(pip(lr[u][0],pii(lr[u][1],(v1*d)%mod)));
            sp.update(lr[u][0],lr[u][1],(v1*d)%mod);
        }

        for(auto y : nodes)
            mk1[y]=0;
        info.clear();
        nodes.clear();
    }

    for(auto y : usf)
        cf.update(y.f,y.s.f,mod-y.s.s);
    for(auto y : usc)
        sp.update(y.f,y.s.f,mod-y.s.s);

    for(auto v : g[cent])
        if(!mk2[v])
            solve(v);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    mul=1;
    for(int i=0;i<n;i++)
    {
        cin >> lr[i][0] >> lr[i][1];
        ll l=lr[i][0];
        ll r=lr[i][1];
        mul=(mul*(r-l+1))%mod;
        inv[i]=qp(r-l+1,mod-2);
    }
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    sp=ABI<ll> (MAXN);
    cf=ABI<ll> (MAXN);

    solve(0);

//    db(add)
    add*=500000004ll;
    add%=mod;
    res=(res+add)%mod;
    db(res)

    return 0;
}
/**
4
1 1
1 2
1 1
1 2
1 2
1 3
3 4
**/