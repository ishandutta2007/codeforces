#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#define maxn 300005
#define ll long long
using namespace std;

int n,i,j,k,a[maxn],fa[maxn],p[maxn],b[maxn];
int em,e[maxn],nx[maxn],ls[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
}

int L[maxn],R[maxn],dep[maxn];
vector<int> E[maxn];
int cmp(int i,int j){return L[i]<L[j];}
void dfs(int x){
	L[x]=R[x]=a[x];
	for(int i=ls[x];i;i=nx[i]) {
		dep[e[i]]=dep[x]+1,dfs(e[i]),E[x].push_back(e[i]);
		L[x]=min(L[x],L[e[i]]),R[x]=max(R[x],R[e[i]]);
	}
	sort(E[x].begin(),E[x].end(),cmp);
	for(int i=1;i<E[x].size();i++) if (L[E[x][i]]<R[E[x][i-1]])
		printf("NO\n"),exit(0);
}
int dfn[maxn],dfn0[maxn];
void dfs2(int x){
	dfn[x]=++dfn[0];
	for(int i=0;i<E[x].size();i++) 
		dfs2(E[x][i]);
	dfn0[x]=++dfn0[0];
}
int now;
void dfs3(int x,int p){
	if (a[x]>now){
		if (a[x]<p) 
			printf("NO\n"),exit(0);
		p=a[x];
	}
	for(int i=0;i<E[x].size();i++) 
		dfs3(E[x][i],p);
}

int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),p[a[i]]=i;
	for(i=1;i<n;i++){
		scanf("%d%d",&j,&k);
		fa[k]=j,insert(j,k);
	}
	dfs(1);
	dfs2(1);
	ll ans=0;
	for(now=1;now<=n;now++){
		int x=p[now],tp=0; ans+=dep[x];
		for(i=ls[x];i;i=nx[i]) if (a[e[i]]>a[x]) tp=1;
		if (tp) break;
		if (dfn0[x]!=now) printf("NO\n"),exit(0); 
	}
	dfs3(1,0);
	printf("YES\n");
	printf("%lld\n",ans);
	for(i=1;i<=n;i++) printf("%d ",dfn[i]);
}