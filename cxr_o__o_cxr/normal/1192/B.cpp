#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4,inf=1e18;
struct segment{
	#define lc (p<<1)
	#define rc (p<<1|1)
	int t[N<<2],lz[N<<2];
	inline void pushdown(int p){
		if(!lz[p])return;
		t[lc]+=lz[p];lz[lc]+=lz[p];
		t[rc]+=lz[p];lz[rc]+=lz[p];
		lz[p]=0;
	}
	void modify(int p,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr){
			t[p]+=v;lz[p]+=v;
			return;
		}
		int mid=l+r>>1;
		pushdown(p);
		if(ql<=mid)modify(lc,l,mid,ql,qr,v);
		if(mid<qr)modify(rc,mid+1,r,ql,qr,v);
		t[p]=max(t[lc],t[rc]);
	}
	int query(int p,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return t[p];
		int mid=l+r>>1;
		pushdown(p);
		if(qr<=mid)return query(lc,l,mid,ql,qr);
		if(mid<ql)return query(rc,mid+1,r,ql,qr);
		return max(query(lc,l,mid,ql,qr),query(rc,mid+1,r,ql,qr)); 
	}
}t1,t2;
namespace seg{
	int t[N<<2],lz[N<<2],id[N<<2];
	inline void pushdown(int p){
		if(!lz[p])return;
		t[lc]+=lz[p];lz[lc]+=lz[p];
		t[rc]+=lz[p];lz[rc]+=lz[p];
		lz[p]=0;
	}
	void modify(int p,int l,int r,int ql,int qr,int v){
		if(ql<=l&&r<=qr){t[p]+=v;lz[p]+=v;return;}
		int mid=l+r>>1;
		pushdown(p);
		if(ql<=mid)modify(lc,l,mid,ql,qr,v);
		if(mid<qr)modify(rc,mid+1,r,ql,qr,v);
		if(t[lc]>t[rc]){t[p]=t[lc];id[p]=id[lc];}
		else{t[p]=t[rc];id[p]=id[rc];}
	}
	void build(int p,int l,int r){
		id[p]=l;
		if(l==r)return;
		int mid=l+r>>1;
		build(lc,l,mid);build(rc,mid+1,r);
	}
}
struct edge{
	int v,w,nxt;
}e[N<<1];
int first[N],cnt;
inline void add(int u,int v,int w){
	e[++cnt].v=v;e[cnt].w=w;
	e[cnt].nxt=first[u];first[u]=cnt;
}
int n,Q,W,tim,siz[N],son[N],dep[N],fa[N],st[N],ed[N],top[N],a[N],pos[N];
void dfs_1(int x){
	siz[x]=1;
	dep[x]=dep[fa[x]]+1;
	for(int i=first[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(v==fa[x])continue;
		fa[v]=x;
		a[v]=e[i].w;
		dfs_1(v);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
} 
void dfs_2(int x,int tp,int d){
	top[x]=tp;
	st[x]=++tim;pos[tim]=x;
	d+=a[x];
	t2.modify(1,1,n,st[x],st[x],d);
	seg::modify(1,1,n,st[x],st[x],d);
	if(son[x])dfs_2(son[x],tp,d);
	for(int i=first[x],v;i;i=e[i].nxt){
		v=e[i].v;
		if(v==fa[x]||v==son[x])continue;
		dfs_2(v,v,d);
	}
	ed[x]=tim;
	if(son[x]&&ed[son[x]]<ed[x])t1.modify(1,1,n,st[x],st[x],max(t2.query(1,1,n,ed[son[x]]+1,ed[x]),d)-(d<<1));
	else t1.modify(1,1,n,st[x],st[x],-d);
}
inline int solve(int x){
	int d=t2.query(1,1,n,st[x],st[x]),dd; 
	int ans=t2.query(1,1,n,st[x],ed[x])-d;
	while(1){
		if(st[top[x]]<st[x])ans=max(ans,d+t1.query(1,1,n,st[top[x]],st[x]-1));
		x=top[x];
		if(x==1)break;
		dd=t2.query(1,1,n,st[fa[x]],st[fa[x]]);
		if(st[fa[x]]<st[x])ans=max(ans,t2.query(1,1,n,st[fa[x]],st[x]-1)+d-(dd<<1));
		if(ed[x]<ed[fa[x]])ans=max(ans,t2.query(1,1,n,ed[x]+1,ed[fa[x]])+d-(dd<<1));
		x=fa[x];
	}
	return ans;
}
inline void change(int x,int v){
	v-=a[x];
	int u=x;
	t1.modify(1,1,n,st[x],ed[x],-v);
	t2.modify(1,1,n,st[x],ed[x],v);
	seg::modify(1,1,n,st[x],ed[x],v);
	while(top[u]!=1){
		u=fa[top[u]];
		if(ed[son[u]]<ed[u])t1.modify(1,1,n,st[u],st[u],t2.query(1,1,n,ed[son[u]]+1,ed[u])-t2.query(1,1,n,st[u],st[u])*2-t1.query(1,1,n,st[u],st[u]));
	}
	a[x]+=v;
}
signed main(){
	n=read();Q=read();W=read(); 
	for(int i=1,u,v,w;i<n;i++){
		u=read();v=read();w=read();
		add(u,v,w);add(v,u,w); 
	}
	seg::build(1,1,n);
	dfs_1(1);dfs_2(1,1,0);
	for(int i=1,las=0,x,u,v;i<=Q;i++){
		x=(read()+las)%(n-1)+1;
		v=(read()+las)%W;
		u=e[(x<<1)-1].v;x=e[x<<1].v;
		change((dep[x]<dep[u])?u:x,v);
		cout<<(las=solve(pos[seg::id[1]]))<<"\n";
	}
	return (0-0);
}