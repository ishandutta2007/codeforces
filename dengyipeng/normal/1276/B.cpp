#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define maxm 500005
#define I(x) ((i&1)?i+1:i-1)
using namespace std;

int T,n,m,i,j,k,x,y,a,b;
int em,e[maxm*2],nx[maxm*2],ls[maxn],used[maxm*2];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em; used[em]=0;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em; used[em]=0;
}

int tot;
int em0,e0[maxm*4],nx0[maxm*4],ls0[maxn*2];
void insert0(int x,int y){
	em0++; e0[em0]=y; nx0[em0]=ls0[x]; ls0[x]=em0;
	em0++; e0[em0]=x; nx0[em0]=ls0[y]; ls0[y]=em0;
}

int vis[maxn],d[maxn],low[maxn],dfn[maxn],totd;
void dfs(int x){
	vis[x]=1,low[x]=dfn[x]=++totd,d[++d[0]]=x;
	for(int i=ls[x];i;i=nx[i]) if (!used[i]){
		used[i]=used[I(i)]=1;
		if (vis[e[i]]) low[x]=min(low[x],dfn[e[i]]);
		else {
			dfs(e[i]);
			low[x]=min(low[x],low[e[i]]);
			if (low[e[i]]>=dfn[x]) {
				++tot,ls0[tot]=0;
				while (1) {
					insert0(d[d[0]],tot),d[0]--;
					if (d[d[0] + 1] == e[i]) break;
				}
				insert0(x,tot);
			}
		}
	}
}

int sz[maxn*2],fa[maxn*2];
void dfs0(int x,int p){
	sz[x]=x<=n,fa[x]=p;
	for(int i=ls0[x];i;i=nx0[i]) if (e0[i]!=p)
		dfs0(e0[i],x),sz[x]+=sz[e0[i]];
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d%d",&n,&m,&a,&b);
		em=em0=0,tot=n,totd=0,d[0]=0;
		for(i=1;i<=n;i++) {
			ls[i]=ls0[i]=0;
			vis[i]=dfn[i]=low[i]=0;
		}
		for(i=1;i<=m;i++) 
			scanf("%d%d",&x,&y),insert(x,y);
		dfs(1);
		dfs0(a,0);
		for(k=b;fa[k]!=a;k=fa[k]);
		printf("%lld\n",1ll*(sz[b]-1)*(n-sz[k]-1));
	}
}