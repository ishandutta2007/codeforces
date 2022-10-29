#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
using namespace std;

int T,n,i,j,k,f[maxn],g[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

int cnt;
void dfs(int x,int p){
	f[x]=g[x]=0; int tp=1;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
		dfs(e[i],x),f[x]+=f[e[i]],g[x]+=(g[e[i]]==0);
	if (g[x]) f[x]++,cnt+=g[x];
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		em=0,memset(ls,0,sizeof(int)*(n+1));
		for(i=1;i<n;i++) scanf("%d%d",&j,&k),insert(j,k);
		cnt=0,dfs(1,0);
		f[1]-=(g[1]>0);
		if (g[1]) printf("%d\n",cnt-f[1]);
		else printf("%d\n",cnt-f[1]+1);
	}
}