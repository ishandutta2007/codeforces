#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
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
typedef vector<ll> vi;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int d[MAXN];
bool mk[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return ;
    if(d[u]>d[v])
        swap(u,v);

    mk[u]|=mk[v];
    d[u]+=d[v];
    d[v]=u;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<ppp> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        edges.push_back(ppp(pii(w,i),pii(u,v)));
    }

    sort(allr(edges));

    for(int i=0;i<n;i++)
        d[i]=-1;

    ll ans=0;
    for(auto e : edges)
    {
        int u=find(e.second.first);
        int v=find(e.second.second);
        if(u!=v && (!mk[u] || !mk[v]))
        {
            ans+=e.first.first;
            join(u,v);
        }
        if(u==v)
        {
            if(!mk[u])
            {
                ans+=e.first.first;
                mk[u]=1;
            }
        }
    }

    cout << ans << '\n';

    return 0;   
}