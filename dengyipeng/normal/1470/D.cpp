#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 300005
using namespace std;

int T,n,m,i,j,k,vis[maxn],bz[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

void dfs(int x){
	vis[x]=1,bz[x]=1;
	for(int i=ls[x];i;i=nx[i]) if (bz[e[i]]){bz[x]=0;break;}
	for(int i=ls[x];i;i=nx[i]) if (!vis[e[i]])
		dfs(e[i]);
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m),em=0;
		for(i=1;i<=n;i++) ls[i]=vis[i]=bz[i]=0;
		for(i=1;i<=m;i++) scanf("%d%d",&j,&k),insert(j,k);
		dfs(1);
		int tp=1;
		for(i=1;i<=n;i++) if (!vis[i]){tp=0;break;}
		if (!tp) printf("NO\n"); else {
			int cnt=0;
			for(i=1;i<=n;i++) cnt+=bz[i];
			printf("YES\n%d\n",cnt);
			for(i=1;i<=n;i++) if (bz[i]) printf("%d ",i);
			printf("\n");
		}
	}
}