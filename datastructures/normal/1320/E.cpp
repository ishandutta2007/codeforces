#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define inf 1000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,q,u[500005],v[500005],first[500005],nxt[500005],k,m,c[500005],s[500005],d[500005];
int fa[500005],depth[500005],sz[500005],son[500005],idx,dfn[500005],dfo[500005],top[500005];
int qwq[500005],awa,col[500005],ask_id[500005],ans[500005];
int sta[500005],tot;
vector<int> e[500005],w[500005];
void dfs1(int now,int f,int d){
	fa[now]=f,depth[now]=d;
	sz[now]=1;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		dfs1(v[i],now,d+1);
		sz[now]+=sz[v[i]];
		if (sz[v[i]]>sz[son[now]])son[now]=v[i];
	}
	return;
}
void dfs2(int now,int f,int t){
	++idx;
	dfn[now]=idx;
	top[now]=t;
	if (son[now]!=0)dfs2(son[now],now,t);
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f||v[i]==son[now])continue;
		dfs2(v[i],now,v[i]);
	}
	dfo[now]=idx;
	return;
}
int lca(int a,int b){
	while(top[a]!=top[b]){
		if (depth[top[a]]<depth[top[b]])swap(a,b);
		a=fa[top[a]];
	}
	if (depth[a]>depth[b])return b;
	return a;
}
bool in(int a,int b){//whether A is in B
	if (dfn[a]>=dfn[b]&&dfn[a]<=dfo[b])return 1;
	return 0;
}
int del_sta[500005],del_tot;
void add(int a,int b){
	del_sta[++del_tot]=a;
	e[a].push_back(b);
	w[a].push_back(depth[b]-depth[a]);
	return;
}
bool cmp(int a,int b){
	return dfn[a]<dfn[b];
}
void build(){
	sort(qwq+1,qwq+1+awa,cmp);
	tot=0;
	for (int i=1;i<=awa;i++){
		if (i>1&&qwq[i]==qwq[i-1])continue;
		int now=qwq[i];
		while(tot>1&&(!in(now,sta[tot]))){
			int qaq=lca(now,sta[tot]);
			if (depth[qaq]<=depth[sta[tot-1]]){
				add(sta[tot-1],sta[tot]);
				tot--;
			}
			else{
				add(qaq,sta[tot]);
				sta[tot]=qaq;
			}
		}
		sta[++tot]=now;
	}
	while(tot>1)add(sta[tot-1],sta[tot]),tot--;
	return;
}
int f1[500005],g1[500005],f2[500005],g2[500005];
int ask_t(int dis,int id){
	return (dis+s[id]-1)/s[id];
}
struct node{
	int v,dis,t,id;
	bool operator <(const node &x)const{
		if (t!=x.t)return t<x.t;
		return id<x.id;
	}
}a[500005];
node make_node(int v,int dis,int t,int id){
	node ans;
	ans.v=v,ans.dis=dis,ans.t=t,ans.id=id;
	return ans;
}
int len;
void dfs3(int now){
	for (int i=0;i<e[now].size();i++)dfs3(e[now][i]);
	if (col[now]!=0){
		f1[now]=col[now],g1[now]=0;
		return;
	}
	len=0;
	for (int i=0;i<e[now].size();i++){
		int id=f1[e[now][i]];
		if (id==0)continue;
		int dis=g1[e[now][i]]+w[now][i];
		a[++len]=make_node(e[now][i],dis,ask_t(dis,id),id);
	}
	sort(a+1,a+1+len);
	if (len==0)f1[now]=0,g1[now]=0;
	else{
		f1[now]=a[1].id;
		g1[now]=a[1].dis;
	}
	return;
}
void dfs4(int now){
	len=0;
	for (int i=0;i<e[now].size();i++){
		int id=f1[e[now][i]];
		if (id==0)continue;
		int dis=g1[e[now][i]]+w[now][i];
		a[++len]=make_node(e[now][i],dis,ask_t(dis,id),id);
	}
	if (f2[now]!=0)a[++len]=make_node(0,g2[now],ask_t(g2[now],f2[now]),f2[now]);
	if (col[now]!=0)a[++len]=make_node(0,0,0,col[now]);
	sort(a+1,a+1+len);
	if (ask_id[now]!=0)ans[ask_id[now]]=a[1].id;
	for (int i=0;i<e[now].size();i++){
		if (e[now][i]==a[1].v){
			if (len==1)f2[e[now][i]]=0,g2[e[now][i]]=0;
			else f2[e[now][i]]=a[2].id,g2[e[now][i]]=a[2].dis+w[now][i];
		}
		else f2[e[now][i]]=a[1].id,g2[e[now][i]]=a[1].dis+w[now][i];
	}
	for (int i=0;i<e[now].size();i++)dfs4(e[now][i]);
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<n;i++){
		u[i]=read(),v[i]=read();
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs1(1,0,1);
	dfs2(1,0,1);
	cin>>q;
	while(q--){
		k=read(),m=read();
		qwq[++awa]=1;
		for (int i=1;i<=k;i++){
			c[i]=read(),s[i]=read();
			col[c[i]]=i;
			qwq[++awa]=c[i];
		}
		for (int i=1;i<=m;i++){
			d[i]=read();
			ask_id[d[i]]=i;
			qwq[++awa]=d[i];
		}
		build();
		dfs3(1);
		dfs4(1);
		for (int i=1;i<=m;i++)printf("%d ",ans[i]);
		printf("\n");
		awa=0;
		for (int i=1;i<=del_tot;i++)e[del_sta[i]].clear(),w[del_sta[i]].clear();
		del_tot=0;
		for (int i=1;i<=k;i++)col[c[i]]=0;
		for (int i=1;i<=m;i++)ask_id[d[i]]=0;
	}
	return 0;
}