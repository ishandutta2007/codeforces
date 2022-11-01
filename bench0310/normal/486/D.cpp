#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;
const int N=2005;
int n;
vector<int> v[N];
vector<bool> in(N,0);
vector<bool> vis(N,0);
vector<ll> val(N,0);

void dfs(int a)
{
    vis[a]=1;
    val[a]=1;
    for(int to:v[a])
    {
        if(in[to]==0||vis[to]==1) continue;
        dfs(to);
        val[a]=(val[a]*(val[to]+1))%mod;
    }
}

ll solve()
{
    vis.assign(N,0);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==1)
        {
            if(vis[i]==0) dfs(i);
            res=(res+val[i])%mod;
        }
    }
    return res;
}

int main()
{
    int d;
    scanf("%d%d",&d,&n);
    if(d==2000) d--;
    vector<vector<int>> x(2001);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        x[a].push_back(i);
    }
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<bool> now(n+1,0);
    vector<bool> nxt(n+1,0);
    for(int i=1;i<=d;i++) for(int a:x[i]) nxt[a]=1;
    ll res=0;
    for(int i=d+1;i<=2000;i++)
    {
        for(int a:x[i]) nxt[a]=1;
        for(int a:x[i-d-1]) nxt[a]=0;
        for(int j=1;j<=n;j++) in[j]=nxt[j];
        res=(res+solve())%mod;
        for(int j=1;j<=n;j++) in[j]=(now[j]&&nxt[j]);
        res=(res-solve()+mod)%mod;
        now=nxt;
    }
    printf("%I64d\n",res);
    return 0;
}