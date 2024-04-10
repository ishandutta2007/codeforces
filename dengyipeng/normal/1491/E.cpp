#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 200005
using namespace std;

int n,i,j,k,f[maxn],m,bz[maxn*2],sz[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

int id,K,fai[maxn],id0,fa[maxn];
void dfs(int x,int p){
	sz[x]=1,fa[x]=p;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p&&!bz[i])	
		fai[e[i]]=i,dfs(e[i],x),sz[x]+=sz[e[i]];
	if (sz[x]==f[K-1]||sz[x]==f[K-2]) id=x,id0=fai[x];
}

void dg(int x,int k){
	if (k<=1) return;
	id=0,K=k,dfs(x,0);
	if (!id) printf("NO\n"),exit(0);
	bz[id0]=bz[id0^1]=1;
	int y=fa[id],t=(sz[id]==f[k-1])?(k-1):(k-2);
	dg(id,t);
	dg(y,k-1+k-2-t);
}

int main(){
	scanf("%d",&n),em=1;
	for(i=1;i<n;i++) scanf("%d%d",&j,&k),insert(j,k);
	f[0]=f[1]=1,m=1;
	while (f[m]<n)
		m++,f[m]=f[m-1]+f[m-2];
	if (f[m]!=n) printf("NO\n"),exit(0);
	dg(1,m);
	printf("YES\n");
}