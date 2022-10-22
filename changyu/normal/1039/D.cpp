#include<cstdio>
const int N=1e5+3;
struct edge{int v,nxt;}g[N+N];
int n,head[N],k,h[N][2],f[N],s,ans[N];
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
void Dfs(int u,int m,int fa){
	int v;
	h[u][0]=h[u][1]=0;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa){
	  Dfs(v,m,u);
	  if(f[v]>h[u][0])h[u][1]=h[u][0],h[u][0]=f[v];
	  else if(f[v]>h[u][1])h[u][1]=f[v];
	}
	if(h[u][0]+h[u][1]+1>=m)++s,f[u]=0;
	else f[u]=h[u][0]+1;
}
inline int Calc(int m){if(~ans[m])return ans[m];s=0,Dfs(1,m,0);return ans[m]=s;}
int main(){
	int u,v,l,r,m;
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	for(int i=1;i<=n;i++)ans[i]=-1;
	ans[1]=n;
	for(int p=1;;){
	  for(l=1,r=n+1;l<r;)m=l+r>>1,Calc(m)<ans[p]?r=m:l=m+1;
	  if(l>n)break;
	  for(++p;p<l;p++)ans[p]=ans[p-1];
	  ans[l]=Calc(l);
	  p=l;
	}
	for(int i=1;i<=n;i++)ans[i]=ans[i]<0?ans[i-1]:ans[i],printf("%d\n",ans[i]);
	return 0;
}