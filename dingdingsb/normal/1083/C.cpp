// Problem: CF1083C Max Mex
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1083C
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define mt make_tuple
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=2e5+100;
int n,m;vector<int>e[N];
int fa[N],dep[N],sz[N],top[N];
void dfs1(int u){
	sz[u]=1;
	for(auto v:e[u])if(v^fa[u]){
		dep[v]=dep[u]+1;
		dfs1(v);
		sz[u]+=sz[v];
	}
}
void dfs2(int u){
	if(!top[u])top[u]=u;
	pair<int,int>mx=mp(0,0);
	for(auto v:e[u])chkmx(mx,mp(sz[v],v));
	top[mx.se]=top[u];
	for(auto v:e[u])dfs2(v);
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;
}
int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
bool on(int x,int u,int v){return dis(u,v)==dis(u,x)+dis(v,x);}
struct node{
	int st,ed;bool ban;
	node(int st=0,int ed=0,bool ban=0):st(st),ed(ed),ban(ban){}
	friend node operator+(node&A,node&B){
		if(A.ban||B.ban)return node(0,0,1);
		tuple<int,int,int>lg={0,0,0};
		if(A.st==0)return B;
		chkmx(lg,mt(dis(A.st,A.ed),A.st,A.ed));
		chkmx(lg,mt(dis(B.st,B.ed),B.st,B.ed));
		chkmx(lg,mt(dis(A.st,B.st),A.st,B.st));
		chkmx(lg,mt(dis(A.st,B.ed),A.st,B.ed));
		chkmx(lg,mt(dis(A.ed,B.st),A.ed,B.st));
		chkmx(lg,mt(dis(A.ed,B.ed),A.ed,B.ed));
		int u=get<1>(lg),v=get<2>(lg);
		if(on(A.st,u,v)&&on(A.ed,u,v)&&on(B.st,u,v)&&on(B.ed,u,v))
			return node(u,v,0);
		return node(0,0,1);
	}
};
int p[N],pos[N];
struct SGT{
	node res[N<<2];
	void pushup(int x){res[x]=res[lc]+res[rc];}
	void build(int x,int l,int r){
		if(l==r)return res[x]=l<n?node(pos[l],pos[l],0):node(0,0,1),void();
		build(lc,l,mid);build(rc,mid+1,r);pushup(x);
	}
	void upd(int x,int l,int r,int p){
		//p
		if(l==r)return res[x]=node(pos[l],pos[l],0),void();
		if(p<=mid)upd(lc,l,mid,p);else upd(rc,mid+1,r,p);pushup(x);
	}
	int lower(int x,int l,int r,node pre){
		if(l==r)return l;
		node L=pre+res[lc];
		if(!L.ban)return lower(rc,mid+1,r,L);
		else return lower(lc,l,mid,pre);
	}
}T;
signed main(){
	read(n);
	for(int i=1;i<=n;i++)
		read(p[i]),pos[p[i]]=i;
	for(int i=2;i<=n;i++)
		read(fa[i]),e[fa[i]].pb(i);
	dfs1(1);dfs2(1);
	T.build(1,0,n);
	read(m);
	while(m--){
		int op;read(op);
		if(op==1){
			int i,j;read(i,j);
			swap(p[i],p[j]);
			swap(pos[p[i]],pos[p[j]]);
			T.upd(1,0,n,p[i]);
			T.upd(1,0,n,p[j]);
		}else{
			write(T.lower(1,0,n,node(0,0,0)));pc('\n');
		}
	}
}