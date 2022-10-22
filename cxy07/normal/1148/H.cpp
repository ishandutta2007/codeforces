//Code By CXY07 - It's My Fiesta.
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
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

const int MAXN = 8e5 + 10;
const int SIZ = 2e7 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct SGT {
	int mn[MAXN << 2];
	void update(int x, int l, int r, int p, int v) {
		if(l == r) return mn[x] = v, void();
		int mid = (l + r) >> 1;
		if(p <= mid) update(x << 1, l, mid, p, v);
		else update(x << 1 | 1, mid + 1, r, p, v);
		mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
	}
	int find_mex(int x, int l, int r, int p) {
		if(l == r) return l;
		int mid = (l + r) >> 1;
		if(mn[x << 1] < p) return find_mex(x << 1, l, mid, p);
		else return find_mex(x << 1 | 1, mid + 1, r, p);
	}
} mexT;

struct PSEG {
	signed rt[MAXN], tcnt, ls[SIZ], rs[SIZ];
	int ts[SIZ], sum[SIZ], tc[SIZ], cnt[SIZ];
	void pushup(int x) { sum[x] = sum[ls[x]] + sum[rs[x]]; cnt[x] = cnt[ls[x]] + cnt[rs[x]]; }
	void update(signed &x, int pre, int l, int r, int L, int R, int vc, int vs) {
		x = ++tcnt; 
		ls[x] = ls[pre], rs[x] = rs[pre], cnt[x] = cnt[pre];
		sum[x] = sum[pre], ts[x] = ts[pre], tc[x] = tc[pre];
		if(L <= l && r <= R) {
			tc[x] += vc, cnt[x] += (r - l + 1) * vc;
			ts[x] += vs, sum[x] += (r - l + 1) * vs;
			return;
		}
		int mid = (l + r) >> 1;
		if(L <= mid) update(ls[x], ls[pre], l, mid, L, R, vc, vs);
		if(R > mid) update(rs[x], rs[pre], mid + 1, r, L, R, vc, vs);
		pushup(x);
	}
	int query(int x, int l, int r, int L, int R, int o) {
		if(!x) return 0;
		if(L <= l && r <= R) return sum[x] - o * cnt[x];
		int mid = (l + r) >> 1, res = 0;
		res = ts[x] * (min(R, r) - max(L, l) + 1);
		res -= o * tc[x] * (min(R, r) - max(L, l) + 1);
		if(L <= mid) res += query(ls[x], l, mid, L, R, o);
		if(R > mid) res += query(rs[x], mid + 1, r, L, R, o);
		return res;
	}
} T;

int n, m, lastans;
int pos[MAXN], mexL[MAXN], mexR[MAXN], rtc;
map<int, int> idx[MAXN]; // idx[col][loc] : rt_id

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void add_mex(int mex, int l, int r, int t, int o) {
	if(!idx[mex].count(t)) {
		int pre = (idx[mex].size()) ? prev(idx[mex].end())->scd : 0;
		idx[mex][t] = ++rtc; T.rt[rtc] = T.rt[pre];
	}
	int p = idx[mex][t];
	T.update(T.rt[p], T.rt[p], 1, n, l, r, o, o * (n - t + 1));
}

void update_mex(int id, int s) {
	mexT.update(1, 0, n, s, id), pos[s] = id;
	if(mexL[s]) {
		int cur = mexR[s], lim = mexL[s];
		add_mex(s, mexL[s], mexR[s], id, -1);
		mexL[s] = mexR[s] = 0;
		while(cur >= lim) {
			int mex = mexT.find_mex(1, 0, n, cur), p;
			if(mexL[mex]) { 
				p = mexR[mex] + 1; mexR[mex] = cur;
				add_mex(mex, p, cur, id, 1); break; 
			} else { 
				mexR[mex] = cur, mexL[mex] = pos[mex] + 1, cur = pos[mex]; 
				add_mex(mex, mexL[mex], mexR[mex], id, 1); 
			}
		}
	}
	int v = (s ? 0 : 1);
	if(mexL[v]) add_mex(v, mexR[v] + 1, id, id, 1);
	else mexL[v] = id, add_mex(v, id, id, id, 1);
	mexR[v] = id;
}

int calc(int l, int r, int k) {
	if(!idx[k].size()) return 0;
	int res = 0;
	auto it = idx[k].upper_bound(r);
	if(it != idx[k].begin()) res += T.query(T.rt[prev(it)->scd], 1, n, l, r, n - r);
	it = idx[k].upper_bound(l - 1);
	if(it != idx[k].begin()) res -= T.query(T.rt[prev(it)->scd], 1, n, l, r, n - l + 1);
	return res;
}

void solve(int id) {
	int a, l, r, k; read(a), read(l), read(r), read(k);
	a = (a + lastans) % (n + 1), k = (k + lastans) % (n + 1); 
	l = (l + lastans) % id + 1, r = (r + lastans) % id + 1; if(l > r) swap(l, r);
	update_mex(id, a); lastans = calc(l, r, k);
	printf("%lld\n", lastans);
}

signed main () {
#ifdef FILE
	freopen("CF1148H.in", "r", stdin);
	freopen("CF1148H.out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) solve(i);
	return 0;
}