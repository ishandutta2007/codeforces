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
typedef pair<ld,pii> pdp;
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
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

int d[MAXN][MAXN];
vector<pii> g[MAXN];
pii ks[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    vector<pii> edges;
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        u--,v--;
        edges.push_back(pii(u,v));
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
    }

    for(int i=0;i<k;i++)
    {
        cin >> ks[i].f >> ks[i].s;
        ks[i].f--;
        ks[i].s--;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            d[i][j]=oo;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push(pii(0,i));
        vector<bool> mk(n,0);
        while(!pq.empty())
        {
            pii x=pq.top();
            pq.pop();
            int u=x.s;
            int w=x.f;
            if(mk[u])
                continue;
            mk[u]=1;
            d[i][u]=w;
            for(auto y : g[u])
                if(!mk[y.f])
                    pq.push(pii(w+y.s,y.f));
        }
    }

    ll res=oo;
    for(int i=0;i<m;i++)
    {
        int u=edges[i].f;
        int v=edges[i].s;
        ll sum=0;
        for(int j=0;j<k;j++)
        {
            int a=ks[j].f;
            int b=ks[j].s;
            ll v1=d[a][b];
            v1=min(v1,(ll)d[a][u]+d[v][b]);
            v1=min(v1,(ll)d[a][v]+d[u][b]);
            sum+=v1;
        }
        res=min(res,sum);
    }
    db(res)

    return 0;
}