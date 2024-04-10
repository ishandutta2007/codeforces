#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 205000;
int n,q,a[N],head[N],to[N],edgenum,nxt[N];
inline void addedge(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}
int dep[N],fa256[N],fa[N],dp[N][200],mx;
inline void dfs(int u, int Fa, int Dep) {
	dep[u]=Dep; fa[u]=Fa; mx=max(mx,Dep);
	L(i,u) if (to[i]!=Fa) dfs(to[i],u,Dep+1);
}
struct Trie {
	int ch[50000][2],val[50000],cnt[50000],f[50000],sz;
	inline void init() {
		while (sz>=0) {ch[sz][0]=ch[sz][1]=val[sz]=cnt[sz]=f[sz]=0; sz--;} sz=0;
	}
	inline void ins(int x) {
		int now=0,Val=x; x>>=8;
		per(i,7,0) {
			int c=(x>>i)&1;
			if (!ch[now][c]) {ch[now][c]=++sz; f[sz]=now;}
			now=ch[now][c]; cnt[now]++;
		}
		val[now]=max(val[now],Val);
	}
	inline void solve(int u, int mx) {
		int now=0; 
		per(i,7,0) if (cnt[ch[now][1]]) now=ch[now][1]; else now=ch[now][0];
		rep(i,0,mx) {
			dp[u][i]=val[now]^(i<<8);
			rep(c,0,7) if (!((i>>c)&1)) { //c+1
				rep(j,0,c) now=f[now];
				if (cnt[ch[now][0]]) now=ch[now][0]; else now=ch[now][1];
				per(j,c,1) if (cnt[ch[now][1]]) now=ch[now][1]; else now=ch[now][0];
				break;
			}
		}
	}
} trie;
inline void solve(int u) {
	trie.init(); for (int i=u,cnt=0; cnt<256; cnt++,i=fa[i]) trie.ins(a[i]^cnt); //WA1. i=fa[i]; WA2. ^=cnt
	trie.solve(u,mx); int v=u; rep(i,1,256) v=fa[v]; fa256[u]=v;
}
inline int query(int u, int v) {
	int res=0,c=0,k=0;
	while (dep[v]-dep[u]>=256) {res=max(res,dp[v][c]); c++; v=fa256[v];}
	while (dep[u]<=dep[v]) {res=max(res,a[v]^(c*256+k)); v=fa[v]; k++;}
	return res;
}
int main() { //freopen("1.in","r",stdin);
	read(n);read(q);rep(i,1,n)read(a[i]);
	rep(i,2,n){int x,y;read(x);read(y);addedge(y,x);addedge(x,y);}
	dfs(1,0,1); mx>>=8; rep(i,1,n) if (dep[i]>=256) solve(i);
	while (q--) {
		int u,v;read(u); read(v); printf("%d\n",query(u,v));
	}
	return 0;
}