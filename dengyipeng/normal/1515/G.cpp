#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
#define ll long long 
using namespace std;

int n,m,i,j,k;
int em,e[maxn],nx[maxn],ls[maxn],ec[maxn];
ll gcd(ll x,ll y){return (!y)?x:gcd(y,x%y);}

void insert(int x,int y,int z){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em; ec[em]=z;
}

int fr[maxn],d[maxn],w,vis[maxn],tot,dfn[maxn],low[maxn];
void tarjan(int x){
	d[++w]=x,vis[x]=1,dfn[x]=low[x]=++tot;
	for(int i=ls[x];i;i=nx[i]) {
		int y=e[i];
		if (!dfn[y]) tarjan(y),low[x]=min(low[x],low[y]);
		else if (vis[y]) low[x]=min(low[x],low[y]);
	}
	if (low[x]==dfn[x]){
		while (d[w]!=x) 
			vis[d[w]]=0,fr[d[w--]]=x;
		vis[x]=0,fr[x]=x,w--;
	}
}

ll dep[maxn],g[maxn];
void dfs(int x){
	vis[x]=1;
	for(int i=ls[x];i;i=nx[i]) if (fr[e[i]]==fr[x]){
		if (vis[e[i]]) 
			g[fr[x]]=gcd(g[fr[x]],dep[x]-dep[e[i]]+ec[i]);
		else dep[e[i]]=dep[x]+ec[i],dfs(e[i]);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		insert(x,y,z);
	}
	for(i=1;i<=n;i++) if (!fr[i]) tarjan(i);
	for(i=1;i<=n;i++) if (fr[i]==i) dfs(i);
	int q; scanf("%d",&q);
	while (q--){
		int v,s,t; scanf("%d%d%d",&v,&s,&t);
		if (s%gcd(g[fr[v]],t)==0)
			printf("YES\n"); else printf("NO\n");
	}
}