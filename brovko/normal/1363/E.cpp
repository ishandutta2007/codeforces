#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, a[200005], b[200005], c[200005], f[200005], used[200005], mc[200005], ans, k0[200005], k1[200005];
vector <int> g[200005];

void dfs(int v)
{
    used[v]=1;
    if(f[v]==1)
        k1[v]=1;
    if(f[v]==0)
        k0[v]=1;

    for(auto to:g[v])
    {
        if(used[to]==0)
        {
            mc[to]=min(mc[v], a[to]);
            dfs(to);
            k0[v]+=k0[to];
            k1[v]+=k1[to];
        }
    }

    if(k0[v]>0 && k1[v]>0)
    {
        int x=min(k0[v], k1[v]);
        k0[v]-=x;
        k1[v]-=x;
        ans+=mc[v]*2*x;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        if(b[i]==0 && c[i]==1)
            f[i]=0;
        else if(b[i]==1 && c[i]==0)
            f[i]=1;
        else f[i]=2;
    }

    for(int i=0;i<n-1;i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int k=0;
    for(int i=0;i<n;i++)
    {
        if(f[i]==0)
            k++;
        if(f[i]==1)
            k--;
    }
    if(k!=0)
    {
        cout << -1;
        return 0;
    }

    mc[0]=a[0];
    dfs(0);
    cout << ans;
}