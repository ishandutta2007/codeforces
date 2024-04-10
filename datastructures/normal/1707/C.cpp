#include <iostream>
#include <cstdio>
using namespace std;
int n,m,x[200005],y[200005],qwq[200005];
int dsu[100005];
int totm,u[200005],v[200005],first[200005],nxt[200005];
void add_edge(int a,int b){
	int i=++totm;
	u[i]=a,v[i]=b;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
int dsu_find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=dsu_find(dsu[x]);
}
int fa[100005][25],depth[100005];
int idx,dfn[100005],dfo[100005];
void dfs(int now,int f,int d){
	fa[now][0]=f;
	for (int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	depth[now]=d;
	dfn[now]=++idx;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs(v[i],now,d+1);
	dfo[now]=idx;
	return;
}
int in(int a,int b){//whether a is in b
	if (dfn[a]>=dfn[b]&&dfo[a]<=dfo[b])return 1;
	return 0;	
}
int ch[100005];
void add(int x,int y){
	if (depth[x]>depth[y])swap(x,y);
	if (in(y,x)){
		ch[dfn[y]]++,ch[dfo[y]+1]--;
		for (int i=20;i>=0;i--)
			if (depth[fa[y][i]]>depth[x])y=fa[y][i];
		ch[1]++,ch[dfn[y]]--;
		ch[dfo[y]+1]++,ch[n+1]--; 
		return;
	}
	ch[dfn[x]]++,ch[dfo[x]+1]--;
	ch[dfn[y]]++,ch[dfo[y]+1]--; 
	return;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)dsu[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		if (dsu_find(x[i])==dsu_find(y[i]))qwq[i]=1;
		else{
			add_edge(x[i],y[i]),add_edge(y[i],x[i]);
			dsu[dsu_find(x[i])]=dsu_find(y[i]);
		}
	}
	dfs(1,0,1);
	int cnt=0;
	for (int i=1;i<=m;i++)
		if (qwq[i]==1)cnt++,add(x[i],y[i]);
	for (int i=1;i<=n;i++)ch[i]+=ch[i-1];
	for (int i=1;i<=n;i++)
		if (ch[dfn[i]]==cnt)putchar('1');
		else putchar('0');
	putchar('\n');
	return 0;
}