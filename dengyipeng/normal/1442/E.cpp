#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 200005
using namespace std;

int T,n,i,j,k,a[maxn],E[maxn][2],fa[maxn];
int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}
void link(int x,int y){
	x=father(x),y=father(y);
	if (x!=y) fa[x]=y;
}

int em,e[maxn*2],nx[maxn*2],ls[maxn];
void insert(int x,int y){
	if (father(x)!=father(y)){
		x=fa[x],y=fa[y];
		em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
		em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
	}
}

int rt,rt0,mx;
void dfs(int x,int p,int s,int pre){
	if (a[x]!=0){
		if (pre!=a[x]) s++;
		pre=a[x];
	}
	if (s>mx) mx=s,rt0=x;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
		dfs(e[i],x,s,pre);
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		em=0,memset(ls,0,sizeof(int)*(n+1));
		for(i=1;i<=n;i++) scanf("%d",&a[i]),fa[i]=i;
		for(i=1;i<n;i++){
			scanf("%d%d",&E[i][0],&E[i][1]);
			if (a[E[i][0]]==a[E[i][1]]) link(E[i][0],E[i][1]);
		}
		for(i=1;i<n;i++) insert(E[i][0],E[i][1]);
		for(i=1;i<=n;i++) if (fa[i]==i) rt=i;
		rt0=mx=-1;
		dfs(rt,0,0,0);
		mx=0;
		dfs(rt0,0,0,0);
		if (mx<=1) printf("1\n"); else
			printf("%d\n",mx/2+1);
	}
}