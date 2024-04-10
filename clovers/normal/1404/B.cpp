#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int TTT=1,n,da,db,sa,sb;
vector<int> v[N];

int dep[N],maxdep,root=1;
void dfs(int u,int f)
{
    if(dep[u]>maxdep) maxdep=dep[u],root=u;
    for(int i=0;i<(int)v[u].size();i++)
    {
        int to=v[u][i]; if(to==f) continue;
        dep[to]=dep[u]+1;
        dfs(to,u);
    }
}

void init()
{
    scanf("%d%d%d%d%d",&n,&sa,&sb,&da,&db);
    for(int i=1;i<n;i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        v[x].push_back(y); v[y].push_back(x);
    }    
    maxdep=-1; dep[1]=0; dfs(1,-1);
    maxdep=-1; dep[root]=0; dfs(root,-1);
}

void solve()
{
    if(da*2>=db||da*2>=maxdep) 
    {
        puts("Alice");
        return;
    }
    dep[sa]=0; dfs(sa,-1);
    if(dep[sb]<=da) puts("Alice");
    else puts("Bob"); 
}

int main()
{
    cin>>TTT;
    while(TTT--){init(); solve(); for(int i=1;i<=n;i++) v[i].clear();}
    return 0;
}