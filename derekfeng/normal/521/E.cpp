#include<bits/stdc++.h>
using namespace std;
int n,m,d[200004],p[200004];
vector<int>g[200004];
bool vis[200004],ins[200004];
int a[200004],cnt,cx[200004],cy[200004];
int lca(int u,int v){
	if(d[u]>d[v])swap(u,v);
	while(d[v]>d[u])v=p[v];
	while(v!=u)u=p[u],v=p[v];
	return u;
}
void add(int u,int v){
	while(u!=v)a[++cnt]=u,u=p[u];
	a[++cnt]=v;
}
void out(){
	printf("%d ",cnt);
	for(int i=1;i<=cnt;i++)printf("%d ",a[i]);
	puts("");
}
void get(int A,int B,int C,int D){
	if(d[B]>d[D])swap(A,C),swap(B,D);
	int L=lca(A,C);
	puts("YES");
	add(L,D);reverse(a+1,a+1+cnt);
	out();
	cnt=0,add(D,B),add(A,L);
	out();
	cnt=0,add(D,D),add(C,L);
	out();
	exit(0);
}
void dfs(int x){
	d[x]=d[p[x]]+1;
	vis[x]=ins[x]=1;
	for(auto y:g[x])if(y!=p[x]){
		if(!vis[y])p[y]=x,dfs(y);
		else if(ins[y]){
			for(int i=x;i!=y;i=p[i]){
				if(cx[i]&&cy[i])get(cx[i],cy[i],x,y);
				else cx[i]=x,cy[i]=y;
			}
		}
	}
	ins[x]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
	puts("NO");
}