#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,p[200005],q[200005],u[200005],v[200005],first[200005],nxt[200005];
int fa[200005],depth[200005],sz[200005],son[200005],idx,dfn[200005],dfo[200005],top[200005];
int t,opt,x,y;
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
	dfn[now]=++idx;
	top[now]=t;
	if (son[now]!=0)dfs2(son[now],now,t);
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f&&v[i]!=son[now])dfs2(v[i],now,v[i]);
	dfo[now]=idx;
	return;
}
int lca(int a,int b){
	while(top[a]!=top[b]){
		if (depth[top[a]]<depth[top[b]])swap(a,b);
		a=fa[top[a]];
	}
	if (depth[b]<depth[a])return b;
	return a; 
}
bool in(int a,int b){//whether A is in B
	return ((dfn[a]>=dfn[b])&&(dfn[a]<=dfo[b]));
}
struct node{
	int x,y,fg;
	node(){
		x=y=0;
		fg=-1;
		return;
	}
}tree[1000005];
int id[5],sta1[5],tot1,sta2[5],tot2;
bool cmp(int a,int b){
	return dfn[a]<dfn[b];
}
node merge(node a,node b){
	if (a.fg==-1)return b;
	if (b.fg==-1)return a;
	node c;
	if (a.fg==0||b.fg==0){
		c.x=c.y=0;
		c.fg=0;
		return c;
	}
	int fg=1;
	id[1]=a.x,id[2]=a.y,id[3]=b.x,id[4]=b.y;
	sort(id+1,id+5,cmp);
	tot1=tot2=0;
	for (int i=1;i<=4;i++){
		if (i>1&&id[i]==id[i-1])continue;
		if (tot1==0||in(id[i],sta1[tot1]))sta1[++tot1]=id[i];
		else if (tot2==0||in(id[i],sta2[tot2]))sta2[++tot2]=id[i];
		else fg=0;
	}
	if (tot1>1&&tot2>0&&depth[lca(sta1[2],sta2[1])]>depth[sta1[1]])fg=0;
	if (fg==0){
		c.x=c.y=0;
		c.fg=0;
		return c;
	}
	c.fg=1;
	if (tot2==0)c.x=sta1[1],c.y=sta1[tot1];
	else c.x=sta1[tot1],c.y=sta2[tot2];
	return c;
}
void pushup(int now){
	tree[now]=merge(tree[now*2],tree[now*2+1]);
	return;
}
void build(int now,int nowl,int nowr){
	if (nowl==nowr){
		tree[now].fg=1;
		tree[now].x=tree[now].y=q[nowl];
		return;
	}
	int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid);
	build(now*2+1,mid+1,nowr);
	pushup(now);
	return;
}
void upd(int now,int nowl,int nowr,int pos){
	if (nowl==nowr){
		tree[now].fg=1;
		tree[now].x=tree[now].y=q[pos];
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)upd(now*2,nowl,mid,pos);
	else upd(now*2+1,mid+1,nowr,pos);
	pushup(now);
	return;
}
node qwq;
int find(int now,int nowl,int nowr){
	if (nowl==nowr){
		qwq=merge(qwq,tree[now]);
		if (qwq.fg==0)return nowl-1;
		return nowl;
	}
	node awa=merge(qwq,tree[now*2]);
	int mid=(nowl+nowr)/2;
	if (awa.fg!=0){
		qwq=awa;
		return find(now*2+1,mid+1,nowr);
	}
	return find(now*2,nowl,mid); 
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>p[i];
		p[i]++;
		q[p[i]]=i;
	}
	for (int i=2;i<=n;i++){
		cin>>u[i];
		v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	dfs1(1,0,1);
	dfs2(1,0,1);
	build(1,1,n);
	cin>>t;
	while(t--){
		cin>>opt;
		if (opt==1){
			cin>>x>>y;
			swap(q[p[x]],q[p[y]]);
			upd(1,1,n,p[x]);
			upd(1,1,n,p[y]);
			swap(p[x],p[y]);
		}
		if (opt==2){
			qwq.fg=-1;
			cout<<find(1,1,n)<<endl;
		}
	}
	return 0;
}