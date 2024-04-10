#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define ll long long
using namespace std;
int n,q,a[300005],u[600005],v[600005],first[300005],nxt[600005],x,y,l,r;
int depth[300005],fa[300005][25];
ll val[300005];
inline ll rnd(){
	register ll nowval=0;
	for (register int i=62;i>=0;i--)
		nowval+=(1ll<<i)*(rand()%2);
	return nowval;
}
struct sgt_node{
	int l,r;
	ll val;
	sgt_node(){
		l=r=val=0;
		return;
	}
}tree[10000005];
int cnt,root[300005];
inline void update(register int &now,register int nowl,register int nowr,register int pos,register ll val){
	tree[cnt+1]=tree[now];
	now=++cnt;
	tree[now].val^=val;
	if (nowl==nowr)return;
	register int mid=(nowl+nowr)/2;
	if (pos<=mid)update(tree[now].l,nowl,mid,pos,val);
	else update(tree[now].r,mid+1,nowr,pos,val);
	return;
}
inline ll ask(register int a,register int b,register int nowl,register int nowr,register int lt,register int rt){
	if (nowl>=lt&&nowr<=rt)return tree[a].val^tree[b].val;
	register int mid=(nowl+nowr)/2;
	ll val=0;
	if (mid>=lt)val^=ask(tree[a].l,tree[b].l,nowl,mid,lt,rt);
	if (mid+1<=rt)val^=ask(tree[a].r,tree[b].r,mid+1,nowr,lt,rt);
	return val;
}
inline void dfs(register int now,register int f,register int d){
	depth[now]=d;
	fa[now][0]=f;
	for (register int i=1;i<=20;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	root[now]=root[f];
	update(root[now],1,n,a[now],val[a[now]]);
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==f)continue;
		dfs(v[i],now,d+1);
	}
	return;
}
inline int lca(register int a,register int b){
	if (depth[a]<depth[b])swap(a,b);
	for (register int i=20;i>=0;i--)
		if (depth[fa[a][i]]>=depth[b])a=fa[a][i];
	if (a==b)return a;
	for (register int i=20;i>=0;i--)
		if (fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
int main(){
	srand(time(NULL));
	cin>>n>>q;
	for (register int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (register int i=1;i<=n;i++)val[i]=rnd();
	for (register int i=1;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs(1,0,1);
	while(q--){
		scanf("%d%d%d%d",&x,&y,&l,&r);
		int ans=-1,L=l,R=r,LCA=lca(x,y);
		while(L<=R){
			register int mid=(L+R)/2;
			register ll nowval=ask(root[x],root[y],1,n,l,mid);
			if (a[LCA]>=l&&a[LCA]<=mid)nowval^=val[a[LCA]];
			if (nowval!=0)ans=mid,R=mid-1;
			else L=mid+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}