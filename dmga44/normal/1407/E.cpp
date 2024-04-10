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
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

bool res[MAXN];
bool done[MAXN];
bool mk[MAXN];
vector<pii> g[MAXN];
int d[MAXN];
int cant[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        d[i]=oo;
    map<pip,bool> mkk;
    for(int i=0;i<m;i++)
    {
        int u,v,t;
        cin >> u >> v >> t;
        u--,v--;
        if(mkk[pip(u,pii(v,t))])
            continue;
        if(u==v)
            continue;
        mkk[pip(u,pii(v,t))]=1;
        g[v].push_back(pii(u,t));
    }

    if(n==1)
    {
        db(0)
        db(0)
        return 0;
    }

    queue<int> q;
    mk[n-1]=1;
    d[n-1]=0;
    done[n-1]=1;
    q.push(n-1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(auto y : g[u])
            cant[y.f]++;

        for(auto y : g[u])
        {
            int v=y.f;
            int t=y.s;
            if(mk[v])
                continue;
            if(done[v] && res[v]!=t)
                continue;
            if(done[v] && res[v]==t)
            {
                mk[v]=1;
                d[v]=d[u]+1;
                q.push(v);
                continue;
            }
            if(cant[v]==2)
            {
                mk[v]=1;
                d[v]=d[u]+1;
                q.push(v);
                done[v]=1;
            }
            if(cant[v]==1)
            {
                done[v]=1;
                res[v]=1-t;
            }
        }

        for(auto y : g[u])
            cant[y.f]--;
    }

    if(d[0]!=oo)
        db(d[0])
    else
        db(-1)
    for(int i=0;i<n;i++)
        cout << "01"[res[i]];
    cout << '\n';

    return 0;
}