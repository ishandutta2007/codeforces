#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 505000;
struct Bit {
	int n,v1[N];ll v2[N];
	inline void clr(int x) {memset(v1,0,sizeof(v1));memset(v2,0,sizeof(v2)); n=x;}
	inline void add(int p, int x) {
		int s=p-1;
		while (p<=n) {
			v1[p]+=x; v2[p]-=x*s; p+=p&-p;
		}
	}
	inline ll query(int p) {
		int res1=0;ll res2=0,i=p;
		while (p) {
			res1+=v1[p]; res2+=v2[p];
			p-=p&-p;
		}
		return (ll)i*res1+res2;
	}
} tree;
inline void mdy(int x,int y){
	tree.add(x,1); tree.add(y+1,-1);
}
inline ll qry(int x, int y){
	return tree.query(y)-tree.query(x-1);
}
 
int top[N],n,fa[N],dep[N],sz[N],son[N],dfn[N],idfn[N],num;Vi e[N];
int id[N];ll ans[N];
void dfs1(int u, int Dep){
	sz[u]=1;dep[u]=Dep;
	rep(i,0,SZ(e[u])-1){
		dfs1(e[u][i],Dep+1);sz[u]+=sz[e[u][i]];
		if(sz[e[u][i]]>sz[son[u]])son[u]=e[u][i];
	}
}
void dfs2(int u, int Top){
	top[u]=Top;dfn[u]=++num;idfn[num]=u;
	if(son[u])dfs2(son[u],Top);
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=son[u])dfs2(e[u][i],e[u][i]);
}
bool cmp(int x, int y){return dep[x]<dep[y];}
inline void MODIFY(int u){
	while(u){
		mdy(dfn[top[u]],dfn[u]);u=fa[top[u]];
	}
}
inline ll QUERY(int u){
	ll res=0;
	while(u){
		res+=qry(dfn[top[u]],dfn[u]);u=fa[top[u]];
	}
	return res;
}
int main() {
	read(n);rep(i,1,n)read(fa[i]),e[fa[i]].pb(i);tree.clr(n);
	int rt=0;rep(i,1,n)if(!fa[i])rt=i;
	dfs1(rt,1);dfs2(rt,rt);rep(i,1,n)id[i]=i;
	sort(id+1,id+n+1,cmp);
	rep(i,1,n){
		int j=i;for(;j<=n;j++)if(dep[id[j]]!=dep[id[i]])break;
		rep(k,i,j-1)MODIFY(id[k]);
		rep(k,i,j-1)ans[id[k]]=QUERY(id[k]);
		i=j-1;
	}
	rep(i,1,n)printf("%lld ",ans[i]-dep[i]);
	return 0;
}