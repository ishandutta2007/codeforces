#include <iomanip>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 600010
#define Dollar1 1000000007
int sz1[MAXN], sz2[MAXN], sz3[MAXN], fail[MAXN], nxt[MAXN][26], last, now, tot, v, p, t, R[MAXN], buc[MAXN], rk[MAXN], ans[MAXN];
#define LL(X) ((long long)(X))
inline int up(int x) { if (x >= Dollar1) return x - Dollar1; return x; }
inline int down(int x) { if (x < 0) return x + Dollar1; return x; }
inline void add(int & x, int y) { x = up(x + y); }
inline void dec(int & x, int y) { x = down(x - y); }
void insert(int x, int * sz) {
	R[now = ++tot] = R[p = last] + 1; sz[last = now] = 1;
	for (; p && !nxt[p][x]; p = fail[p]) nxt[p][x] = now;
	if (!p) fail[now] = 1;
	else {
		t = nxt[p][x];
		if (R[p] + 1 == R[t]) fail[now] = t;
		else {
			R[v = ++tot] = R[p] + 1;
			memcpy(nxt[v], nxt[t], sizeof(int) * 26);
			fail[v] = fail[t]; fail[t] = fail[now] = v;
			for (; p && nxt[p][x] == t; p = fail[p]) nxt[p][x] = v;
		}
	}
}
char buf[MAXN], *cur;
namespace Graph {
	int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
	void addedge(int b, int e) { nxt[++tot] = head[b]; head[b] = tot; to[tot] = e; }
	void dfs(int u) {
		for (int i = head[u]; i; i = nxt[i]) {
			dfs(to[i]);
			sz1[u] += sz1[to[i]];
			sz2[u] += sz2[to[i]];
			sz3[u] += sz3[to[i]];
		}
	}
}
int main() {
	int len = 0, maxl = 0x3f3f3f3f;
	last = tot = 1;
	scanf("%s", buf); cur = buf; len = 0;
	while (*cur) insert(*cur++ - 'a', sz1), ++len;
	maxl = min(maxl, len);
	last = 1;
	scanf("%s", buf); cur = buf; len = 0;
	while (*cur) insert(*cur++ - 'a', sz2), ++len;
	maxl = min(maxl, len);
	last = 1;
	scanf("%s", buf); cur = buf; len = 0;
	while (*cur) insert(*cur++ - 'a', sz3), ++len;
	maxl = min(maxl, len);
	for (int i = 2; i <= tot; ++i) Graph::addedge(fail[i], i);
	Graph::dfs(1);
	for (int i = 1; i <= tot; ++i) {
		if (sz1[i] && sz2[i] && sz3[i]) {
			int tv = LL(sz1[i]) * sz2[i] % Dollar1 * sz3[i] % Dollar1;
			add(ans[R[fail[i]] + 1], tv);
			dec(ans[R[i] + 1], tv);
		}
	}
	for (int i = 1; i <= maxl; ++i) add(ans[i], ans[i - 1]), printf("%d ", ans[i]); putchar(10);
	return 0;
}