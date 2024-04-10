//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=5e5+4;
int n,m,Q,tim,tot,a[N],ia[N],idx[N],st[N],ed[N],dep[N],fa[N][20],in[N],uu[N],vv[N],op[N],xx[N],vis[N];
vector<int>e[N];
namespace seg{
	int t[N<<2];
	#define lc (p<<1)
	#define rc (p<<1|1)
	void build(int p,int l,int r){
		if(l==r){
			t[p]=a[idx[l]];
			return;
		}
		int mid=(l+r)>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
		t[p]=max(t[lc],t[rc]);
	}
	void modify(int p,int l,int r,int x){
		if(l==r){
			t[p]=0;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)modify(lc,l,mid,x);
		else modify(rc,mid+1,r,x);
		t[p]=max(t[lc],t[rc]);
	}
	int query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return t[p];
		int mid=(l+r)>>1;
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(mid<ql)return query(rc,mid+1,r,ql,qr);
		return max(query(lc,l,mid,ql,qr),query(rc,mid+1,r,ql,qr)); 
	}
}
namespace dsu{
	int fa[N];
	inline void clear(int n){
		for(int i=1;i<=n;i++)fa[i]=i;
	}
	int find(int x){
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
}
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	for(int i=1;(1ll<<i)<=dep[x];i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	st[x]=tim+1;
	if(x<=n)idx[++tim]=x;
	for(auto v:e[x]){
		fa[v][0]=x;
		dfs(v);
	}
	ed[x]=tim;
}
inline void merge(int u,int v,int intim){
	u=dsu::find(u);v=dsu::find(v);
	if(u==v)return;
	++tot;
	dsu::fa[u]=dsu::fa[v]=dsu::fa[tot]=tot;
	e[tot].push_back(u);e[tot].push_back(v);
	in[tot]=intim;
}
int main(){
	n=tot=read();m=read();Q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		ia[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		uu[i]=read();vv[i]=read();
	}
	for(int i=1;i<=Q;i++){
		op[i]=read();xx[i]=read();
		if(op[i]==2)vis[xx[i]]=1;
	}
	dsu::clear(n);
	for(int i=1;i<=m;i++)if(!vis[i]){
		merge(uu[i],vv[i],Q+1);
	}
	for(int i=Q;i;i--)if(op[i]==2){
		merge(uu[xx[i]],vv[xx[i]],i);
	}
	for(int i=1;i<=tot;i++)
		if(dsu::find(i)==i)dfs(i);
	seg::build(1,1,n);
	for(int t=1,x,v;t<=Q;t++)if(op[t]==1){
		x=xx[t];
		for(int i=19;i>=0;i--)if(in[fa[x][i]]>t)x=fa[x][i];
		v=seg::query(1,1,n,st[x],ed[x]);
		cout<<v<<"\n";
		if(!v)continue;
		seg::modify(1,1,n,st[ia[v]]);
	}
	return (0-0);
}