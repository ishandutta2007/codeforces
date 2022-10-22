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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, k, d, who = 1, Ans = 1, bad;
int a[MAXN], g[MAXN][20];
int stkmn[MAXN], stkmx[MAXN], topmn, topmx;
int tag[MAXN << 2], mn[MAXN << 2];
map<int, int> buk;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int qgcd(int l, int r) {
	if(l == r) return 0;
	--r; int len = __lg(r - l + 1);
	return __gcd(g[l][len], g[r - (1 << len) + 1][len]);
}

void push(int x, int v) { tag[x] += v, mn[x] += v; }

void pushup(int x) { mn[x] = min(mn[x << 1], mn[x << 1 | 1]); }

void pushdown(int x) {
	if(!tag[x]) return;
	push(x << 1, tag[x]), push(x << 1 | 1, tag[x]); tag[x] = 0;
}

void update(int x, int l, int r, int L, int R, int v) {
	if(L <= l && r <= R) return push(x, v), void();
	int mid = (l + r) >> 1; pushdown(x);
	if(L <= mid) update(x << 1, l, mid, L, R, v);
	if(R > mid) update(x << 1 | 1, mid + 1, r, L, R, v);
	pushup(x);
}

int query(int x, int l, int r, int L, int R, int v) {
	if((r < L || l > R) || mn[x] > v) return -1;
	if(l == r) return l;
	int mid = (l + r) >> 1, res = -1; pushdown(x);
	if(L <= mid) res = query(x << 1, l, mid, L, R, v);
	if(~res) return res;
	return query(x << 1 | 1, mid + 1, r, L, R, v);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(k), read(d); // check for d = 0.
	for(int i = 1; i <= n; ++i) read(a[i]);
	if(n == 1) return puts("1 1"), 0;
	if(d == 0) {
		for(int L = 1, R = 1; L <= n; L = R + 1) {
			R = L;
			while(R < n && a[R + 1] == a[L]) ++R;
			if(R - L + 1 > Ans) Ans = R - L + 1, who = L;
		}
		printf("%lld %lld\n", who, who + Ans - 1);
		return 0;
	}
	for(int i = 1; i < n; ++i) g[i][0] = abs(a[i + 1] - a[i]);
	for(int p = 1; p < 20; ++p)
		for(int i = 1, j; i + (1 << p) - 1 < n; ++i) {
			j = i + (1 << (p - 1));
			g[i][p] = __gcd(g[i][p - 1], g[j][p - 1]);
		}
	for(int R = 1, L = 1, s; R <= n; ++R) {
		assert(L <= R);
		bad += ((buk[a[R]]++) == 1);
		while(L < R && (bad || qgcd(L, R) % d)) { bad -= ((--buk[a[L]]) == 1); ++L; }
		while(topmn && a[stkmn[topmn]] > a[R]) {
			update(1, 1, n, stkmn[topmn - 1] + 1, stkmn[topmn], a[stkmn[topmn]]);
			topmn--;
		}
		while(topmx && a[stkmx[topmx]] < a[R]) {
			update(1, 1, n, stkmx[topmx - 1] + 1, stkmx[topmx], -a[stkmx[topmx]]);
			topmx--;
		}
		update(1, 1, n, stkmn[topmn] + 1, R, -a[R]); stkmn[++topmn] = R;
		update(1, 1, n, stkmx[topmx] + 1, R, a[R]); stkmx[++topmx] = R;
		update(1, 1, n, R, R, d * R);
		s = query(1, 1, n, L, R, d * (k + R));
		if(s == -1) continue;
		assert(L <= s && s <= R);
		if(R - s + 1 > Ans) Ans = R - s + 1, who = s;
	}
	printf("%lld %lld\n", who, who + Ans - 1);
	return 0;
}