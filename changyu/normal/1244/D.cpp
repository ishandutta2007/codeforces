#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=1e5+3;
struct edge{int v,nxt;}g[N+N];
int n,a[N][3],head[N],k,root,d[N],t[3],c[N];long long s,ans=1e18;
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
inline void Dfs1(int u,int k,int fa){
	int v;
	s+=a[u][t[k]];c[u]=t[k];
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa)
	  Dfs1(v,(k+1)%3,u);
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(int j=0;j<3;j++)
	  for(u=1;u<=n;u++)scanf("%d",&a[u][j]);
	for(int i=1;i<n;i++){
	  scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u),d[u]++,d[v]++;
	  if(d[u]>2||d[v]>2)return 0*puts("-1");
	}
	for(u=1;u<=n;u++)if(d[u]==1)root=u;
	for(int i=0;i<3;i++)t[i]=i;
	do{
	s=0;
	Dfs1(root,0,0);
	ans=std::min(ans,s);
	}while(std::next_permutation(t,t+3));
	printf("%lld\n",ans);
	for(int i=0;i<3;i++)t[i]=i;
	do{
	s=0;
	Dfs1(root,0,0);
	if(ans==s){
	  for(u=1;u<=n;u++)printf("%d ",c[u]+1);
	  return 0;
	}
	}while(std::next_permutation(t,t+3));
}