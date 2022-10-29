#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define ll long long 
using namespace std;

int T,n,i,j,k,a[maxn],b[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn];
ll f[maxn][2];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

void dfs(int x,int p){
	f[x][0]=f[x][1]=0;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p){
		int y=e[i]; dfs(y,x);
		f[x][0]+=max(f[y][0]+abs(a[x]-a[y]),f[y][1]+abs(a[x]-b[y]));
		f[x][1]+=max(f[y][0]+abs(b[x]-a[y]),f[y][1]+abs(b[x]-b[y]));
	}
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		em=0,memset(ls,0,sizeof(int)*(n+1));
		for(i=1;i<n;i++) scanf("%d%d",&j,&k),insert(j,k);
		dfs(1,0);
		printf("%lld\n",max(f[1][0],f[1][1]));
	}
}