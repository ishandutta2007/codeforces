#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=555;
const double inf=1e10,eps=1e-10;
int n,m,L;
int adj[maxn*2],c[maxn*2],next[maxn*2],head[maxn],tot=1;
int col[maxn];

double A[maxn][maxn],X[maxn];
int bas[maxn],out[maxn];

int dc(const double &a)
{return a>eps?1:(a<-eps?-1:0);}

void addedge(int u,int v,int w)
{tot++;adj[tot]=v;c[tot]=w;next[tot]=head[u];head[u]=tot;
tot++;adj[tot]=u;c[tot]=w;next[tot]=head[v];head[v]=tot;}

void tdfs(int x,int fa,int dp,double *a)
{
    if(dp>=0)
    {
        a[x]--;
        for(int i=head[x];i;i=next[i])
            if(adj[i]!=fa)
                tdfs(adj[i],x,dp-c[i],a);
    }
}

void init()
{
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)
        scanf("%d",col+i);
    for(int i=1,u,v,w;i<n;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }
}

void work()
{
    int ts=0;
    for(int i=1;i<=n;i++)
        A[0][i]=col[i]-1,ts+=col[i];
    for(int i=1;i<=n;i++)
    {
        tdfs(i,0,L,A[i]);
        A[i][n+1]=-1;
    }
    for(int i=1;i<=n;i++)A[n+1][i]=1;
    A[n+1][n+1]=ts;
    m=n+1;
}

void PIVOT(int a,int b)
{
    for(int i=0;i<=m;i++)
        if(i!=a&&dc(A[i][b]))
            for(int j=1;j<=n+1;j++)
                if(j!=b)A[i][j]-=A[a][j]*A[i][b]/A[a][b];
    for(int j=1;j<=n+1;j++)
        if(j!=b)A[a][j]/=A[a][b];
    for(int i=0;i<=m;i++)
        if(i!=a)A[i][b]/=-A[a][b];
    A[a][b]=1/A[a][b];
    swap(bas[a],out[b]);
}

void OUT()
{
    for(int i=0;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%.1lf ",A[i][j]);
        printf("%.1lf\n",A[i][n+1]);
    }
}

double simplex()
{
    for(int j=1;j<=n;j++)
        A[0][j]=-A[0][j];
    for(int i=0;i<=m;i++)bas[i]=-i;
    for(int j=1;j<=n+1;j++)out[j]=j;
    while(1)
    {
        int ii=1,jj=1;
        for(int i=1;i<=m;i++)
            if(make_pair(A[i][n+1],bas[i])<make_pair(A[ii][n+1],bas[ii]))ii=i;
        if(dc(A[ii][n+1])>=0)break;
        for(int j=1;j<=n;j++)
            if(A[ii][j]<A[ii][jj])jj=j;
        if(A[ii][jj]>=0)return -inf;
        PIVOT(ii,jj);
    }
    while(1)
    {
        int ii=1,jj=1;
        for(int j=1;j<=n;j++)
            if(make_pair(A[0][j],out[j])<make_pair(A[0][jj],out[jj]))jj=j;
        if(A[0][jj]>=0)break;
        for(int i=1;i<=m;i++)
            if(A[i][jj]>0&&(A[ii][jj]<=0||make_pair(A[i][n+1]/A[i][jj],bas[i])<make_pair(A[ii][n+1]/A[ii][jj],bas[ii])))ii=i;
        if(A[ii][jj]<=0)return inf;
        PIVOT(ii,jj);
    }
    for(int j=1;j<=n;j++)X[j]=0;
    for(int i=1;i<=m;i++)
        if(bas[i]>=0)X[bas[i]]=A[i][n+1];
    return A[0][n+1];
}

void solve()
{
    //OUT();
    double r=simplex();
    if(r<-1e9)puts("-1");
    else printf("%.0lf\n",eps-r);
}

int main()
{
    init();
    work();
    solve();
    return 0;
}