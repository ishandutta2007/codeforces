#include <iostream>
#include <cstdio>
#define int long long
#define inf 1000000000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct tree_node{
	int l,r,val,tag;
	tree_node(){
		l=r=tag=0;
		val=inf;
		return;
	}
}tree[7000005];
int maxn=200000,root[200005],tree_cnt;
void pushdown(int now){
	if (tree[now].l!=0)tree[tree[now].l].val+=tree[now].tag,tree[tree[now].l].tag+=tree[now].tag;
	if (tree[now].r!=0)tree[tree[now].r].val+=tree[now].tag,tree[tree[now].r].tag+=tree[now].tag;
	tree[now].tag=0;
	return;
}
void pushup(int now){
	tree[now].val=min(tree[tree[now].l].val,tree[tree[now].r].val);
	return;
}
void upd(int &now,int nowl,int nowr,int pos,int val){
	if (now==0)now=++tree_cnt;
	if (nowl!=nowr)pushdown(now);
	if (nowl==nowr){
		tree[now].val=val;
		return;
	}
	int mid=(nowl+nowr)/2;
	if (pos<=mid)upd(tree[now].l,nowl,mid,pos,val);
	else upd(tree[now].r,mid+1,nowr,pos,val);
	pushup(now);
	return;
}
int ask(int now,int nowl,int nowr,int pos){
	if (nowl!=nowr)pushdown(now);
	if (now==0)return inf;
	if (nowl==nowr)return tree[now].val;
	int mid=(nowl+nowr)/2;
	if (pos<=mid)return ask(tree[now].l,nowl,mid,pos);
	return ask(tree[now].r,mid+1,nowr,pos);
}
int merge(int x,int y,int nowl,int nowr){
	if (nowl!=nowr){
		if (x!=0)pushdown(x);
		if (y!=0)pushdown(y);
	}
	if (x==0)return y;
	if (y==0)return x;
	if (nowl==nowr){
		tree[x].val=min(tree[x].val,tree[y].val);
		return x;
	}
	int mid=(nowl+nowr)/2;
	tree[x].l=merge(tree[x].l,tree[y].l,nowl,mid);
	tree[x].r=merge(tree[x].r,tree[y].r,mid+1,nowr);
	pushup(x);
	return x;
}
int n,s;
int opt_num;
int cnt;
void dfs(int now,int val){
	upd(root[now],0,maxn,val,0);
	while(opt_num<n){
		char opt[5];
		scanf("%s",opt+1);
		opt_num++;
		if (opt[1]=='s'){
			int x=read(),y=read();
			if (x==s)tree[root[now]].val+=y,tree[root[now]].tag+=y;
			else{
				int val=tree[root[now]].val;
				tree[root[now]].val+=y;
				tree[root[now]].tag+=y;
				upd(root[now],0,maxn,x,val);
			}
		}
		if (opt[1]=='i'){
			int x=read();
			++cnt;
			int v=cnt;
			dfs(cnt,x);
			int val=ask(root[now],0,maxn,x);
			int awa=val+ask(root[v],0,maxn,x);
			tree[root[v]].val+=val,tree[root[v]].tag+=val;
			int pre=tree[root[now]].val;
			root[now]=merge(root[now],root[v],0,maxn);
			upd(root[now],0,maxn,x,awa);
		}
		if (opt[1]=='e')break;
	}
	return;
}
signed main(){
	cin>>n>>s;
	++cnt;
	dfs(1,0);
	cout<<tree[root[1]].val<<endl;
	return 0;
}