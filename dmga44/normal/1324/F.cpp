#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

int a[MAXN],dp[MAXN],mk[MAXN];
vector<int> g[MAXN];

void dfs(int u)
{
    mk[u]=1;
    dp[u]=1;
    if(a[u]==0)
        dp[u]=-1;

    for(auto v: g[u])
        if(!mk[v])
        {
            dfs(v);
            dp[u]+=max(dp[v],0);
        }
}

void dfs1(int u)
{
    mk[u]=1;
    for(auto v: g[u])
        if(!mk[v])
        {
            if(dp[v]>dp[u])
            {
                dfs1(v);
                continue;
            }
            if(a[v] || dp[v]>=0)
                dp[v]=dp[u];
            else if(dp[u]>=0)
                dp[v]=dp[u]-1;
            dfs1(v);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    for(int i=0;i<n;i++)
        mk[i]=0;
    dfs1(0);

    for(int i=0;i<n;i++)
        cout << dp[i] << ' ';
    cout << '\n';

    return 0;
}