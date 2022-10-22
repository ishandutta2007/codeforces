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
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(6e5+5)

ll sum1,sum2;
vector<pii> g[MAXN];
ll sons[MAXN];
bool mk[MAXN];
int n;

void dfs(int u)
{
    mk[u]=1;
    sons[u]=1;
    vector<pii> ss;
    for(auto y : g[u])
    {
        ll v=y.f;
        ll w=y.s;
        if(!mk[v])
        {
            ss.push_back(y);
            dfs(v);
            ll x=sons[v];
            if(x&1)
                sum1+=w;
            sons[u]+=sons[v];
        }
    }

    for(auto y : ss)
    {
        ll v=y.f;
        ll w=y.s;

        ll x=min(sons[v],2*n-sons[v]);
        sum2+=x*w;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        sum1=0;
        sum2=0;
        cin >> n;
        for(int i=0;i<2*n-1;i++)
        {
            ll u,v,w;
            cin >> u >> v >> w;
            u--,v--;
            g[u].push_back(pii(v,w));
            g[v].push_back(pii(u,w));
        }

        dfs(0);

        cout << sum1 << ' ' << sum2 << '\n';

        for(int i=0;i<2*n;i++)
        {
            mk[i]=0;
            sons[i]=0;
            g[i].clear();
        }
    }

    return 0;
}