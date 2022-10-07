#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,h,m,l,r,x,c,ans,k=1,head[100005],Next[2000005],adj[2000005],flow[2000005],j,u,T;
int q[100005],d[5005],ansf,last[5005],i;
void Push(int u,int v,int w)
{
    Next[++k]=head[u];
    head[u]=k;
    adj[k]=v;
    flow[k]=w;
    Next[++k]=head[v];
    head[v]=k;
    adj[k]=u;
    flow[k]=0;
}
bool dfs(int i,int f)
{
    if(i==T)
    {
        ansf=f;
        ans-=f;
        return true;
    }
    int j;
    for(j=last[i];j!=0;last[i]=j=Next[j])
        if(flow[j]!=0&&d[adj[j]]==d[i]+1)
            if(dfs(adj[j],min(flow[j],f)))
            {
                flow[j]-=ansf;
                flow[j^1]+=ansf;
                return true;
            }
    return false;
}
int main()
{
    scanf("%d %d %d",&n,&h,&m);
    ans=h*h*n;
    T=n*h+m+1;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d %d",&l,&r,&x,&c);
        Push(0,i+n*h,c);
        if(x!=h)
            for(j=l;j<=r;j++)
                Push(i+n*h,j+x*n,1<<30);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<h;j++)
            Push(i+(j-1)*n,i+j*n,1<<30);
        for(j=1;j<=h;j++)
            Push(i+(j-1)*n,T,j*j-(j-1)*(j-1));
    }
    while(1)
    {
        q[l=r=1]=0;
        memset(d,-1,sizeof(d));
        d[0]=0;
        while(l<=r)
        {
            for(j=head[q[l]];j!=0;j=Next[j])
                if(d[adj[j]]==-1&&flow[j]!=0)
                {
                    d[adj[j]]=d[q[l]]+1;
                    q[++r]=adj[j];
                }
            l++;
        }
        if(d[T]==-1)
            break;
        for(i=0;i<=T;i++)
            last[i]=head[i];
        while(dfs(0,1<<30));
    }
    cout<<ans;
}