#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long
#define inf 1000000000000000
using namespace std;
struct node{
	int l,r;
	ll val,tag;
	node(){
		l=r=tag=0;
		val=inf;
		return;
	}
}tree[6000005];
int cnt;
inline void pushdown(register int now){
	if (tree[now].l)tree[tree[now].l].val+=tree[now].tag,tree[tree[now].l].tag+=tree[now].tag;
	if (tree[now].r)tree[tree[now].r].val+=tree[now].tag,tree[tree[now].r].tag+=tree[now].tag;
	tree[now].tag=0;
	return;
}
inline int merge(register int x,register int y){
	if (x==0)return y;
	if (y==0)return x;
	pushdown(x),pushdown(y);
	tree[x].val=min(tree[x].val,tree[y].val);
	tree[x].l=merge(tree[x].l,tree[y].l);
	tree[x].r=merge(tree[x].r,tree[y].r);
	return x;
}
inline ll ask(register int now,register int nowl,register int nowr,register int lt,register int rt){
	if (now==0)return inf;
	pushdown(now);
	if (nowl>=lt&&nowr<=rt)return tree[now].val;
	register int mid=(nowl+nowr)/2;
	register ll ans=inf;
	if (mid>=lt)ans=min(ans,ask(tree[now].l,nowl,mid,lt,rt));
	if (mid+1<=rt)ans=min(ans,ask(tree[now].r,mid+1,nowr,lt,rt));
	return ans;
}
inline void upd(register int &now,register int nowl,register int nowr,register int pos,register ll val){
	if (now==0)now=++cnt;
	pushdown(now);
	tree[now].val=min(tree[now].val,val);
	if (nowl==nowr)return;
	register int mid=(nowl+nowr)/2;
	if (pos<=mid)upd(tree[now].l,nowl,mid,pos,val);
	else upd(tree[now].r,mid+1,nowr,pos,val); 
	return;
}
int n,m,u[600005],v[600005],first[300005],nxt[600005],depth[600005],root[600005],fg;
ll ans;
vector <int>c[300005];
vector <ll>val[300005];
inline void dfs(register int now,register int fa,register int d){
	depth[now]=d;
	register ll sum=0;
	for (register int i=first[now];i&&fg==0;i=nxt[i])
		if (v[i]!=fa){
			dfs(v[i],now,d+1);
			sum+=ask(root[v[i]],1,n,1,depth[now]);
			if (sum>=inf)fg=1;
		}
	for (register int i=first[now];i&&fg==0;i=nxt[i]){
		if (v[i]==fa)continue;
		register ll nowval=ask(root[v[i]],1,n,1,depth[now]);
		tree[root[v[i]]].val+=sum-nowval;
		tree[root[v[i]]].tag+=sum-nowval;		
		root[now]=merge(root[now],root[v[i]]);
	}
	for (register int i=0,len=c[now].size();i<len&&fg==0;i++)
		upd(root[now],1,n,depth[c[now][i]],val[now][i]+sum);
	return;
}
int main(){
	cin>>n>>m;
	if (n==1){
		cout<<0<<endl;
		return 0;
	} 
	for (int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	for (int i=1;i<=m;i++){
		register int x,y;
		register ll z;
		scanf("%d%d%lld",&x,&y,&z);
		if (x!=y)c[x].push_back(y),val[x].push_back(z);
	}
	dfs(1,0,1);
	ans=ask(root[1],1,n,1,1);
	if (fg==0&&ans<inf)cout<<ans<<endl;
	else puts("-1");
	return 0;
}
//~