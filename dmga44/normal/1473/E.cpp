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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-8);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<pii> g[MAXN];
ll res[MAXN][4];
bool mk[MAXN][4];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
    }

    priority_queue<pip,vector<pip>,greater<pip> > pq;
    pq.push(pip(0,pii(0,0)));
    res[0][1]=1e18;
    res[0][2]=1e18;
    res[0][3]=1e18;
    while(!pq.empty())
    {
        pip x=pq.top();
        pq.pop();
        int u=x.s.f;
        int ty=x.s.s;
        ll w=x.f;
        if(mk[u][ty])
            continue;
        mk[u][ty]=1;
        res[u][ty]=w;
        for(auto p : g[u])
        {
            int v=p.f;
            ll w0=p.s;
            if(!ty)
                pq.push(pip(w+w0,pii(v,3)));
            if(!(ty&1))
                pq.push(pip(w,pii(v,ty|1)));
            if(!(ty&2))
                pq.push(pip(w+2*w0,pii(v,ty|2)));
            pq.push(pip(w+w0,pii(v,ty)));
        }
    }

    for(int i=1;i<n;i++)
        cout << res[i][3] << ' ';
    cout << '\n';

    return 0;
}