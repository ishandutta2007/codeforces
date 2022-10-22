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
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

vector<int> g[MAXN];
bool ok;
bool mk[MAXN];
int c[MAXN];

void dfs(int u)
{
    mk[u]=1;
    for(auto v : g[u])
    {
        if(mk[v])
        {
            if(c[v]==c[u])
                ok=0;
            continue;
        }
        c[v]=1-c[u];
        dfs(v);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ok=1;
    for(int i=0;i<n;i++)
        if(!mk[i])
            dfs(i);
    if(!ok)
        db(-1)
    else
    {
        vector<int> vv[2];
        for(int i=0;i<n;i++)
            vv[c[i]].push_back(i);
        for(int i=0;i<2;i++)
        {
            db(vv[i].size())
            for(auto y : vv[i])
                cout << y+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}