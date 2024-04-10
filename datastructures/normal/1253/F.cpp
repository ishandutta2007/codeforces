#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define int long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,m,k,q;
int a[1000005],b[1000005],c[1000005];
vector<int> e_id[100005],e_val[100005];
struct dis_node{
	int id,dis;
	bool operator <(const dis_node &x)const{
		return x.dis<dis;
	}
};
dis_node make_dis_node(int id,int dis){
	dis_node x;
	x.id=id,x.dis=dis;
	return x;
}
int dis[1000005],book[100005];
struct edge_node{
	int u,v,w;
	bool operator <(const edge_node &x)const{
		return w<x.w;
	}
}e[1000005];
priority_queue<dis_node> h;
void dijkstra(){
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	h.push(make_dis_node(0,0));
	while(!h.empty()){
		int now=(h.top()).id;
		h.pop();
		if (book[now]==1)continue;
		book[now]=1;
		for (int i=0;i<e_id[now].size();i++){
			int v=e_id[now][i],w=e_val[now][i];
			if (dis[v]>dis[now]+w){
				dis[v]=dis[now]+w;
				h.push(make_dis_node(v,dis[v]));
			}
		}
	}
	return;
}
int dsu[100005];
int dsu_find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=dsu_find(dsu[x]);
}
int totm,u[1000005],v[1000005],w[1000005],first[1000005],nxt[1000005];
void add_edge(int a,int b,int c){
	int i=++totm;
	u[i]=a,v[i]=b,w[i]=c;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
int depth[100005],fa[100005][25],st[100005][25];
void dfs(int now,int f,int d){
	fa[now][0]=f,depth[now]=d;
	for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1],st[now][i]=max(st[now][i-1],st[fa[now][i-1]][i-1]);
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f)st[v[i]][0]=w[i],dfs(v[i],now,d+1);
	return;
}
int lca(int a,int b){
	if (depth[a]<depth[b])swap(a,b);
	for (int i=20;i>=0;i--)
		if (depth[fa[a][i]]>=depth[b])a=fa[a][i];
	if (a==b)return a;
	for (int i=20;i>=0;i--)
		if (fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
int ask(int a,int b){
	int c=lca(a,b),ans=0;
	for (int i=20;i>=0;i--)
		if (depth[fa[a][i]]>=depth[c])ans=max(ans,st[a][i]),a=fa[a][i];
	for (int i=20;i>=0;i--)
		if (depth[fa[b][i]]>=depth[c])ans=max(ans,st[b][i]),b=fa[b][i];
	return ans;
}
signed main(){
	n=read(),m=read(),k=read(),q=read();
	for (int i=1;i<=m;i++){
		int x,y,z;
		x=read(),y=read(),z=read();
		a[i]=x,b[i]=y,c[i]=z;
		e_id[x].push_back(y),e_val[x].push_back(z);
		e_id[y].push_back(x),e_val[y].push_back(z);
	}
	for (int i=1;i<=k;i++)e_id[0].push_back(i),e_val[0].push_back(0);
	dijkstra();
	for (int i=1;i<=m;i++)e[i].u=a[i],e[i].v=b[i],e[i].w=dis[a[i]]+c[i]+dis[b[i]];
	sort(e+1,e+1+m);
	for (int i=1;i<=n;i++)dsu[i]=i;
	for (int i=1;i<=m;i++){
		int x=dsu_find(e[i].u),y=dsu_find(e[i].v),z=e[i].w;
		if (x==y)continue;
		dsu[x]=y;
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	dfs(1,0,1);
	while(q--){
		int x,y;
		x=read(),y=read();
		printf("%lld\n",ask(x,y));
	}
	return 0;
}