#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5,M=1e5+5;
mt19937 rng(12345);
int n,q,bg[M],ed[M],rt;
int tot,s[2][N],id[N],f[N],tg[N],mn[N],mx[N],sz[N],fa[N],key[N];
int node(int I,int X){
	int i=++tot;
	id[i]=I,f[i]=mn[i]=mx[i]=X,sz[i]=1;
	key[i]=rng();
	return i;
}
void pushup(int i){
	int ls=s[0][i],rs=s[1][i];
	mn[i]=min(f[i],min(mn[ls],mn[rs]));
	mx[i]=max(f[i],max(mx[ls],mx[rs]));
	sz[i]=sz[ls]+sz[rs]+1;
	if(ls)fa[ls]=i;
	if(rs)fa[rs]=i;
}
void pushdown(int i){
	int ls=s[0][i],rs=s[1][i],t=tg[i];
	if(t){
		if(ls)f[ls]-=t,mn[ls]-=t,mx[ls]-=t,tg[ls]+=t;
		if(rs)f[rs]-=t,mn[rs]-=t,mx[rs]-=t,tg[rs]+=t;
		tg[i]=0;
	}
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	pushdown(x),pushdown(y);
	int r;
	if(key[x]<key[y])r=x,s[1][r]=merge(s[1][r],y);
	else r=y,s[0][r]=merge(x,s[0][r]);
	pushup(r);
	return r;
}
void split(int i,int k,int &x,int &y){
	if(!i){x=y=0;return;}
	fa[i]=0;
	pushdown(i);
	if(sz[s[0][i]]>=k)y=i,split(s[0][i],k,x,s[0][i]);
	else x=i,split(s[1][i],k-sz[s[0][i]]-1,s[1][i],y);
	pushup(i);
}
void pushtag(int u){
	stack<int>sta;
	for(;u;u=fa[u])sta.push(u);
	while(!sta.empty())pushdown(sta.top()),sta.pop();
}
int getdfn(int u){
	int sm=sz[s[0][u]]+1;
	for(int f=fa[u];f;u=f,f=fa[f])
		if(s[1][f]==u)sm+=sz[s[0][f]]+1;
	return sm;
}
int getbs(int u,int w){
	pushdown(u);
	if(mx[s[1][u]]>=w)return getbs(s[1][u],w);
	if(f[u]==w)return u;
	return getbs(s[0][u],w);
}
int getsb(int u,int w){
	pushdown(u);
	if(mn[s[1][u]]<=w)return getsb(s[1][u],w);
	if(f[u]==w)return u;
	return getsb(s[0][u],w);
}
void change(){
	int u,h;scanf("%d%d",&u,&h);
	pushtag(bg[u]),pushtag(ed[u]);
	int l=getdfn(bg[u]),r=getdfn(ed[u]);
	int A,B,C;
	split(rt,l-1,A,B),split(B,r-l+1,B,C);
	int p=id[getsb(A,f[bg[u]]-h)];
	rt=merge(A,C);
	int ts=getdfn(ed[p]);
	split(rt,ts,A,C);
	ed[p]=node(p,f[bg[u]]-h);
	f[B]-=h-1,mn[B]-=h-1,mx[B]-=h-1,tg[B]+=h-1;
	rt=merge(A,merge(B,merge(ed[p],C)));
}
void ask1(){
	int u,v;scanf("%d%d",&u,&v);
	u=bg[u],v=bg[v];
	pushtag(u),pushtag(v);
	int du=getdfn(u),dv=getdfn(v);
	if(du>dv)swap(du,dv);
	int A,B,C;
	split(rt,du-1,A,B);
	split(B,dv-du+1,B,C);
	printf("%d\n",f[u]+f[v]-2*mn[B]);
	rt=merge(A,merge(B,C));
}
void ask2(){
	int w;scanf("%d",&w);
	int u=getbs(rt,w);
	printf("%d\n",id[u]);
}
vector<int>g[M];
void dfs(int u,int d){
	bg[u]=ed[u]=node(u,d),rt=merge(rt,bg[u]);
	for(auto v:g[u]){
		dfs(v,d+1);
		ed[u]=node(u,d),rt=merge(rt,ed[u]);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	mn[0]=1e9,mx[0]=-1e9;
	for(int i=1;i<=n;i++){
		int N;scanf("%d",&N);
		while(N--){
			int u;scanf("%d",&u);
			g[i].push_back(u);
		}
	}
	dfs(1,0);
	while(q--){
		int op;scanf("%d",&op);
		switch(op){
			case 1:ask1();break;
			case 2:change();break;
			case 3:ask2();break;
		}
	}
}