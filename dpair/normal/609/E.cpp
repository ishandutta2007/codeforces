#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int UI;

template <typename T>
inline void read(T &x){
	x = 0;int fu = 1;
	char c = getchar();
	while(c > 57 || c < 48){
		if(c == 45) fu = -1;
		c = getchar();
	}
	while(c <= 57 && c >= 48){
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	x *= fu;
}
template <typename T>
inline void fprint(T x){
	if(x < 0) putchar(45), x = -x;
	if(x > 9) fprint(x / 10);
	putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
	fprint(x);putchar(ch);
}
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}
int n, m;
int head[200010], e[400010], val[400010], nxt[400010], cnt;

inline void add(int u, int v, int w){
	nxt[++ cnt] = head[u];
	head[u] = cnt;
	e[cnt] = v;
	val[cnt] = w;
}

struct EDGE{
	int u, v, w;
    int id;
	inline bool operator < (const EDGE &tmp) const{return w < tmp.w;}
}ed[200010];
LL ans = 0;
namespace Kruscal{
	int tot;int fa[200010];
	int find(int x){
		if(fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	inline void init(){
		for (register int i = 1;i <= n;i ++) fa[i] = i;
		tot = n;
	}
	inline void work(){
		sort(ed + 1, ed + m + 1);
		for (register int i = 1;i <= m;i ++){
			int uu = ed[i].u, vv = ed[i].v;
			int xx = find(uu), yy = find(vv);
			if(xx ^ yy){
				tot --;fa[xx] = yy;
				add(uu, vv, ed[i].w);
				add(vv, uu, ed[i].w);
                ans += ed[i].w;
			}
			if(tot == 1) break;
		}
	}
}
namespace LCA{
	inline bool Link(int x, int y){
		return Kruscal :: find(x) == Kruscal :: find(y);
	}
	int dep[200010], pa[200010][21], dp[200010][21];
	bool vis[200010];
	void build(int rt){
		vis[rt] = true;
		for (register int i = head[rt];i;i = nxt[i]){
			if(vis[e[i]]) continue;
			pa[e[i]][0] = rt;dp[e[i]][0] = val[i];
			dep[e[i]] = dep[rt] + 1;
			for (register int j = 1;j <= 20;j ++){
				pa[e[i]][j] = pa[pa[e[i]][j - 1]][j - 1];
				dp[e[i]][j] = mx(dp[e[i]][j - 1], dp[pa[e[i]][j - 1]][j - 1]);
			}
			build(e[i]);
		}
	}
	inline void init(){
		for (register int i = 1;i <= n;i ++){
			if(!vis[i]) dep[i] = 1, build(i);
		}
	}
	inline int solve(int x, int y){
		if(dep[x] < dep[y]) swap(x, y);
		int minx = -0x3f3f3f3f, miny = -0x3f3f3f3f;
		for (register int i = 20;i >= 0;i --){
			if(dep[x] - (1 << i) >= dep[y]){
				chmax(minx, dp[x][i]);
				x = pa[x][i];
			}
			if(dep[x] == dep[y]) break;
		}
		if(x == y) return mx(minx, miny);
		for (register int i = 20;i >= 0;i --){
			if(pa[x][i] ^ pa[y][i]){
				chmax(minx, dp[x][i]);chmax(miny, dp[y][i]);
				x = pa[x][i];y = pa[y][i];
			}
		}
		chmax(minx, dp[x][0]);chmax(miny, dp[y][0]);
		return mx(minx, miny);
	}
}

inline bool cmp (EDGE tmp1, EDGE tmp2){return tmp1.id < tmp2.id;}

int main(){
	read(n);read(m);
	for (register int i = 1;i <= m;i ++) read(ed[i].u), read(ed[i].v), read(ed[i].w), ed[i].id = i;
	Kruscal :: init();
	Kruscal :: work();
	LCA :: init();
    sort(ed + 1, ed + m + 1, cmp);
	for (register int i = 1;i <= m;i ++){
        int num = LCA ::solve(ed[i].u, ed[i].v);
        fprint(ans + ed[i].w - num, 10);
    }
	return 0;
}