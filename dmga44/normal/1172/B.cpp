#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005
#define mod 998244353

ll f[MAXN],dp[MAXN],sons[MAXN];
bool mk[MAXN];
vector<int> g[MAXN];

void dfs(int u)
{
    mk[u]=1;
    dp[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs(v);
            sons[u]++;
            dp[u]=(dp[u]*((dp[v]*(sons[v]+1))%mod))%mod;
        }
    dp[u]=(dp[u]*f[sons[u]])%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    f[0]=1;
    for(ll i=1;i<MAXN;i++)
        f[i]=(f[i-1]*i)%mod;

    ll n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

//    for(int i=0;i<n;i++)
//        db(dp[i])
    db((dp[0]*n)%mod)

    return 0;
}