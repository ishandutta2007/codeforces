#include<bits/stdc++.h>
using namespace std;
const int N=202001;
 
int Bits[25],f[N][25],n,q;
int e=0,first[N],nxt[N],point[N],dep[N];
void add_edge(int x,int y)
{
    point[e]=y;
    nxt[e]=first[x];
    first[x]=e; e++;
}
 
void dfs(int u,int F)
{
    for(int i=first[u];i!=-1;i=nxt[i])
    {
        if(point[i]==F) continue;
        int v=point[i];
        f[v][0]=u;
        dep[v]=dep[u]+1;
        for(int j=1;j<21;j++) f[v][j]=f[f[v][j-1]][j-1];
        dfs(v,u);
    }
}
 
int LCA(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
 
int solve(int x,int y)
{
    int father=LCA(x,y);
    return dep[x]+dep[y]-dep[father]*2;
}
 
void init()
{
    Bits[0]=1;
    for(int i=1;i<=20;i++) Bits[i]=Bits[i-1]*2;
}
 
int main()
{
    init();
    memset(first,-1,sizeof(first));
    memset(nxt,-1,sizeof(nxt));
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    memset(f,0,sizeof(f));
    dep[1]=1; dfs(1,0);
    scanf("%d",&q);
    while(q--)
    {
        int x,y,a,b,k;
        scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
        int disax=solve(a,x);
        int disay=solve(a,y);
        int disbx=solve(b,x);
        int disby=solve(b,y);
        int dis1=min(disax+disby+1,disay+disbx+1);
        int dis2=solve(a,b);
        if(k>=dis1&&(k-dis1)%2==0)
        {
        	puts("YES");
        	continue;
        }
        if(k>=dis2&&(k-dis2)%2==0)
        {
        	puts("YES");
        	continue;
        }
        puts("NO");
    }
}