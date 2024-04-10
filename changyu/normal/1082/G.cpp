#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
#define S (n+m+1)
#define T (n+m+2)
const int V=2003,INF=1e15;
int n,m,a,head[V],iter[V],k,ans,q[V],l,r,d[V];
struct edge{int v,c,nxt;}g[8003];
inline void Insert(int u,int v,int c){
	g[k]=(edge){v,c,head[u]},head[u]=k++;
	g[k]=(edge){u,0,head[v]},head[v]=k++;
}
inline bool Bfs(){
	int u,v;
	for(u=1;u<=T;u++)d[u]=0;
	d[q[l=r=0]=S]=1;
	for(;l<=r;){
	  u=q[l++];
	  for(int i=head[u];~i;i=g[i].nxt)if(g[i].c&&!d[v=g[i].v])
		d[q[++r]=v]=d[u]+1;
	}
	return d[T];
}
int Dfs(int u,int f){
	if(!f||u==T)return f;
	int tmp,s=0,v;
	for(int i=head[u];~i;i=g[i].nxt)
	  if(g[i].c&&d[v=g[i].v]>d[u]&&(tmp=Dfs(v,std::min(f,g[i].c)))){
		f-=tmp,s+=tmp;
		g[i].c-=tmp,g[i^1].c+=tmp;
		if(!f)return s;
	  }return s;
}
signed main()
{
	int u,v,c;
	scanf("%lld%lld",&n,&m);
	memset(head,-1,sizeof head);
	for(int i=1;i<=n;i++)scanf("%lld",&a),Insert(S,i,a);
	for(int j=1;j<=m;j++){
	  scanf("%lld%lld%lld",&u,&v,&c),ans+=c;
	  Insert(u,j+n,INF),Insert(v,j+n,INF);
	  Insert(j+n,T,c);
	}
	for(;Bfs();){
	  memcpy(iter,head,sizeof iter);
	  ans-=Dfs(S,INF);
	}
	printf("%lld\n",ans);
	return 0;
}