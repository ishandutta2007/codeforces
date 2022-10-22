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
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

vector<int> g[MAXN];
int aux[MAXN][45];
int tot[MAXN][45];
int a[MAXN];
bool mk[MAXN];
int n,k;

void dfs1(int u)
{
    mk[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs1(v);
            for(int i=0;i<2*k;i++)
                aux[u][(i+1)%(2*k)]^=aux[v][i];
        }
    aux[u][0]^=a[u];
}

void dfs2(int u)
{
    mk[u]=1;
    for(int i=0;i<2*k;i++)
        tot[u][i]^=aux[u][i];
    for(auto v : g[u])
        if(!mk[v])
        {
            for(int i=0;i<2*k;i++)
                tot[v][(i+1)%(2*k)]^=tot[u][i]^aux[v][(i-1+2*k)%(2*k)];
            dfs2(v);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0;i<n;i++)
        cin >> a[i];

    dfs1(0);
    for(int i=0;i<n;i++)
        mk[i]=0;
    dfs2(0);

    for(int i=0;i<n;i++)
    {
        ll x=0;
        for(int j=k;j<2*k;j++)
            x^=tot[i][j];
        cout << (int)(x!=0) << ' ';
    }
    cout << '\n';

    return 0;
}