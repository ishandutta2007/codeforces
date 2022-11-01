//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4,cinf=0xcfcfcfcf;
int tim,dep[N],siz[N],fa[N],son[N],top[N],st[N],ed[N],idx[N];
vector<int>e[N];
void dfs_1(int x){
	dep[x]=dep[fa[x]]+1;
	siz[x]=1;
	for(auto v:e[x]){
		if(v==fa[x])continue;
		fa[v]=x;
		dfs_1(v);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
void dfs_2(int x,int tp){
	top[x]=tp;
	st[x]=++tim;idx[tim]=x;
	if(son[x])dfs_2(son[x],tp);
	for(auto v:e[x]){
		if(v==fa[x]||v==son[x])continue;
		dfs_2(v,v);
	}
	ed[x]=tim;
}
inline int getlca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])u^=v^=u^=v;
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
#define lc (p<<1)
#define rc (p<<1|1)
int n,m,Q,t[N<<2],up[N][20];
void modify(int p,int l,int r,int ql,int qr,int v){
	if(ql<=l&&r<=qr){
		if(!t[p]||t[p]>v)t[p]=v;
		return;
	}
	int mid=l+r>>1;
	if(ql<=mid)modify(lc,l,mid,ql,qr,v);
	if(mid<qr)modify(rc,mid+1,r,ql,qr,v); 
}
void query(int p,int l,int r){
	if(l==r){
		if(t[p])up[idx[l]][0]=idx[t[p]];
		else up[idx[l]][0]=idx[l];
		return;
	}
	int mid=l+r>>1;
	if(t[p]){
		if(!t[lc]||t[lc]>t[p])t[lc]=t[p];
		if(!t[rc]||t[rc]>t[p])t[rc]=t[p];
	}
	query(lc,l,mid);query(rc,mid+1,r);
}
inline void slpfmdf(int u,int f){
	while(top[u]!=top[f]){
		modify(1,1,n,st[top[u]],st[u],st[f]);
		u=fa[top[u]];
	}
	modify(1,1,n,st[f],st[u],st[f]);
}
inline void add(int x,int v){
	for(;x<=n;x+=x&-x)t[x]+=v;
}
inline int ask(int x){
	int ret=0;
	for(;x;x-=x&-x)ret+=t[x];
	return ret;
}
inline int uppo(int &u,int f){
	if(dep[up[u][19]]>dep[f])return cinf;
	int ret=0;
	for(int i=19;i>=0;i--){
		if(dep[up[u][i]]>dep[f]){
			ret+=1<<i;
			u=up[u][i];
		}
	}
	return ret;
}
vector<int>bus[N];
vector<pair<int,int> >q[N];
#define fi first
#define se second
int ans[N],ans2[N];
int main(){
	n=read();
	for(int i=2,x;i<=n;i++){
		x=read();
		e[x].push_back(i);e[i].push_back(x);
	}
	dfs_1(1);dfs_2(1,1);
	m=read();
	for(int i=1,u,v,lca;i<=m;i++){
		u=read();v=read();
		lca=getlca(u,v);
		if(st[u]>st[v])u^=v^=u^=v;
		if(u!=lca){
			bus[st[u]].push_back(v);
			slpfmdf(u,lca);
		}
		slpfmdf(v,lca);
	}
	query(1,1,n);
	for(int j=1;j<=19;j++)
		for(int i=1;i<=n;i++)
			up[i][j]=up[up[i][j-1]][j-1];
//	for(int i=1;i<=n;i++)cerr<<up[i][0]<<" ";puts("");
	Q=read();
	for(int tt=1,u,v,lca;tt<=Q;tt++){
		u=read();v=read();
		lca=getlca(u,v);
		ans[tt]=uppo(u,lca)+uppo(v,lca)+2;
		if(st[u]>st[v])u^=v^=u^=v;
		if(u==lca)ans[tt]--;
		else if(ans[tt]>0){
			q[st[u]-1].push_back(make_pair(v,-tt));
			q[ed[u]].push_back(make_pair(v,tt));
		}
	}
	for(int i=0;i<=n;i++){
		for(auto v:bus[i])
			add(st[v],1);
		for(auto v:q[i]){
			if(v.se<0)ans2[-v.se]-=ask(ed[v.fi])-ask(st[v.fi]-1);
			else{
				ans2[v.se]+=ask(ed[v.fi])-ask(st[v.fi]-1);
				if(ans2[v.se])ans[v.se]--;
			} 
		}
	}
	for(int i=1;i<=Q;i++){
		if(ans[i]<0)puts("-1");
		else cout<<ans[i]<<"\n";
	}
	return (0-0);
}