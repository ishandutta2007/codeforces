#include<bits/stdc++.h>
#define ll long long
#define MAX_N 5010
using namespace std;
struct edge {
	int v,w,next;
} e[MAX_N<<1];
int eid,p[MAX_N<<1];
void insert(int u,int v,int w) {
	e[++eid]= {v,w,p[u]};
	p[u]=eid;
}
int ans[MAX_N];
bool vis[MAX_N],fa[MAX_N];
void dfs(int u) {
	vis[u]=1,fa[u]=1;
	for(register int i=p[u]; i; i=e[i].next) {
		int v=e[i].v;
		if(fa[v])
			ans[e[i].w]=2;
		else {
			ans[e[i].w]=1;
			if(!vis[v])
				dfs(v);
		}
	}
	fa[u]=0;
}
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	for(register int i=1; i<=m; ++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v,i);
	}
	for(register int i=1; i<=n; ++i)
		if(!vis[i])dfs(i);
	bool flag=0;
	for(register int i=2; i<=m; ++i)if(ans[i]!=ans[i-1])flag=1;
	cout<<flag+1<<endl;
	if(flag)
		for(register int i=1; i<=m; ++i)printf("%d ",ans[i]);
	else for(register int i=1; i<=m; ++i)printf("1 ");
	return 0;
}