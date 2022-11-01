#include <bits/stdc++.h>

using namespace std;

const int N=200005;
vector<int> v[N];
vector<pair<int,long long>> g[N];
vector<vector<int>> p(N,vector<int>(18,0));
vector<long long> val(N,0);
vector<long long> d(N,0);
vector<int> x(N,0);
vector<int> res(N,0);

void dfs(int a)
{
    for(int i=1;i<18;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(auto [to,w]:g[a])
    {
        d[to]=d[a]+w;
        p[to][0]=a;
        dfs(to);
    }
}

void lift(int a)
{
    int b=a;
    for(int i=17;i>=0;i--) if(p[a][i]!=0&&d[p[a][i]]>=d[b]-val[b]) a=p[a][i];
    x[p[b][0]]++;
    x[p[a][0]]--;
}

void solve(int a)
{
    res[a]=x[a];
    for(int to:v[a])
    {
        solve(to);
        res[a]+=res[to];
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%I64d",&val[i]);
    for(int i=2;i<=n;i++)
    {
        int a,w;
        scanf("%d%d",&a,&w);
        v[a].push_back(i);
        g[a].push_back({i,w});
    }
    dfs(1);
    for(int i=1;i<=n;i++) lift(i);
    solve(1);
    for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
    return 0;
}