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
const int N = 2050;
int n,m,q,a[N],b[N];
/*int head[N],to[N],nxt[N],edgenum=1;
inline void addedge(int u, int v) {
	to[++edgenum]=v; nxt[edgenum]=head[u]; head[u]=edgenum;
}*/
struct yzr {
	char s[24];
	int bel[N],bel1[N],f[N];
	bool ok[N];
	inline int find(int x) {return f[x]==x?x:f[x]=find(f[x]);}
	inline void merge(int x, int y) {
		int fx=find(x),fy=find(y);
		if (fx<fy) f[fy]=fx; else f[fx]=fy;
	}
	inline void init() {		
		rep(i,1,q) {
			scanf("%s",s); int p,l; read(p);read(l);
			rep(i,1,l) {int x;read(x);bel[x]=p;}
			bel1[i]=p;
		}
		rep(i,1,n) f[i]=i;
	}
	inline void solve() {
		rep(j,1,m) rep(i,1,m) if (!ok[i]&&(find(bel[i])==find(a[i])||find(bel[i])==find(b[i]))) {
			ok[i]=1; merge(a[i],b[i]);
		}
		rep(i,1,m) bel[i]=find(bel[i]);
		rep(i,1,q) bel1[i]=find(bel1[i]);
	}
} one,two;
int main() {
	read(n); read(m); read(q);
	rep(i,1,m) {
	//	int x,y;read(x);read(y);
	//	addedge(x,y);addedge(y,x);
		read(a[i]);read(b[i]);
	}
	one.init(); two.init();
	one.solve(); two.solve();
	rep(i,1,m) if (one.ok[i]^two.ok[i]) {puts("NO"); return 0;}
	rep(i,1,m) if (one.bel[i]!=two.bel[i]) {puts("NO"); return 0;}
	rep(i,1,q) if (one.bel1[i]!=two.bel1[i]) {puts("NO"); return 0;}
	puts("YES"); return 0;
}