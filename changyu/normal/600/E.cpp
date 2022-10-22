#include<cstdio>
const int N=1e5+1;
struct node{int v,nxt;}g[N+N];
int n,a[N],b[N],head[N],siz[N],son[N],k,mx;long long sum,ans[N];
inline void Insert(int u,int v){g[++k]=(node){v,head[u]};head[u]=k;}
void Dfs(int u,int fa){
	int v,mx=0,p=0;siz[u]=1;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa){
	  Dfs(v,u),siz[u]+=siz[v];
	  if(siz[v]>mx)mx=siz[v],p=v;
	}son[u]=p;
}
void Update(int u,int fa,int w,int d){
	//printf("%d %d\n",u,d);
	int v;
	b[a[u]]+=d;
	if(b[a[u]]==mx)sum+=a[u];
	if(b[a[u]]>mx)mx=b[a[u]],sum=a[u];
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa&&v!=w)
	  Update(v,u,w,d);
}
void Dfs1(int u,int fa){
	int v;
	for(int i=head[u];i;i=g[i].nxt)if((v=g[i].v)!=fa&&v!=son[u])
	  Dfs1(v,u),Update(v,u,0,-1),mx=-1,sum=0;
	if(son[u])Dfs1(son[u],u);
	Update(u,fa,son[u],1);
	ans[u]=sum;
}
int main(){
	int u,v;
	scanf("%d",&n);
	for(u=1;u<=n;u++)scanf("%d",a+u);
	for(int i=1;i<n;i++)
	  scanf("%d%d",&u,&v),Insert(u,v),Insert(v,u);
	mx=-1,sum=0;
	Dfs(1,0);Dfs1(1,0);
	for(u=1;u<=n;u++)printf("%I64d ",ans[u]);
	return 0;
}