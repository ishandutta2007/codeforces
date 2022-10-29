#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 205
#define ll long long 
#define mo 1000000007
using namespace std;

int n,i,j,k;
int em,e[maxn*2],nx[maxn*2],ls[maxn];
ll ans,inv[maxn];

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

int lca[maxn][maxn],sz[maxn],dep[maxn],fa[maxn],d[maxn];
void dfs(int x,int p){
	fa[x]=p,dep[x]=dep[p]+1,d[++d[0]]=x,sz[x]=1;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
		dfs(e[i],x),sz[x]+=sz[e[i]];
}

ll f[maxn][maxn],g[maxn][maxn];

int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++) scanf("%d%d",&j,&k),insert(j,k);
	inv[0]=1;for(i=1;i<=n;i++) inv[i]=ksm(i,mo-2);
	f[0][0]=1;
	for(i=0;i<=n;i++) for(j=0;j<=n;j++){
		if (i) (f[i][j]+=f[i-1][j]*inv[2])%=mo;
		if (j) (f[i][j]+=f[i][j-1]*inv[2])%=mo;
	}
	for(i=1;i<=n;i++) for(j=1;j<=n-i;j++) for(k=0;k<j;k++) 
		(g[i][j]+=f[i-1][k]*inv[2])%=mo;
	for(int rt=1;rt<=n;rt++){
		d[0]=0,dfs(rt,0);
		for(i=1;i<=n;i++) for(j=1;j<=n;j++){
			int x=d[i],y=d[j];
			if (x==y) lca[x][y]=x; else {
				if (dep[x]>dep[y]) lca[x][y]=lca[fa[x]][y];
				else lca[x][y]=lca[x][fa[y]];
			}
		}
		for(i=1;i<=n;i++) for(j=i+1;j<=n;j++) {
			if (lca[i][j]==j) ans++; else 
			if (lca[i][j]!=i){
				int x=dep[i]-dep[lca[i][j]],y=dep[j]-dep[lca[i][j]];
				(ans+=g[y][x])%=mo;
			}
		}
	}
	printf("%lld\n",ans%mo*inv[n]%mo);
}