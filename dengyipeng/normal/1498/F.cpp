#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100005
#define maxp 40
#define ll long long 
using namespace std;

int n,i,j,k,K,a[maxn],L;
int em,e[maxn*2],nx[maxn*2],ls[maxn];
int f[maxn][maxp],g[maxn][maxp];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

void dfs(int x,int p){
	f[x][0]=a[x];
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p){
		dfs(e[i],x);
		for(int j=0;j<L;j++)
			f[x][(j+1)%L]^=f[e[i]][j];
	}
}

int ans[maxn];
void dfs2(int x,int p){
	for(int i=K;i<L;i++) ans[x]^=f[x][i]^g[x][i];
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p){
		int y=e[i];
		for(int j=0;j<L;j++) g[y][(j+1)%L]^=g[x][j]^f[x][j];
		for(int j=0;j<L;j++) g[y][(j+2)%L]^=f[y][j];
		dfs2(e[i],x);
	}
}

int main(){
	scanf("%d%d",&n,&K),L=2*K;
	for(i=1;i<n;i++) scanf("%d%d",&j,&k),insert(j,k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0),dfs2(1,0);
	for(i=1;i<=n;i++) printf("%d ",ans[i]>0);
}