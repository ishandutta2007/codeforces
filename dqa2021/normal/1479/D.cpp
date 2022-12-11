#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
inline ull getrand(){
	static ull sd=954758641236047862ULL;
	return sd^=sd>>13,sd^=sd<<38,sd^=sd>>46,sd^=sd<<17;
}

int n,q,a[300010];
ull b[300010];
vector<int> e[300010];



#define mid (l+r>>1)

struct C{
	int ls,rs; ull w;
}c[25*300000+10];
int ctot,rt[300010];

void ins(int &u,int v,int l,int r,int p,const ull &w){
	c[u=++ctot]=c[v]; c[u].w^=w;
	if (l==r) return;
	if (p<=mid) ins(c[u].ls,c[v].ls,l,mid,p,w);
	else ins(c[u].rs,c[v].rs,mid+1,r,p,w);
}

int query(int A,int B,int C,int D,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr){
		if (c[A].w^c[B].w^c[C].w^c[D].w);
		else return -1;
		if (l==r) return l;
		if (c[c[A].ls].w^c[c[B].ls].w^c[c[C].ls].w^c[c[D].ls].w) return query(c[A].ls,c[B].ls,c[C].ls,c[D].ls,l,mid,ql,qr);
		return query(c[A].rs,c[B].rs,c[C].rs,c[D].rs,mid+1,r,ql,qr);
	}
	if (qr<=mid) return query(c[A].ls,c[B].ls,c[C].ls,c[D].ls,l,mid,ql,qr);
	if (ql>mid) return query(c[A].rs,c[B].rs,c[C].rs,c[D].rs,mid+1,r,ql,qr);
	int t=query(c[A].ls,c[B].ls,c[C].ls,c[D].ls,l,mid,ql,qr);
	if (!~t) t=query(c[A].rs,c[B].rs,c[C].rs,c[D].rs,mid+1,r,ql,qr);
	return t;
}

#undef mid

int fat[300010],dep[300010],siz[300010],son[300010];
int top[300010];

void dfs1(int x,int f,int d){
	ins(rt[x],rt[f],1,n,a[x],b[a[x]]);
	fat[x]=f; dep[x]=d; siz[x]=1;
	for (int y: e[x]){
		if (y==f) continue;
		dfs1(y,x,d+1);
		siz[x]+=siz[y];
		if (siz[y]>siz[son[x]]) son[x]=y;
	}
}
void dfs2(int x,int t){
	top[x]=t;
	if (siz[x]==1) return;
	dfs2(son[x],t);
	for (int y: e[x]){
		if (y==fat[x]||y==son[x]) continue;
		dfs2(y,y);
	}
}
int getlca(int x,int y){
	while (top[x]^top[y])
		if (dep[top[x]]<dep[top[y]]) y=fat[top[y]];
		else x=fat[top[x]];
	return dep[x]<dep[y]?x:y;
}

void solve(){
	n=read(),q=read();
	rep(i,1,n) b[i]=getrand();
	rep(i,1,n) a[i]=read();
	rep(i,1,n-1){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0,1); dfs2(1,1);
	while (q--){
		int u=read(),v=read(),l=read(),r=read();
		int lc=getlca(u,v),lcf=fat[lc];
		printf("%d\n",query(rt[u],rt[v],rt[lc],rt[lcf],1,n,l,r));
	}
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}