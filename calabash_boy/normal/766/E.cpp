
#include<stdio.h>
const int N=2e5+1;
long long r;
int i,j,k,n,a[N],f[N][2];
int t,en[N],fa[N],nxt[N];
void dfs(int u,int p){	
int w=a[u]>>k&1,i=fa[u],v;
for(f[u][w]=1,f[u][w^1]=0;i;i=nxt[i])if((v=en[i])!=p)	{	
    dfs(v,u);	
    r+=(1ll*f[v][0]*f[u][1]+1ll*f[v][1]*f[u][0])<<k;	
    f[u][1]+=f[v][w^1],f[u][0]+=f[v][w];	
    }
}
int main(){	
    scanf("%d",&n);	
    for(i=1;i<=n;r+=a[i++])	
        scanf("%d",a+i);	
    for(k=1;k<n;++k){	
        scanf("%d%d",&i,&j);	
        en[++t]=j,nxt[t]=fa[i],fa[i]=t;	
        en[++t]=i,nxt[t]=fa[j],fa[j]=t;	
    }	
    for(k=19;k>=0;--k)
        dfs(1,0);	
    printf("%I64d",r);
}