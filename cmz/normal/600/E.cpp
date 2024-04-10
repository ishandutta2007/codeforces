#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int ls[maxn*30],rs[maxn*30],rt[maxn],Max[maxn*30];
ll ans[maxn*30];
int a[maxn],n,top,tot;
int fir[maxn*2],nxt[maxn*2],gett[maxn*2];
inline void add(int x,int y){
	gett[++top]=y; nxt[top]=fir[x]; fir[x]=top;
}
inline void pushup(int x){
	if (Max[ls[x]]==Max[rs[x]]) Max[x]=Max[ls[x]],ans[x]=ans[ls[x]]+ans[rs[x]]; else 
	if (Max[ls[x]]>Max[rs[x]]) Max[x]=Max[ls[x]],ans[x]=ans[ls[x]]; else ans[x]=ans[rs[x]],Max[x]=Max[rs[x]];
}
int merge(int x,int y,int l,int r){
	if (!x) return y;
	if (!y) return x;
	if (l==r){
		Max[x]+=Max[y];
		return x;
	}
	int mid=(l+r)/2;
	ls[x]=merge(ls[x],ls[y],l,mid); rs[x]=merge(rs[x],rs[y],mid+1,r);
	pushup(x); 
	return x; 
}
void build(int &now,int l,int r,int val,int pos){
	if (!now) now=++tot;
	if (l==r){
		ans[now]=val; Max[now]=1;
		return;
	}
	int mid=(l+r)/2;
	if (pos<=mid) build(ls[now],l,mid,val,pos); else build(rs[now],mid+1,r,val,pos);
	pushup(now);
}
void dfs(int x,int fa){
	for (int i=fir[x];i;i=nxt[i]){
		int v=gett[i];
		if (v==fa) continue;
		dfs(v,x); rt[x]=merge(rt[x],rt[v],1,n);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		build(rt[i],1,n,a[i],a[i]);
	}
	for (int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	for (int i=1;i<=n;++i) printf("%lld ",ans[rt[i]]);
	return 0;
}