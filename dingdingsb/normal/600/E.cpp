#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
struct node{
	int lc,rc,sum;
	long long ans;
}T[maxn*32];int tot=0;
int pushup(int now){
	int lson=T[now].lc,rson=T[now].rc;
	if(T[lson].sum>T[rson].sum){
		T[now].sum=T[lson].sum;
		T[now].ans=T[lson].ans;
	}
	if(T[rson].sum>T[lson].sum){
		T[now].sum=T[rson].sum;
		T[now].ans=T[rson].ans;
	}
	if(T[lson].sum==T[rson].sum){
		T[now].sum=T[lson].sum;
		T[now].ans=T[lson].ans+T[rson].ans;
	}
}
void add(int &now,int l,int r,int pos,int v){
	if(!now)now=++tot;
	if(l==r){
		T[now].sum+=v;
		T[now].ans=l;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)add(T[now].lc,l,mid,pos,v);
	else add(T[now].rc,mid+1,r,pos,v);
	pushup(now);
}
int merge(int a,int b,int l,int r){
	if(!a||!b)return b|a;
	if(l==r){
		T[a].sum+=T[b].sum;
		T[a].ans=l;
		return a;
	}
	int mid=(l+r)>>1;
	T[a].lc=merge(T[a].lc,T[b].lc,l,mid);
	T[a].rc=merge(T[a].rc,T[b].rc,mid+1,r);
	pushup(a);
	return a;
}
vector<int>e[maxn];
int color[maxn],root[maxn],n;
ll ans[maxn];
void dfs(int u,int fa){
	for(auto v:e[u])
		if(v!=fa)
			dfs(v,u),
			root[u]=merge(root[u],root[v],1,n);
	add(root[u],1,n,color[u],1);
	ans[u]=T[root[u]].ans;
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&color[i]);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
	printf("%lld ",ans[i]);
}