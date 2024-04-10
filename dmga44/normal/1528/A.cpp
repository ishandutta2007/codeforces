#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef __int128_t int128;
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
#define MAXN (ll)(1e5+5)

int l[MAXN];
int r[MAXN];
vector<int> g[MAXN];
bool mk[MAXN];
ll ans[MAXN][2];

void dfs(int u)
{
    mk[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs(v);
            ans[u][0]+=max(abs(l[u]-l[v])+ans[v][0],abs(l[u]-r[v])+ans[v][1]);
            ans[u][1]+=max(abs(r[u]-l[v])+ans[v][0],abs(r[u]-r[v])+ans[v][1]);
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
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> l[i] >> r[i];
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0);

        db(max(ans[0][0],ans[0][1]))

        for(int i=0;i<n;i++)
        {
            mk[i]=0;
            g[i].clear();
            ans[i][0]=ans[i][1]=0;
        }
    }

    return 0;
}