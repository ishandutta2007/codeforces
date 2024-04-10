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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> g[MAXN];
bool mk[MAXN];
int sz[MAXN];
int res[MAXN];
int n;

void dfs(int u)
{
    mk[u]=1;
    sz[u]=1;
    int ms=0;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs(v);
            ms=max(ms,sz[v]);
            sz[u]+=sz[v];
        }
    res[u]=max(n-sz[u],ms);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int u,v;
        cin >> n;
        for(int i=0;i<n-1;i++)
        {
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0);

//        for(int i=0;i<n;i++)
//        {
//            cout << i << ' ' << res[i] << ' ' << sz[i] << '\n';
//        }

        vector<int> ps;
        int mi=n;
        for(int i=0;i<n;i++)
        {
            if(mi<res[i])
                continue;
            if(mi>res[i])
                ps.clear();
            mi=res[i];
            ps.push_back(i);
        }

//        for(auto y : ps)
//            cout << y << ' ';
//        cout << '\n';

        if(ps.size()==1)
        {
            cout << 1 << ' ' << g[0][0]+1 << '\n';
            cout << 1 << ' ' << g[0][0]+1 << '\n';
        }
        else
        {
            int u=-1;
            for(auto y : g[ps[0]])
                if(y!=ps[1])
                    u=y;
            cout << ps[0]+1 << ' ' << u+1 << '\n';
            cout << ps[1]+1 << ' ' << u+1 << '\n';
        }

        for(int i=0;i<n;i++)
        {
            mk[i]=0;
            sz[i]=0;
            res[i]=0;
            g[i].clear();
        }
    }

    return 0;
}