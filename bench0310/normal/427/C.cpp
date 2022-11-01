#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<int> v[N];
vector<int> vr[N];
vector<bool> vis(N,0);
vector<int> ord;
vector<int> now;

void dfs(int a)
{
    vis[a]=1;
    for(int to:v[a])
    {
        if(vis[to]==1) continue;
        dfs(to);
    }
    ord.push_back(a);
}

void gen(int a)
{
    now.push_back(a);
    vis[a]=1;
    for(int to:vr[a])
    {
        if(vis[to]==1) continue;
        gen(to);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    vector<ll> c(n+1,0);
    for(int i=1;i<=n;i++) scanf("%I64d",&c[i]);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        vr[b].push_back(a);
    }
    for(int i=1;i<=n;i++) if(vis[i]==0) dfs(i);
    for(int i=1;i<=n;i++) vis[i]=0;
    ll best=0;
    ll res=1;
    const ll mod=1000000007;
    reverse(ord.begin(),ord.end());
    for(int x:ord)
    {
        if(vis[x]==0)
        {
            gen(x);
            ll mn=(1ll<<60);
            ll cnt=0;
            for(int y:now)
            {
                if(c[y]<mn)
                {
                    mn=c[y];
                    cnt=1;
                }
                else if(c[y]==mn) cnt++;
            }
            best+=mn;
            res=(res*cnt)%mod;
            now.clear();
        }
    }
    printf("%I64d %I64d\n",best,res);
    return 0;
}