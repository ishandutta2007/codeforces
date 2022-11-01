#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll inf=(1ll<<60);
const int N=5005;
int n;
vector<int> v[N];
vector<int> sz(N,0);
vector<int> big(N,0);
vector<int> c(N,0);
vector<int> d(N,0);
vector<vector<ll>> dp(N,vector<ll>(N,inf));
vector<vector<ll>> best(N,vector<ll>(N,inf));
vector<int> sub[N];

void dfs(int a)
{
    sz[a]=1;
    sub[a]={c[a]};
    for(int to:v[a])
    {
        dfs(to);
        sz[a]+=sz[to];
        if(sz[to]>sz[big[a]]) big[a]=to;
        vector<int> tmp;
        merge(sub[a].begin(),sub[a].end(),sub[to].begin(),sub[to].end(),back_inserter(tmp));
        sub[a]=tmp;
    }
    best[a][0]=0;
    for(int i=1;i<=sz[a];i++) best[a][i]=best[a][i-1]+sub[a][i-1];
}

void solve(int a)
{
    dp[a][1]=d[a];
    if(big[a]==0) return;
    for(int to:v[a]) solve(to);
    for(int i=1;i<=sz[big[a]];i++) dp[a][i+1]=min(dp[big[a]][i],best[big[a]][i])+d[a];
    vector<ll> &now=dp[a];
    for(int to:v[a])
    {
        if(to==big[a]) continue;
        vector<ll> nxt=now;
        for(int i=1;i<=sz[to];i++)
        {
            ll x=min(dp[to][i],best[to][i]);
            for(int j=1;j+i<=n;j++) nxt[j+i]=min(nxt[j+i],now[j]+x);
        }
        now=nxt;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll b;
    cin >> n >> b;
    for(int i=1;i<=n;i++)
    {
        cin >> c[i] >> d[i];
        d[i]=c[i]-d[i];
        if(i>=2)
        {
            int p;
            cin >> p;
            v[p].push_back(i);
        }
    }
    dfs(1);
    solve(1);
    int res=0;
    for(int i=1;i<=n;i++) if(min(dp[1][i],best[1][i])<=b) res=i;
    cout << res << "\n";
    return 0;
}