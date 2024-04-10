#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
//const ld PI=acosl(-1),EPS=1e-10;
template<class T> inline void dmin(T& x,T y){ y<x?x=y:0; }
template<class T> inline void dmax(T& x,T y){ y>x?x=y:0; }
template<class T> inline void dmin(T& x,vector<T> y){for(auto t:y)t<x?x=t:0;}
template<class T> inline void dmax(T& x,vector<T> y){for(auto t:y)t>x?x=t:0;}
/*
const int N=5+1e5,MOD=998244353;
inline int fpow(int x,int n,int ret=1,int mod=MOD){
	for(;n;n>>=1,x=1ll*x*x%mod)
		n&1?ret=1ll*ret*x%mod:0;
	return ret;
}
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int inv[N],fac[N],ifac[N];
struct IniterFacInv{
	IniterFacInv(){
		fac[0]=ifac[0]=inv[1]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__initer_comb;
inline int comb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
inline int rcomb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*ifac[n]*fac[m]%MOD*fac[n-m]%MOD;
}
*/
const int N=5+1e6;
struct SEG{
	pair<int,int> t[N<<2];
	void up(int x){ t[x]=max(t[x+x],t[x+x+1]); }
	void build(int p,int l,int r){
		if(l==r){
			t[p]=make_pair(0,l);
			return;
		}
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
	}
	void change(int p,int l,int r,int x,int k){
		if(l==r){
			t[p].first=k;
			return;
		}
		int m=l+r>>1;
		if(x<=m) change(p+p,l,m,x,k);
		else change(p+p+1,m+1,r,x,k);
		up(p);
	}
	pair<int,int> query(int p,int l,int r,int x,int y){
		if(y<l||r<x) return make_pair(0,0);
		if(x<=l&&r<=y) return t[p];
		int m=l+r>>1;
		return max(query(p+p,l,m,x,y),query(p+p+1,m+1,r,x,y));
	}
}seg;
vector<int> a[N];
void merge(vector<int>& x,vector<int>& y){
	if(x.size()<y.size()) swap(x,y);
	for(auto t:y) x.push_back(t);
}
struct E{ int x,y,t; }e[N];
struct Q{ int type,x; }q[N];
int p[N],val[N],n,m,top_q,top_node=0;
bool cmp(E x,E y){ return x.t>y.t; }
struct DSF{
	int fa[N];
	void ms(int x){ fa[x]=x; }
	int fs(int x){
		if(fa[x]!=x) fa[x]=fs(fa[x]);
		return fa[x];
	}
	bool member(int x,int y){
		return fs(x)==fs(y);
	}
	void merge(int x,int y){
		if(!member(x,y))
			fa[fs(x)]=fs(y);
	}
}dsf;
vector<int> son[N];
int dfn[N],en[N],fa[23][N],ti=0;
void dfs(int x,int pre){
	fa[0][x]=pre;
	for(int l=1;l<=20;++l)
		fa[l][x]=fa[l-1][fa[l-1][x]];
	dfn[x]=++ti;
	seg.change(1,1,top_node,dfn[x],p[x]);
	for(auto y:son[x])
		dfs(y,x);
	en[x]=ti;
}
int jump(int x,int ti){
	for(int l=20;l>=0;--l)
		if(val[fa[l][x]]>ti) 
			x=fa[l][x];
	return x;
}
int main(){
	scanf("%d%d%d",&n,&m,&top_q);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]),val[i]=top_q+1;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&e[i].x,&e[i].y);
		e[i].t=top_q+1;
	}
	for(int i=1;i<=top_q;++i){
		scanf("%d%d",&q[i].type,&q[i].x);
		if(q[i].type==2) e[q[i].x].t=i;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;++i) dsf.ms(i);
	top_node=n;
	for(int i=1;i<=m;++i){
		E x=e[i];
		if(!dsf.member(x.x,x.y)){
			val[++top_node]=x.t;
			dsf.ms(top_node);
			son[top_node].push_back(dsf.fs(x.x));
			son[top_node].push_back(dsf.fs(x.y));
			dsf.merge(x.x,top_node);
			dsf.merge(x.y,top_node);
		}
	}
	seg.build(1,1,top_node);
	for(int i=1;i<=top_node;++i)
		if(dsf.fs(i)==i)
			dfs(i,0);
	for(int i=1;i<=top_q;++i){
		int x=q[i].x;
		if(q[i].type==1){
			x=jump(x,i);
			pair<int,int> d=seg.query(1,1,top_node,dfn[x],en[x]);
			seg.change(1,1,top_node,d.second,0);
			printf("%d\n",d.first);
		}
	}
	return 0;
}