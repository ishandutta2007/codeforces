#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>

using namespace std;
typedef long long LL;
const int MX=1000011;
struct Edge{int f,t;}e[MX<<1];
int pool[MX<<1],*G[MX],D[MX];
int n,m;LL ans;
int vis[MX];
void dfs(int k){
	vis[k]=1;
	for(int *i=G[k];i!=G[k+1];i++)if(!vis[*i])dfs(*i);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&e[i].f,&e[i].t);
		++D[e[i].f],++D[e[i].t];
	}
	G[1]=pool;for(int i=1;i<=n;i++)G[i+1]=G[i]+D[i];
	for(int i=1;i<=m;i++){
		G[e[i].f][--D[e[i].f]]=e[i].t;
		G[e[i].t][--D[e[i].t]]=e[i].f;
	}
	for(int i=1;i<=m;i++)++D[e[i].f],++D[e[i].t];
	for(int i=1;i<=n;i++){
		if(D[i]){
			dfs(i);break;
		}
	}
	for(int i=1;i<=m;i++)if(!vis[e[i].f]&&!vis[e[i].t]){
		printf("0\n");return 0;
	}
	memset(D,0,sizeof(D));
	LL c1=0,c2=0;
	for(int i=1;i<=m;i++)if(e[i].f==e[i].t)c1++;else c2++;
	ans+=c1*(c1-1)/2+c1*c2;
	for(int i=1;i<=m;i++){
		if(e[i].f!=e[i].t)++D[e[i].f],++D[e[i].t];
	}
	for(int i=1;i<=n;i++)ans+=(LL)D[i]*(D[i]-1)/2;
	printf("%lld\n",ans);
	return 0;
}