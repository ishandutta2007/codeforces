//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define inv(x) qpow((x), mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define ull unsigned long long
#define pii pair<int, int>
#define LL long long
#define mp make_pair
#define pb push_back
#define scd second
#define vec vector
#define fst first
#define endl '\n'

const int MAXN = 5e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct EDGE {
	int head[MAXN], siz;
	int nxt[MAXN << 1], to[MAXN << 1], w[MAXN << 1];
	void _add(int x, int y, int _w) {
		nxt[++siz] = head[x];
		to[siz] = y, w[siz] = _w, head[x] = siz;
	}
	void add(int x, int y, int _w) {_add(x, y, _w); _add(y, x, 0);}
} e;

int n, m, r, b, cnt, s, t, S, T;
int tot[MAXN], d[MAXN], chk[MAXN], type[MAXN];
int lim[MAXN], Ans;
map<int, int> mpx, mpy;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

namespace Flow {
	int dep[MAXN], cur[MAXN];
	queue<int> Q;
	bool BFS() {
		while(Q.size()) Q.pop();
		memset(dep, 0, sizeof dep); dep[S] = 1, Q.push(S);
		memcpy(cur, e.head, sizeof cur);
		while(Q.size()) {
			int x = Q.front(); Q.pop();
			for(int i = e.head[x], to; i; i = e.nxt[i]) {
				to = e.to[i];
				if(dep[to] || !e.w[i]) continue;
				dep[to] = dep[x] + 1; Q.push(to);
				if(to == T) return true;
			}
		}
		return false;
	}
	int DFS(int x, int flow) {
		if(x == T || !flow) return flow;
		int res = flow;
		for(int i = cur[x], to; i && res; i = e.nxt[i]) {
			to = e.to[i], cur[x] = i;
			if(dep[to] != dep[x] + 1 || !e.w[i]) continue;
			int k = DFS(to, min(res, e.w[i]));
			if(!k) dep[to] = 0;
			e.w[i] -= k, e.w[i ^ 1] += k, res -= k;
		}
		return flow - res;
	}
	int Dinic() {
		int res = 0, flow = 0;
		while(BFS()) {
			flow = DFS(S, INF);
			while(flow) res += flow, flow = DFS(S, INF);
		}
		return res;
	}
}

using Flow :: Dinic;

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(m), read(r), read(b), e.siz = 1; cnt = n;
	s = ++cnt; t = ++cnt;
	for(int i = 1, x, y; i <= n; ++i) {
		read(x), read(y);
		if(!mpx[x]) mpx[x] = ++cnt, type[cnt] = 1;
		if(!mpy[y]) mpy[y] = ++cnt, type[cnt] = 2;
		tot[mpx[x]]++, tot[mpy[y]]++;
		e.add(mpx[x], mpy[y], 1); chk[i] = e.siz;
	}
	memset(lim, 0x3f, sizeof lim);
	for(int i = 1, opt, l, d; i <= m; ++i) {
		read(opt), read(l), read(d);
		if(opt == 1 && mpx[l]) lim[mpx[l]] = min(lim[mpx[l]], d);
		if(opt == 2 && mpy[l]) lim[mpy[l]] = min(lim[mpy[l]], d);
	}
	for(int i = t + 1, all, l, r; i <= cnt; ++i) {
		all = tot[i]; r = (all + lim[i]) / 2, l = (all - lim[i] + 1) / 2;
		l = max(l, 0ll), r = min(r, all);
		if(l > r) return puts("-1"), 0;
		if(type[i] == 1) e.add(s, i, r - l), d[s] -= l, d[i] += l;
		if(type[i] == 2) e.add(i, t, r - l), d[i] -= l, d[t] += l;
	}
	int full = 0;
	S = ++cnt, T = ++cnt;
	for(int i = 1; i <= cnt - 2; ++i) {
		if(d[i] > 0) e.add(S, i, d[i]), full += d[i];
		if(d[i] < 0) e.add(i, T, -d[i]);
	}
	e.add(t, s, INF);
	if(Dinic() != full) return puts("-1"), 0;
	Ans = e.w[e.siz]; e.w[e.siz] = e.w[e.siz ^ 1] = 0;
	S = s, T = t; Ans += Dinic();
	printf("%lld\n", max(r, b) * n - Ans * abs(r - b));
	for(int i = 1; i <= n; ++i) {
		if(e.w[chk[i]]) putchar(r < b ? 'r' : 'b');
		else putchar(r < b ? 'b' : 'r');
	}
	return 0;
}