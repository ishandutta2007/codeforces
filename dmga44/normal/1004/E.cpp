#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

vector<pii> g[MAXN];
int fson[MAXN];
int fpar[MAXN];
bool mk[MAXN];
int n,k;
ll tar;
bool ok;

void dfs1(int u)
{
    mk[u]=1;
    for(auto p : g[u])
        if(!mk[p.f])
        {
            dfs1(p.f);
            fson[u]=max((int)p.s+fson[p.f],fson[u]);
        }
}

void dfs2(int u)
{
    mk[u]=1;
    vector<pii> ds;
    ds.push_back(pii(fpar[u],-1));
    for(auto p : g[u])
        if(!mk[p.f])
            ds.push_back({fson[p.f]+p.s,p.f});

    sort(allr(ds));

    for(auto p : g[u])
        if(!mk[p.f])
        {
            if(ds[0].s!=p.f)
                fpar[p.f]=p.s+ds[0].f;
            else
                fpar[p.f]=p.s+ds[1].f;
            dfs2(p.f);
        }
}

pii dfs(int u)
{
    mk[u]=1;
    vector<pii> kks;
    for(auto p : g[u])
        if(!mk[p.f])
        {
            pii kk=dfs(p.f);
            if(kk.f)
                kks.push_back(pii(kk.f,kk.s));
            else if(fson[p.f]+p.s>tar)
                kks.push_back(pii(1,1));
        }

    sort(allr(kks));

    if(kks.empty())
    {
        if(fpar[u]<=tar)
            ok=1;
        return pii(0,0);
    }
    else if(kks.size()==1)
    {
        if(kks[0].f==2)
            return pii(2,0);
        if(fpar[u]<=tar && kks[0].s+1<=k)
            ok=1;
        return pii(1,kks[0].s+1);
    }
    else if(kks.size()==2)
    {
        if(kks[0].f==2)
            return pii(2,0);
        if(fpar[u]<=tar && kks[1].s+kks[0].s+1<=k)
            ok=1;
        return pii(2,0);
    }
    else
        return pii(2,0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
    }

    dfs1(0);
    for(int i=0;i<n;i++)
        mk[i]=0;
    dfs2(0);
    for(int i=0;i<n;i++)
        mk[i]=0;

    tar=-1;
    for(int po=(1<<30);po;po>>=1)
    {
        tar+=po;
        dfs(0);
        if(ok)
            tar-=po;
        for(int i=0;i<n;i++)
            mk[i]=0;
        ok=0;
    }
    tar++;
    db(tar)

    return 0;
}