#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
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

const int N = 500005;

ll n,m,k;
vector<int> v[N];
int c[N];

bool bad[N];
map<pii,vector<pii>> ed;

 
struct dsu_node
{
    int x, rnkx, y, rnky;
    int sz;
    vector<int> Xor;
    dsu_node(){}
    dsu_node(int x_,int rnkx_,int y_,int rnky_,int sz_): x(x_),y(y_),rnkx(rnkx_),rnky(rnky_){sz = sz_;}
};
struct dsu_with_rollback
{
    vector<int> r,p;
    vector<vector<int>> elements;
    vector<int> XorToRoot;
    int comps;
    stack<dsu_node> st;
 
    dsu_with_rollback(){}
 
    dsu_with_rollback(int n) : comps(n)
    {
        r.resize(n+2);p.resize(n+2);
        XorToRoot.resize(n+1);
        elements.resize(n+1);
        for(int i=0;i<=n;++i)
            p[i]=i,r[i]=0,XorToRoot[i] = 0,elements[i].pb(i);
    }
    inline int parent(int i)
    {
       return (i==p[i])?i:parent(p[i]);
    }
    void merge(int x,int y,int w)
    {
        int lx = x,ly = y;
        x=parent(x),y=parent(y);
        int yy = sz(elements[x]) + sz(elements[y]);
        if(sz(elements[x])>sz(elements[y]))
            swap(x,y),swap(lx,ly);
        st.push(dsu_node(x,r[x],y,r[y],sz(elements[y])));
        p[x] = y;
        bool f = true;
        for(int &j:elements[x])
        {
            st.top().Xor.pb(XorToRoot[j]);
            if(j==lx)
            {
                f = false;
                elements[y].pb(lx);
                continue;
            }
            int val = XorToRoot[j]^XorToRoot[lx]^w^XorToRoot[ly];
            XorToRoot[j] = val;
            elements[y].pb(j);
        }
        XorToRoot[lx] = w^XorToRoot[ly];
        elements[x].clear();
    }
    void rollback()
    {
        if(st.empty())return ;
        dsu_node val= st.top();st.pop();
        ++comps;
        p[val.x]=val.x,p[val.y]=val.y;
        while(sz(elements[val.y])>val.sz)
        {
            elements[val.x].pb(elements[val.y].back());
            elements[val.y].pop_back();
        }
        reverse(all(elements[val.x]));
        for(int i=0;i<sz(elements[val.x]);++i)
            XorToRoot[elements[val.x][i]] = val.Xor[i];
    }
};

int _runtimeTerror_()
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
        cin>>c[i];

    dsu_with_rollback dsu(n);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        if(c[x]>c[y])
            swap(x,y);
        if(c[x]==c[y])
        {
            if(dsu.parent(x) == dsu.parent(y))
            {
                int u = dsu.XorToRoot[x]^dsu.XorToRoot[y];
                if(!u)
                    bad[c[x]] = true;
            }
            else
                dsu.merge(x,y,1);
        }
        else
            ed[{c[x],c[y]}].pb({x,y});
    }
    ll cnt = 0;
    for(int i=1;i<=k;++i)
    {
        cnt += bad[i];
        // if(!bad[i])
            // cout<<i<<"\n";
    }
    cnt = k - cnt;
    ll ans = cnt*(cnt-1)/2;
    for(auto j:ed)
    {
        if(bad[j.F.F] || bad[j.F.S])
            continue;
        // cout<<j.F<<"\n";
        int cnt = 0;
        bool f = false;
        for(auto k:j.S)
        {
            // cout<<k<<" ";
            int u = k.F,v = k.S;
            if(dsu.parent(u) != dsu.parent(v))
                dsu.merge(u,v,1),++cnt;
            else
            {
                // cout<<"Here\n";
                int x = dsu.XorToRoot[u]^dsu.XorToRoot[v];
                if(!x)
                    f = true;
            }
        }
        // cout<<"\n";
        while(cnt--)
            dsu.rollback();
        if(f)
        {
            // cout<<j.F<<" false"<<"\n";
            --ans;
        }
    }
    cout<<ans<<"\n";
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