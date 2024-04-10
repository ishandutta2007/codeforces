#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define maxp 20
using namespace std;

int n,m,q,i,j,k,tot,dfn[maxn],low[maxn],d[maxn],fr[maxn],cnt,id[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn],bz[maxn*2];
int Em,E[maxn*2],Nx[maxn*2],Ls[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

void Insert(int x,int y){
	Em++; E[Em]=y; Nx[Em]=Ls[x]; Ls[x]=Em;
	Em++; E[Em]=x; Nx[Em]=Ls[y]; Ls[y]=Em;
}

void tarjan(int x){
	dfn[x]=low[x]=++tot,d[++d[0]]=x;
	for(int i=ls[x];i;i=nx[i]) if (!bz[i]){
		bz[i]=bz[i^1]=1;
		if (!dfn[e[i]]) tarjan(e[i]); 
		low[x]=min(low[x],low[e[i]]);
	}
	if (low[x]==dfn[x]){
		cnt++;
		while (d[d[0]]!=x) fr[d[d[0]]]=cnt,d[0]--;
		fr[x]=cnt,d[0]--;
	}
}

int fa[maxn][maxp],f[maxn],g[maxn],dep[maxn];
void dfs(int x,int p){
	fa[x][0]=p,dep[x]=dep[p]+1,id[x]=id[0];
	for(int i=1;i<maxp;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=Ls[x];i;i=Nx[i]) if (E[i]!=p)
		dfs(E[i],x);
}

int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for(int i=maxp-1;i>=0;i--) if (dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	if (x==y) return x;
	for(int i=maxp-1;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

//int father(int x){
//	if (f[x]==x) return x;
//	if (g[f[x]]==g[x]) return f[x]=father(f[x]);
//	return f[x];
//}
//
//void cover(int x,int z,int t){
//	while (dep[x]>dep[z]){
//		if (f[x]!=x) {
//			if (g[x]!=t) printf("No\n"),exit(0);
//			else {
//				x=father(x);
//				if (dep[x]<=dep[z]) return;
//				if (g[x]) printf("No\n"),exit(0);
//			}
//		}
//		f[x]=fa[x][0],g[x]=t,x=father(x);
//	}
//}

int c[maxn][2];
void check(int x,int p){
	for(int i=Ls[x];i;i=Nx[i]) if (E[i]!=p)
		check(E[i],x),c[x][0]+=c[E[i]][0],c[x][1]+=c[E[i]][1];
	if (x>1&&c[x][0]>0&&c[x][1]>0)
		printf("No"),exit(0);
}

int main(){
	scanf("%d%d%d",&n,&m,&q),em=1;
	for(i=1;i<=m;i++) scanf("%d%d",&j,&k),insert(j,k);
	for(i=1;i<=n;i++) if (!dfn[i]) tarjan(1);
	for(int x=1;x<=n;x++) for(i=ls[x];i;i=nx[i]) if (fr[x]<fr[e[i]])
		Insert(fr[x],fr[e[i]]);
	for(i=1;i<=cnt;i++) if (!fa[i][0]) id[0]++,dfs(i,0);
	for(i=1;i<=cnt;i++) f[i]=i,g[i]=0;
	while (q--){
		int x,y,z; scanf("%d%d",&x,&y),x=fr[x],y=fr[y];
		if (id[x]!=id[y]) printf("No\n"),exit(0);
		if (x==y) continue; z=lca(x,y);
		c[x][0]++,c[z][0]--,c[y][1]++,c[z][1]--;
//		cover(x,z,1),cover(y,z,2);
	}
	check(1,0);
	printf("Yes\n");
}