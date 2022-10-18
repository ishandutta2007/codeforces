#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
const int MX=200100;
struct Edge{int f,t;}e[MX],ee[MX];int ec;
int n,m,k;
int fa[MX],D[MX];
int pool[MX<<1],*G[MX],ett[MX<<1],ettc;
void dfs(int k,int f){
	ett[++ettc]=k;
	for(int *i=G[k];i!=G[k+1];i++){
		if(*i!=f)dfs(*i,k),ett[++ettc]=k;
	}
}
inline int ffa(int k){
	return k==fa[k]?k:(fa[k]=ffa(fa[k]));
}
int main(){
	scanf("%d%d%d",&n,&m,&k);for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d%d",&e[i].f,&e[i].t);
	for(int i=1;i<=m;i++){
		int fx=ffa(e[i].f),fy=ffa(e[i].t);
		if(fx!=fy){
			fa[fx]=fy;
			ee[++ec]=e[i];++D[e[i].f],++D[e[i].t];
		}
	}
	G[1]=pool;for(int i=1;i<=n;i++)G[i+1]=G[i]+D[i];
	for(int i=1;i<=ec;i++){
		G[ee[i].f][--D[ee[i].f]]=ee[i].t;
		G[ee[i].t][--D[ee[i].t]]=ee[i].f;
	}
	dfs(1,0);
	int c1=0,c2=0;int lm=(n*2+k-1)/k;
	for(int i=1;i<=ettc;i++){
		c2++;
		if(c2==lm||i==ettc){
			c1++;
			printf("%d ",c2);
			for(int j=1;j<=c2;j++)printf("%d ",ett[i-c2+j]);
			printf("\n");
			c2=0;
		}
	}
	while(c1<k)printf("1\n1\n"),c1++;
	return 0;
}