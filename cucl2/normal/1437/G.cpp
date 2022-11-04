/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */
 
const int QwQ = 1 << 19;
int N, M;
int to[QwQ][26], T = 1, fail[QwQ];
char tmp[QwQ];
vector<int> nei[QwQ];
int szi[QwQ], bgi[QwQ], tmi[QwQ];
int fa[QwQ];
int it[QwQ], tmc, ti[QwQ];
int tpi[QwQ], dy[QwQ];
 
void inline dfs(int now) {
	szi[now] = 1;
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		fa[to] = now;
		dfs(to);
		szi[now] += szi[to];
		if(!bgi[now] || szi[bgi[now]] < szi[to]) {
			bgi[now] = to;
		}
	}
}
 
void inline dft(int now, int top) {
	it[now] = ++tmc; ti[tmc] = now;
	tpi[now] = top;
	if(bgi[now]) dft(bgi[now], top);
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		if(to == bgi[now]) continue;
		dft(to, to);
	}
}
 
struct Segtree {
	ll dt[QwQ << 1];
	void inline init() {memset(dt, -1, sizeof(dt));}
	void inline add(int a, int x) {
		a += QwQ; dt[a] = x;
		while(a >>= 1) dt[a] = max(dt[a << 1], dt[a << 1 | 1]);
	}
	ll inline get(int l, int r) {
		ll res = -1;
		for(l += QwQ, r += QwQ + 1; l < r; l >>= 1, r >>= 1) {
			if(l & 1) res = max(res, dt[l++]);
			if(r & 1) res = max(res, dt[--r]);
		}
		return res;
	}
} sgt;
 
ll inline getval(int now) {
	ll res = -1;
	while(~now) {
		int up = tpi[now];
		res = max(res, sgt.get(it[up], it[now]));
		now = fa[up];
	}
	return res;
}
 
int main() {
	scanf("%d%d", &N, &M);
	cont(i, N) {
		scanf("%s", tmp);
		int now = 0;
		for(int i = 0; tmp[i]; ++i) {
			int ch = tmp[i] - 'a';
			if(!to[now][ch]) to[now][ch] = T++;
			now = to[now][ch];
		}
		tmi[i] = now;
	}
	// Build AC Automaton
	queue<int> q;
	loop(i, 26) if(to[0][i]) {
		q.push(to[0][i]);
	}
	while(SZ(q)) {
		int now = q.front(); q.pop();
		loop(i, 26) {
			if(to[now][i]) {
				fail[to[now][i]] = to[fail[now]][i];
				q.push(to[now][i]);
			} else {
				to[now][i] = to[fail[now]][i];
			}
		}
	}
	cont(i, N) {
		if(!dy[tmi[i]]) {
			dy[tmi[i]] = i;
		} else {
			int clone = T++;
			int nt = dy[tmi[i]];
			fail[clone] = fail[tmi[i]];
			fail[tmi[i]] = clone;
			tmi[nt] = clone;
			dy[clone] = nt;
			dy[tmi[i]] = i;
		}
	}
	cont(i, T - 1) nei[fail[i]].pub(i);
	// HLD
	fa[0] = -1;
	dfs(0); dft(0, 0);
	sgt.init();
	cont(i, N) {
		int ter = tmi[i];
		sgt.add(it[ter], 0);
	}
	while(M--) {
		int mode; scanf("%d", &mode);
		if(mode == 1) {
			int i, x; scanf("%d%d", &i, &x);
			sgt.add(it[tmi[i]], x);
		} else {
			scanf("%s", tmp);
			int now = 0; ll res = -1;
			for(int i = 0; tmp[i]; ++i) {
				now = to[now][tmp[i] - 'a'];
				res = max(res, getval(now));
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
 
/**
 * 30min
 * 1.5h
 * 
 *   AC  Fail 
 *   Fail  HLD
 *  
 *  
 *  
 */