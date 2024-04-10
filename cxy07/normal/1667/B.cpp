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

const int MAXN = 2e6 + 10;
const int INF = 2e9;
const int V = 1e15;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

struct SGT {
	int mx[MAXN << 2];
	void update(int x, int l, int r, int p, int v) {
		mx[x] = max(mx[x], v);
		if(l == r) return;
		int mid = (l + r) >> 1;
		if(p <= mid) update(x << 1, l, mid, p, v);
		else update(x << 1 | 1, mid + 1, r, p, v);
	}
	int query(int x, int l, int r, int L, int R) {
		if(L > R) return -INF;
		if(L <= l && r <= R) return mx[x];
		int mid = (l + r) >> 1, res = -INF;
		if(L <= mid) res = max(res, query(x << 1, l, mid, L, R));
		if(R > mid) res = max(res, query(x << 1 | 1, mid + 1, r, L, R));
		return res;
	}
	void build(int x, int l, int r) {
		mx[x] = -INF;
		if(l == r) return;
		int mid = (l + r) >> 1;
		build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
	}
} T1, T2;

int T, n, m, rt, a[MAXN], tcnt;
map<int, int> mmp;
vec<int> des;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int Id(int x) {
	return lower_bound(des.begin(), des.end(), x) - des.begin() + 1;
}

void solve() {
	read(n); mmp.clear(), des.clear();
	for(int i = 1; i <= n; ++i) read(a[i]);
	mmp[0] = 0;
	des.pb(0);
	for(int i = 1, s = 0; i <= n; ++i) { 
		s += a[i]; des.pb(s);
		des.pb(s + 1), des.pb(s - 1); 
	}
	sort(des.begin(), des.end());
	des.erase(unique(des.begin(), des.end()), des.end());
	m = des.size();
	T1.build(1, 1, m), T2.build(1, 1, m);
	T1.update(1, 1, m, Id(0), 0), T2.update(1, 1, m, Id(0), 0);
	//T1 : v - i, T2 : v + i 
	for(int i = 1, s = 0, v; i <= n; ++i) {
		s += a[i], v = -INF;
		if(mmp.count(s)) v = mmp[s];
		int p = Id(s - 1);
		v = max(v, T1.query(1, 1, m, 1, p) + i);
		p = Id(s + 1);
		v = max(v, T2.query(1, 1, m, p, m) - i);
		if(!mmp.count(s)) mmp[s] = v;
		else mmp[s] = max(mmp[s], v);
		p = Id(s);
		T1.update(1, 1, m, p, v - i);
		T2.update(1, 1, m, p, v + i);
		if(i == n) printf("%lld\n", v);
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}