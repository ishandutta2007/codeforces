#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(3e3+5)

vector<int> g[MAXN];
ll dp[MAXN][MAXN];
ll pas[MAXN][MAXN];
ll sum[MAXN][MAXN];

void dfs(int u)
{
    for(int i=1;i<MAXN;i++)
        dp[u][i]=1;
    for(auto v : g[u])
    {
        dfs(v);
        for(int i=1;i<MAXN;i++)
            dp[u][i]=(dp[u][i]*sum[v][i])%mod;
    }

    for(int i=1;i<MAXN;i++)
        sum[u][i]=(sum[u][i-1]+dp[u][i])%mod;
}

ll comb(int n,int m)
{
    return pas[n+1][m+1];
}

ll qp(ll b,ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
            ans=(ans*b)%mod;
        e>>=1;
        b=(b*b)%mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pas[0][0]=1;
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<=i;j++)
            pas[i][j]=(pas[i-1][j-1]+pas[i-1][j])%mod;

    int n,d;
    cin >> n >> d;
    for(int i=0;i<n-1;i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i+1);
    }

    dfs(0);

    vector<ll> act(n+1);
    for(int i=0;i<=n;i++)
        act[i]=sum[0][i];

    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            act[i]=(act[i]-((act[j]*comb(i,j))%mod)+mod)%mod;

    ll c=1;
    ll ans=0;
    for(int i=1;i<=min(d,n);i++)
    {
        c=(c*(d-i+1))%mod;
        c=(c*qp(i,mod-2))%mod;
        ans=(ans+c*act[i])%mod;
    }
    db(ans)

    return 0;
}