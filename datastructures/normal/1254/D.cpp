#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
#define int long long
using namespace std;
int Qpow(int a,int p){
	if (p==0)return 1;
	int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p&1)t=t*a%mod;
	return t;
}
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
int n,q,u[300005],v[300005],first[150005],nxt[300005];
int inv[150005];
int depth[150005],fa[150005],sz[150005],son[150005],top[150005],idx,dfn[150005],dfo[150005];
int sum[150005];
int opt,x,y;
struct BIT1{ //add(l,r) ask(pos)
	int tree[150005],maxn;
	BIT1(){
		memset(tree,0,sizeof(tree));
		maxn=150000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	} 
	void add(int l,int r,int val){
		while(l<=maxn)upd(tree[l],val),l+=lowbit(l);
		r++;
		while(r<=maxn)upd(tree[r],mod-val),r+=lowbit(r);
		return;
	}
	int ask(int pos){
		int ans=0;
		while(pos)upd(ans,tree[pos]),pos-=lowbit(pos);
		return ans;
	}
}bit1;
struct BIT2{ //add(l,r) ask(pos)
	int tree[150005],maxn;
	BIT2(){
		memset(tree,0,sizeof(tree));
		maxn=150000;
		return;
	}
	int lowbit(int x){
		return x&(-x);
	} 
	void add(int pos,int val){
		while(pos<=maxn)upd(tree[pos],val),pos+=lowbit(pos);
		return;
	}
	int ask(int l,int r){
		int ans=0;
		while(r)upd(ans,tree[r]),r-=lowbit(r);
		l--;
		while(l)upd(ans,mod-tree[l]),l-=lowbit(l);
		return ans;
	}
}bit2;
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
	dfn[now]=idx;
	if (son[now]!=0)dfs2(son[now],now,t);
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=f&&v[i]!=son[now])dfs2(v[i],now,v[i]);
	dfo[now]=idx;
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
	for (int i=1;i<=n;i++)inv[i]=Qpow(i,mod-2);
	dfs1(1,0,1);
	dfs2(1,0,1);
	while(q--){
		scanf("%lld",&opt);
		if (opt==1){
			scanf("%lld%lld",&x,&y);
			bit1.add(1,dfn[x]-1,y*sz[x]%mod*inv[n]%mod);
			bit1.add(dfo[x]+1,n,y*sz[x]%mod*inv[n]%mod);
			bit2.add(dfn[x],y*(n-sz[son[x]])%mod*inv[n]%mod);
			upd(sum[x],y);
		}
		if (opt==2){
			scanf("%lld",&x);
			int ans=sum[x];
			upd(ans,bit1.ask(dfn[x]));
			int now=x;
			while(now){
				upd(ans,bit2.ask(dfn[top[now]],dfn[now]-1));
				if (fa[top[now]])upd(ans,sum[fa[top[now]]]*(n-sz[top[now]])%mod*inv[n]%mod);
				now=fa[top[now]];
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}