//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define popc(x) __builtin_popcount(x)
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
#define y1 _y1

const int MAXN = 1e5 + 10;
const int SIZ = 820;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, siz, cnt;
int b[MAXN], pos[MAXN], L[SIZ], R[SIZ], seq[SIZ][SIZ], tot[SIZ];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

struct treap {
	int rt, cnt;
	int ls[SIZ], rs[SIZ], rnk[SIZ], siz[SIZ], val[SIZ], tag[SIZ];
	int New(int x) {
		++cnt; val[cnt] = x; siz[cnt] = 1;
		rnk[cnt] = rand(); return cnt;
	}
	void pushup(int x) { siz[x] = siz[ls[x]] + siz[rs[x]] + 1; }
	void push(int x, int v) { if(x) { tag[x] += v, val[x] += v; } }
	void pushdown(int x) { if(tag[x]) push(ls[x], tag[x]), push(rs[x], tag[x]), tag[x] = 0; }
	void split(int x, int &a, int &b, int k) {
		if(!x) return a = b = 0, void();
		pushdown(x);
		if(val[x] <= k) a = x, split(rs[x], rs[a], b, k);
		else b = x, split(ls[x], a, ls[b], k);
		pushup(x);
	}
	int merge(int &x, int a, int b) {
		if(!a || !b) return x = (a | b);
		pushdown(a), pushdown(b);
		if(rnk[a] < rnk[b]) x = a, merge(rs[x], rs[a], b);
		else x = b, merge(ls[x], a, ls[b]);
		pushup(x); return x;
	}
	void Insert(int v) {
		int a = 0, b = 0; split(rt, a, b, v);
		merge(rt, merge(a, a, New(v)), b);
	}
	void clear() {
		for(int i = 1; i <= cnt; ++i)
			val[i] = siz[i] = rnk[i] = ls[i] = rs[i] = tag[i] = 0;
		cnt = rt = 0;
	}
	void Grab(int x, int id) {
		pushdown(x);
		if(ls[x]) Grab(ls[x], id);
		seq[id][++tot[id]] = val[x];
		if(rs[x]) Grab(rs[x], id);
	}
} B;

void build(int x) {
	B.clear();
	for(int i = R[x], s1, s2; i >= L[x]; --i) {
		s1 = s2 = 0;
		B.split(B.rt, s1, s2, b[i]); B.push(s2, -1); 
		B.merge(B.rt, s1, s2); B.Insert(b[i]);
	} tot[x] = 0; B.Grab(B.rt, x);
}

int query(int x) {
	int cur = b[x];
	for(int i = x + 1; i <= R[pos[x]]; ++i)
		if(b[i] <= cur) ++cur;
	for(int i = pos[x] + 1, p; i <= cnt; ++i) {
		p = upper_bound(seq[i] + 1, seq[i] + tot[i] + 1, cur) - seq[i] - 1;
		cur += p;
	}
	return cur;
}

void solve() {
	int opt, x, y; read(opt), read(x);
	if(opt == 1) { read(y); b[x] = x - y; build(pos[x]); } 
	else printf("%d\n", query(x));
}

signed main () {
#ifdef FILE
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
#endif
	read(n); siz = 150; cnt = (n + siz - 1) / siz;
	for(int i = 1; i <= n; ++i) read(b[i]), b[i] = i - b[i];
	for(int i = 1; i <= cnt; ++i) {
		L[i] = (i - 1) * siz + 1, R[i] = min(n, i * siz);
		for(int j = L[i]; j <= R[i]; ++j) pos[j] = i;
		build(i);
	}
	read(m);
	while(m--) solve();
	return 0;
}