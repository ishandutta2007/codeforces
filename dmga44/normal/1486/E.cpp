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
typedef int ll;
typedef unsigned long long ull;
typedef double ld;
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
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

ll dp[MAXN][55],n;
bool mk[MAXN][55];
vector<pii> g[MAXN];

void dijkstra()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<55;j++)
            dp[i][j]=oo;

    priority_queue<pip,vector<pip>,greater<pip>> pq;
    pq.push(pip(0,pii(0,0)));
    while(!pq.empty())
    {
        pip xxx=pq.top();
        pq.pop();
        ll u=xxx.s.f;
        ll w=xxx.f;
        ll t=xxx.s.s;
        if(mk[u][t])
            continue;
        mk[u][t]=1;
        dp[u][t]=w;
        for(auto p : g[u])
        {
            ll v=p.f;
            ll w0=p.s;
            if(t)
            {
                if(w+(t+w0)*(t+w0)<dp[v][0])
                {
                    pq.push(pip(w+(t+w0)*(t+w0),pii(v,0)));
                    dp[v][0]=w+(t+w0)*(t+w0);
                }
            }
            else if(w<dp[v][w0])
            {
                pq.push(pip(w,pii(v,w0)));
                dp[v][w0]=w;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
    }

    dijkstra();

    for(int i=0;i<n;i++)
    {
        if(dp[i][0]==oo)
            cout << -1 << ' ';
        else
            cout << dp[i][0] << ' ';
    }
    cout << '\n';

    return 0;
}