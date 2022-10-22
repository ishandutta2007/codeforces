#include<cstdio>
#include<cstring>
const int N=3e5+2,M=998244353;
struct edge{int v,nxt;}g[N+N];
int s,n,m,head[N],k,used[N],c,d;
inline int Pow(int a,int k){int s=1;for(;k;k>>=1)k&1?s=1ll*s*a%M:0,a=1ll*a*a%M;return s;}
inline void Insert(int u,int v){g[++k]=(edge){v,head[u]};head[u]=k;}
bool Dfs(int u,int o){
	int v,r;
	used[u]=o;o==1?c++:d++;
	for(int i=head[u];i;i=g[i].nxt)
	  if(used[v=g[i].v]==used[u]||!used[v]&&!Dfs(v,o==1?2:1))return 0;
	return 1;
}
int main(){
	int u,v;
	int T;scanf("%d",&T);for(;T--;){
	s=1;k=0;
	for(int i=1;i<=n;i++)used[i]=head[i]=0;
	scanf("%d%d",&n,&m);
	for(;m--;)
	  scanf("%d%d",&u,&v),
	  Insert(u,v),Insert(v,u);
	for(u=1;u<=n;u++)
	  if(!used[u])c=d=0,s*=Dfs(u,1),s=1ll*(Pow(2,c)+Pow(2,d))*s%M;
	printf("%d\n",s);
	}return 0;
}