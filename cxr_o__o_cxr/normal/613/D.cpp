#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int siz[N],dep[N],fa[N],son[N],top[N],dfn[N],tim;
vector<int>pe[N],e[N];
void dfs_1(int x){
	siz[x]=1;
	dep[x]=dep[fa[x]]+1;
	for(auto v:pe[x]){
		if(v==fa[x])continue;
		fa[v]=x;
		dfs_1(v);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]])son[x]=v;
	}
}
void dfs_2(int x,int tpp){
	dfn[x]=++tim;
	top[x]=tpp;
	if(son[x])dfs_2(son[x],tpp);
	for(auto v:pe[x]){
		if(v==fa[x]||v==son[x])continue;
		dfs_2(v,v);
	}
}
inline int LCA(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])u^=v^=u^=v;
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
int n,m,kk,tp,ans,st[N],h[N],tg[N],f[N][2];
inline void insert(int x){
	if(tp==1){st[++tp]=x;return;}
	int lca=LCA(st[tp],x);
	if(lca==st[tp]){st[++tp]=x;return;}
	while(tp>1&&dfn[st[tp-1]]>=dfn[lca]){e[st[tp-1]].push_back(st[tp]);tp--;}
	if(st[tp]!=lca){e[lca].push_back(st[tp]);st[tp]=lca;}
	st[++tp]=x;
}
void getans(int x,int fat){
	int s0=0,s1=0;
	for(auto v:e[x]){
		getans(v,x);
		s0+=f[v][0];
		s1+=min(f[v][1],f[v][0]);
	}
	if(tg[x]){f[x][0]=N;f[x][1]=s0;}
	else{
		f[x][0]=min(s0,1+s1);
		f[x][1]=N;
		for(auto v:e[x])
			f[x][1]=min(f[x][1],s0-f[v][0]+f[v][1]);
	}
	if(fa[x]!=fat)f[x][0]=min(f[x][1]+1,f[x][0]);
	e[x].clear();
}
inline bool comp(int x,int y){return dfn[x]<dfn[y];}
int main(){
	int ygg=clock();
	n=read();
	for(int i=1,u,v;i<n;i++){
		u=read();v=read();
		pe[u].push_back(v);pe[v].push_back(u);
	}
	dfs_1(1);dfs_2(1,1);
	if(clock()-ygg>1500)assert(0);
	m=read();
	while(m--){
		kk=read();
		for(int i=1;i<=kk;i++){h[i]=read();tg[h[i]]=1;} 
		sort(h+1,h+kk+1,comp);
		st[tp=1]=1;
		for(int i=1;i<=kk;i++)if(h[i]!=1)insert(h[i]);
		while(tp>1){e[st[tp-1]].push_back(st[tp]);tp--;}
		getans(1,0);
		for(int i=1;i<=kk;i++)tg[h[i]]=0;
		ans=min(f[1][0],f[1][1]);
		if(ans>n)puts("-1");
		else cout<<ans<<"\n";
	}
	return (0-0);
}