#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> g[MAXN];
ll dp[MAXN];
ll dp2[MAXN];

void dfs(int u)
{
    dp[u]=1;
    dp2[u]=0;
    vector<ll> d(3);
    d[0]=1;
    vector<int> sons;
    for(auto v : g[u])
    {
        dfs(v);
//        cout << u << ' ' << v << '\n';
        dp[u]=(dp[u]*dp[v])%mod;
        d[2]=(d[2]*((dp[v]+dp2[v])%mod))%mod;
        d[2]=(d[2]+d[1]*dp2[v])%mod;
        d[1]=(d[0]*dp2[v]+d[1]*dp[v])%mod;
        d[0]=(d[0]*dp[v])%mod;
        sons.push_back(v);
    }
    if(!g[u].size())
    {
        dp2[u]=1;
        return ;
    }
//    cout << d[0] << ' ' << d[1] << ' ' << d[2]<< '\n';
    dp[u]=(dp[u]+d[2])%mod;
    dp2[u]=d[2];
    vector<ll> m(g[u].size()+1),mi(g[u].size()+1);
    m[0]=1;
    mi[g[u].size()]=1;
    for(int i=0;i<g[u].size();i++)
        m[i+1]=(m[i]*dp[g[u][i]])%mod;
    for(int i=g[u].size()-1;i>=0;i--)
        mi[i]=(mi[i+1]*dp[g[u][i]])%mod;
    for(int i=0;i<g[u].size();i++)
        dp2[u]=(dp2[u]+((dp2[g[u][i]]*m[i])%mod)*mi[i+1])%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin>> x;
        g[x-1].push_back(i+1);
    }

    dfs(0);

    db(dp[0])

    return 0;
}
/**
5
1 1 1 1
4
1 2 2
**/