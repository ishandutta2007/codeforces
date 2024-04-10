#include <iostream>
#include <cstdio>
using namespace std;
int n,u[2000005],v[2000005],first[1000005],nxt[2000005],depth[2000005],ans[2000005];
struct node{
	int mx,l,r;
}tree[22000005];
int cnt,root[1000005];
inline int tree_merge(register int x,register int y,register int nowl,register int nowr){
	if (x==0)return y;
	if (y==0)return x;
	if (nowl==nowr){
		tree[x].mx+=tree[y].mx;
		return x;
	}
	register int mid=(nowl+nowr)/2;
	tree[x].l=tree_merge(tree[x].l,tree[y].l,nowl,mid);
	tree[x].r=tree_merge(tree[x].r,tree[y].r,mid+1,nowr);
	tree[x].mx=max(tree[tree[x].l].mx,tree[tree[x].r].mx);
	return x;
}
inline void tree_update(register int &now,register int nowl,register int nowr,register int pos,register int val){
	if (now==0)now=++cnt;
	if (nowl==nowr){
		tree[now].mx++;
		return;
	}
	register int mid=(nowl+nowr)/2;
	if (pos<=mid)tree_update(tree[now].l,nowl,mid,pos,val);
	else tree_update(tree[now].r,mid+1,nowr,pos,val);
	tree[now].mx=max(tree[tree[now].l].mx,tree[tree[now].r].mx);
	return; 
}
inline int tree_query(register int now,register int nowl,register int nowr){
	if (nowl==nowr)return nowl;
	register int mid=(nowl+nowr)/2;
	if (tree[tree[now].l].mx>=tree[tree[now].r].mx)return tree_query(tree[now].l,nowl,mid);
	return tree_query(tree[now].r,mid+1,nowr);
}
inline void dfs(register int now,register int f,register int d){
	depth[now]=d;
	tree_update(root[now],1,n,depth[now],1);
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		dfs(v[i],now,d+1);
		root[now]=tree_merge(root[now],root[v[i]],1,n);
	}
	ans[now]=tree_query(root[now],1,n)-depth[now];
	return;
}
int main(){
	cin>>n;
	for (register int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs(1,0,1);
	for (register int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++
//AHOI2020RP++