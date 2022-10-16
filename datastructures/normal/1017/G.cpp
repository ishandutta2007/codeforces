#include <iostream>
#include <cstdio>
#define inf 1000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,q,opt,x;
int fa[100005],u[100005],v[100005],first[100005],nxt[100005];
int depth[100005],sz[100005],son[100005],top[100005],idx,dfn[100005],dfo[100005],nfd[100005];
void dfs1(int now,int d){
	depth[now]=d;
	sz[now]=1;
	for (int i=first[now];i;i=nxt[i]){
		dfs1(v[i],d+1);
		sz[now]+=sz[v[i]];
		if (sz[v[i]]>sz[son[now]])son[now]=v[i];
	}
	return;
}
void dfs2(int now,int t){
	top[now]=t;
	++idx;
	dfn[now]=idx;
	nfd[idx]=now;
	if (son[now]!=0)dfs2(son[now],t);
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=son[now])dfs2(v[i],v[i]);
	dfo[now]=idx;
	return;
}
int mxd[400005],tree[400005],tag1[400005],tag2[400005];//tag1:cover tag2:add (tag1 first)
void pushdown(int now){
	if (tag1[now]!=0){
		tree[now*2]=-mxd[now*2];
		tree[now*2+1]=-mxd[now*2+1];
		tag1[now*2]=1;
		tag1[now*2+1]=1;
		tag2[now*2]=0;
		tag2[now*2+1]=0;
		tag1[now]=0;
	}
	if (tag2[now]!=0){
		tree[now*2]+=tag2[now];
		tree[now*2+1]+=tag2[now];
		tag2[now*2]+=tag2[now];
		tag2[now*2+1]+=tag2[now];
		tag2[now]=0;
		return;
	}
	return;
}
void pushup(int now){
	tree[now]=min(tree[now*2],tree[now*2+1]);
	return;
}
void upd1(int now,int nowl,int nowr,int lt,int rt){//cover
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]=-mxd[now];
		tag1[now]=1;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)upd1(now*2,nowl,mid,lt,rt);
	if (mid+1<=rt)upd1(now*2+1,mid+1,nowr,lt,rt);
	pushup(now);
	return;
}
void upd2(int now,int nowl,int nowr,int lt,int rt,int val){//add
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt){
		tree[now]+=val;
		tag2[now]+=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (mid>=lt)upd2(now*2,nowl,mid,lt,rt,val);
	if (mid+1<=rt)upd2(now*2+1,mid+1,nowr,lt,rt,val);
	pushup(now);
	return;
}
int ask(int now,int nowl,int nowr,int lt,int rt){
	if (nowl!=nowr)pushdown(now);
	if (nowl>=lt&&nowr<=rt)return tree[now];
	int mid=(nowl+nowr)/2,s=inf;
	if (mid>=lt)s=min(s,ask(now*2,nowl,mid,lt,rt));
	if (mid+1<=rt)s=min(s,ask(now*2+1,mid+1,nowr,lt,rt));
	return s;
}
void build(int now,int nowl,int nowr){
	if (nowl==nowr){
		mxd[now]=depth[nfd[nowl]];
		tree[now]=-mxd[now];
		return;
	}
	int mid=(nowl+nowr)/2;
	build(now*2,nowl,mid);
	build(now*2+1,mid+1,nowr);
	mxd[now]=max(mxd[now*2],mxd[now*2+1]);
	tree[now]=-mxd[now];
	return;
}
int getans(int x){
	int qwq=ask(1,1,n,dfn[x],dfn[x]);
	int ans=qwq;
	x=fa[x];
	while(x){
		ans=max(ans,qwq-ask(1,1,n,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
	return ans;
}
int main(){
	cin>>n>>q;
	for (int i=2;i<=n;i++){
		fa[i]=read();
		u[i]=fa[i],v[i]=i;
		nxt[i]=first[u[i]],first[u[i]]=i;
	}
	dfs1(1,1);
	dfs2(1,0);
	build(1,1,n);
	while(q--){
		opt=read(),x=read();
		if (opt==1)upd2(1,1,n,dfn[x],dfo[x],1);
		if (opt==2){
			int qwq=getans(x);
			int s=ask(1,1,n,dfn[x],dfn[x])+depth[x]-max(0,qwq+1);
			upd1(1,1,n,dfn[x],dfo[x]);
			upd2(1,1,n,dfn[x],dfo[x],s);
		}
		if (opt==3){
			if (getans(x)<0)puts("white");
			else puts("black");
		}
	}
	return 0;
}