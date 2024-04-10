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
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
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
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> g[MAXN],nodes;
bool mk1[MAXN],mk2[MAXN];
int sons[MAXN][2];
int ty[MAXN];
int res;
vector<pii> info;

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

void dfs2(int u,int dif,int tt,int ff)
{
    mk1[u]=1;
    ///usually you start coding over here
    nodes.push_back(u);
    info.push_back(pii(ff,dif));
    for(auto v : g[u])
        if(!mk1[v] && !mk2[v])
        {
            if((!ty[v] || ty[v]==tt) || !tt)
            {
                if(ff)
                    dfs2(v,dif,tt|ty[v],ff);
                else
                    dfs2(v,dif,tt|ty[v],tt|ty[v]);
            }
            else
                dfs2(v,dif+1,ty[v],ff);
        }
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
    int ad1=-1;
    int ad2=-1;
    if(ty[cent])
        ad1=ad2=0;
    for(auto v : g[cent])
    {
        if(mk2[v])
            continue;
        ///usually you start coding over here
        if((!ty[v] || ty[v]==ty[cent]) || !ty[cent])
            dfs2(v,0,ty[cent]|ty[v],ty[cent]|ty[v]);
        else
            dfs2(v,1,ty[v],ty[v]);

        for(auto y : info)
        {
            if(ty[cent])
            {
                res=max(res,max(ad1,ad2)+(int)y.s);
                continue;
            }
            int t=y.f;
            int v=y.s;
            if(!t)
                continue;
            if(t==1)
            {
                res=max(res,v+ad1);
                res=max(res,v+ad2+1);
            }
            else
            {
                res=max(res,v+ad1+1);
                res=max(res,v+ad2);
            }
        }
        for(auto y: info)
        {
            if(ty[cent])
                ad1=max(ad1,(int)y.s);
            else
            {
                if(!y.f)
                    continue;
                if(y.f==1)
                    ad1=max(ad1,(int)y.s);
                else
                    ad2=max(ad2,(int)y.s);
            }
        }
        for(auto y : nodes)
            mk1[y]=0;
        nodes.clear();
        info.clear();
    }

    for(auto v : g[cent])
        if(!mk2[v])
            solve(v);
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            ty[i]=0;
            g[i].clear();
            mk2[i]=0;
        }
        res=0;
        for(int i=0;i<n;i++)
            cin >> ty[i];
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        solve(0);

        res=(res+1)/2+1;
        db(res)
    }

    return 0;
}