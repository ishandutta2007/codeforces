#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define mod 1000000007
using namespace std;
int n,q,u[200005],v[200005],first[100005],nxt[200005];
int fa[100005],depth[100005],sz[100005],son[100005],top[100005],idx,lt[100005],rt[100005];
void dfs1(int now,int f,int d){
	fa[now]=f,depth[now]=d;
	sz[now]=1;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f){
			dfs1(v[i],now,d+1);
			sz[now]+=sz[v[i]];
			if (sz[v[i]]>sz[son[now]])son[now]=v[i];
		}
	return;
}
void dfs2(int now,int f,int t){
	top[now]=t;
	++idx;
	lt[now]=idx;
	if (son[now])dfs2(son[now],now,t);
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f&&v[i]!=son[now])dfs2(v[i],now,v[i]);
	rt[now]=idx;
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
struct BIT{
	int tree[100005],maxn;
	BIT(){
		memset(tree,0,sizeof(tree));
		maxn=100000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	}
	void add(int l,int r,int val){
		while(l<=maxn)tree[l]+=val,l+=lowbit(l);
		r++;
		while(r<=maxn)tree[r]-=val,r+=lowbit(r);
		return;
	}
	int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
}bit;
void add(int pos,int val){
	bit.add(lt[pos],rt[pos],val);
	return;
}
int ask(int a,int b){
	return bit.ask(lt[a])+bit.ask(lt[b])-bit.ask(lt[lca(a,b)])-bit.ask(lt[fa[lca(a,b)]]);
}
int k,m,r,a[100005],c[100005],f[305],g[305];
void dp(int num){
	for (int i=m;i>=1;i--){
		if (g[i]==0)continue;
		if (num>=i)f[i]=g[i]=0;
		else f[i]=(f[i-1]+f[i]*(i-num))%mod;
	}
	f[0]=0;
	return;
}
signed main(){
	cin>>n>>q;
	for (int i=1;i<n;i++){
		scanf("%lld%lld",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs1(1,0,1);
	dfs2(1,0,1);
	while(q--){
		scanf("%lld%lld%lld",&k,&m,&r);
		for (int i=1;i<=k;i++)scanf("%lld",&a[i]),add(a[i],1);
		memset(f,0,sizeof(f));
		f[0]=1;
		for (int i=1;i<=m;i++)g[i]=1;
		for (int i=1;i<=k;i++)c[i]=ask(a[i],r)-1;
		sort(c+1,c+1+k);
		for (int i=1;i<=k;i++)dp(c[i]);
		for (int i=1;i<=k;i++)add(a[i],-1);
		int ans=0;
		for (int i=1;i<=m;i++)ans=(ans+f[i])%mod;
		cout<<ans<<endl;
	}
}