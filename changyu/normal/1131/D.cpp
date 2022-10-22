#include<cstdio>
const int N=1002;// 
int n,m,p[N+N],g[N+N][N+N],d[N+N],q[N+N],l,r=-1,f[N+N];char a[N][N];
int Find(int k){return k==p[k]?k:p[k]=Find(p[k]);}
int main()
{
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(u=1;u<=n+m;u++)p[u]=u;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	  if(a[i][j]=='=')p[Find(i)]=Find(j+n);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	  if(a[i][j]!='=')
	  {
	  	u=Find(i),v=Find(j+n);
		if(u==v)return 0*puts("No");
		else{
		  if(a[i][j]=='>'&&!g[v][u])g[v][u]=1,d[u]++;
		  if(a[i][j]=='<'&&!g[u][v])g[u][v]=1,d[v]++;
		}
	  }
	for(u=1;u<=n+m;u++)if(!d[u])
	  f[u]=1,q[++r]=u;
	for(;l<=r;){
	  u=q[l++];
	  for(v=1;v<=n+m;v++)
		if(g[u][v]&&!--d[v])q[++r]=v,f[v]=f[u]+1;
	}
	for(u=1;u<=n+m;u++)if(d[u])return 0*puts("No");
	puts("Yes");
	for(u=1;u<=n;u++)printf("%d ",f[Find(u)]);
	puts("");
	for(u=n+1;u<=n+m;u++)printf("%d ",f[Find(u)]);
	return 0;
}