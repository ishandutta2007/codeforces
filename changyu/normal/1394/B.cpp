#include<cstdio>
#include<algorithm>
#include<vector>
const int N=2e5+3,K=9;
int n,m,d,b[N][K][K],e[K][K][K][K],p[K],ans;
struct edge{int v,c;};
bool Cmp(const edge&a,const edge&n){return a.c<n.c;}
std::vector<edge>g[N];
void Dfs(int t){
	if(t==d){
	  for(int i=0;i<d;i++)
		for(int j=0;j<=i;j++)
		  if(e[i][p[i]][j][p[j]])return;
	  ++ans;
	  //for(int i=0;i<d;i++)printf("%d ",p[i]);puts("");
	  return;
	}
	for(int i=0;i<=t;i++)
	  p[t]=i,Dfs(t+1);
}
signed main(){
	int u,v,c;
	scanf("%d%d%d",&n,&m,&d);
	for(int j=1;j<=m;j++){
	  scanf("%d%d%d",&u,&v,&c);
	  g[u].push_back((edge){v,c});
	}
	for(u=1;u<=n;u++){
	  std::sort(g[u].begin(),g[u].end(),Cmp);
	  for(int i=0;i<g[u].size();i++)
		++b[g[u][i].v][g[u].size()-1][i];//printf("%d %d %d\n",g[u][i].v,g[u].size()-1,i);
	}
	for(u=1;u<=n;u++){
	  for(int i=0;i<d;i++)
		for(int j=0;j<=i;j++)
		  for(int k=0;k<i;k++)
			for(int l=0;l<=k;l++)if(b[u][i][j]&&b[u][k][l])
			  e[i][j][k][l]=1;
	  for(int i=0;i<d;i++)
		for(int j=0;j<=i;j++)if(b[u][i][j]>1)
		  e[i][j][i][j]=1;
	}
	Dfs(0);
	printf("%d\n",ans);
	return 0;
}