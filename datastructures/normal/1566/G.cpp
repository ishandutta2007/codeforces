#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#define ll long long
#define inf 1000000000000
#define maxw 1000000000
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct edge_node{
	int u,v,w;
	edge_node(){
		u=v=w=0;
		return;
	}
	bool operator ==(const edge_node &x)const{
		if (u!=x.u)return 0;
		if (v!=x.v)return 0;
		if (w!=x.w)return 0;
		return 1;
	}
	bool operator <(const edge_node &x)const{
		if (w!=x.w)return w<x.w;
		if (u!=x.u)return u<x.u;
		return v<x.v;
	}
};
edge_node make_edge_node(int u,int v,int w){
	edge_node ans;
	ans.u=u,ans.v=v,ans.w=w;
	return ans;
}
multiset<edge_node> c[100005],d;
struct SGT{
	ll tree[400005];
	SGT(){
		for (int i=0;i<=400000;i++)tree[i]=inf;
		return;
	}
	void pushup(int now){
		tree[now]=min(tree[now*2],tree[now*2+1]);
		return;
	}
	void upd(int now,int nowl,int nowr,int pos,ll val){
		if (nowl==nowr){
			tree[now]=val;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (pos<=mid)upd(now*2,nowl,mid,pos,val);
		else upd(now*2+1,mid+1,nowr,pos,val);
		pushup(now);
		return;
	}
	ll ask(){
		return tree[1];
	}
}sgt;
struct tree_node{
	int l,r,val;
	tree_node(){
		l=r=val=0;
		return;
	}
}tree[15000005];
int cnt,root[100005];
void add(int &now,int nowl,int nowr,int pos,int val){
	if (now==0)now=++cnt;
	tree[now].val+=val;
	if (nowl==nowr)return;
	int mid=(nowl+nowr)/2;
	if (pos<=mid)add(tree[now].l,nowl,mid,pos,val);
	else add(tree[now].r,mid+1,nowr,pos,val);
	return;
}
ll ask(int a,int b,int c,int nowl,int nowr){
	if (nowl==nowr){
		if (tree[a].val==tree[b].val+tree[c].val)return inf;
		return nowl;
	}
	int mid=(nowl+nowr)/2;
	if (tree[tree[a].l].val==tree[tree[b].l].val+tree[tree[c].l].val)return ask(tree[a].r,tree[b].r,tree[c].r,mid+1,nowr);
	return ask(tree[a].l,tree[b].l,tree[c].l,nowl,mid);
}
int n,m,q,u,v,w;
map<int,int> e[100005];
void vertice_upd(int now){
	multiset<edge_node>::iterator it=c[now].begin();
	ll sum=0;
	for (int i=1;i<=3;i++){
		if (it==c[now].end()){
			sum=inf;
			continue;
		}
		sum+=(*it).w;
		it++;
	}
	sgt.upd(1,1,n,now,sum);
	return;
}
void add_edge(int u,int v,int w){
	if (u>v)swap(u,v);
	c[u].insert(make_edge_node(u,v,w));
	c[v].insert(make_edge_node(u,v,w));
	add(root[0],1,maxw,w,1);
	add(root[u],1,maxw,w,1);
	add(root[v],1,maxw,w,1);
	vertice_upd(u),vertice_upd(v);
	e[u][v]=w;
	d.insert(make_edge_node(u,v,w));
	return;
}
void del_edge(int u,int v){
	if (u>v)swap(u,v);
	int w=e[u][v];
	c[u].erase(c[u].lower_bound(make_edge_node(u,v,w)));
	c[v].erase(c[v].lower_bound(make_edge_node(u,v,w)));
	add(root[0],1,maxw,w,-1);
	add(root[u],1,maxw,w,-1);
	add(root[v],1,maxw,w,-1);
	vertice_upd(u),vertice_upd(v);
	e[u][v]=0;
	d.erase(d.lower_bound(make_edge_node(u,v,w)));
	return;
}
ll find1(int u,int v,int w){
	ll ans=inf;
	multiset<edge_node>::iterator it1=c[u].begin(),it2;
	int cnt=0;
	edge_node qwq=make_edge_node(u,v,w);
	while(it1!=c[u].end()&&cnt<2){
		if ((*it1)==qwq){
			it1++;
			continue;
		}
		cnt++;
		it2=c[v].begin();
		while(it2!=c[v].end()&&((*it2)==qwq||(*it2).u==(*it1).u||(*it2).u==(*it1).v||(*it2).v==(*it1).u||(*it2).v==(*it1).v))it2++;
		if (it2!=c[v].end())ans=min(ans,(ll)((*it1).w+(*it2).w));
		it1++;
	}
	return ans;
}
ll find2(int u,int v,int w){
	ll ans=w;
	add(root[0],1,maxw,w,1);
	ans+=ask(root[0],root[u],root[v],1,maxw);
	add(root[0],1,maxw,w,-1);
	return ans;
}
ll ask(){
	multiset<edge_node>::iterator it=d.begin();
	int u=(*it).u,v=(*it).v,w=(*it).w;
	return min(sgt.ask(),min(find1(u,v,w),find2(u,v,w)));
}
signed main(){
	n=read(),m=read();
	for (int i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		add_edge(u,v,w);
	}
	printf("%lld\n",ask());
	q=read();
	while(q--){
		int opt=read();
		if (opt==0)u=read(),v=read(),del_edge(u,v);
		if (opt==1)u=read(),v=read(),w=read(),add_edge(u,v,w);
		printf("%lld\n",ask());
	}
	return 0;
}