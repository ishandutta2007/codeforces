#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector<array<int,2>> v[N];
vector<int> depth(N,0);
vector<vector<int>> p(N,vector<int>(17,0));
vector<int> x(N,0);
vector<int> res(N,0);

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<=17;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(auto [to,id]:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs(to);
    }
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=16;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=16;i>=0;i--)
    {
        if(p[a][i]!=p[b][i])
        {
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];
}

void solve(int a)
{
    int cnt=x[a];
    int par=-1;
    for(auto [to,id]:v[a])
    {
        if(to==p[a][0]) par=id;
        else
        {
            solve(to);
            cnt+=res[id];
        }
    }
    if(par!=-1) res[par]=cnt;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    dfs(1);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int l=lca(a,b);
        x[l]-=2;
        x[a]++;
        x[b]++;
    }
    solve(1);
    for(int i=0;i<n-1;i++) printf("%d%c",res[i]," \n"[i==n-2]);
    return 0;
}