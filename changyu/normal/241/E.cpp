#include<cstdio>
const int N=1003,M=5003,INF=23333;
int n,m,head[N],vis[N],vis1[N],d[N],k,x[M],y[M],q[N],l,r,inq[N],cnt[N];
struct node{int v,c,nxt;}g[M+M];
inline void Insert(int u,int v,int c){g[++k]=(node){v,c,head[u]};head[u]=k;}
void Dfs(int u){
	if(vis[u])return;
	vis[u]=1;
	for(int i=head[u];i;i=g[i].nxt)
	  if(g[i].c>0)Dfs(g[i].v);
}
void Dfs1(int u){
	if(vis1[u])return;
	vis1[u]=1;
	for(int i=head[u];i;i=g[i].nxt)
	  if(g[i].c<0)Dfs1(g[i].v);
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	  scanf("%d%d",x+i,y+i),Insert(x[i],y[i],2),Insert(y[i],x[i],-1);
	Dfs1(n);
	if(!vis1[1])return 0*puts("No");
	Dfs(1);
	for(u=1;u<=n;u++)d[u]=INF,vis[u]&=vis1[u];
	d[1]=0;
	q[l=r=0]=1,inq[1]=1,cnt[1]++;
	for(;l<=r;){
	  u=q[(l++)%N];inq[u]=0;
	  for(int i=head[u];i;i=g[i].nxt)if(vis[v=g[i].v]&&d[v]>d[u]+g[i].c){
		d[v]=d[u]+g[i].c;
		if(!inq[v]){
		  q[(++r)%N]=v,inq[v]=1,cnt[v]++;
		  if(cnt[v]>n)return 0*puts("No");
		}
	  }
	}
	puts("Yes");
	for(int i=1;i<=m;i++)
	  printf("%d\n",vis[x[i]]&&vis[y[i]]?d[y[i]]-d[x[i]]:1);
	return 0;
}