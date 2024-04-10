#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return a > val ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}

struct SuffixArray {
	static const int MAXN = 1000010;
	char T[MAXN];
	int nsz;
	int RA[MAXN], tmpRA[MAXN];
	int SA[MAXN], tmpSA[MAXN];
	int c[MAXN];
	int Phi[MAXN], PLCP[MAXN];
	int LCP[MAXN];
	void init(char* str) {
		strcpy(T, str);
		nsz = strlen(T);
		for (int i = 0; i < nsz; i++) {
			RA[i] = tmpRA[i] = 0;
			SA[i] = tmpSA[i] = 0;
			Phi[i] = PLCP[i] = LCP[i] = 0;
		}
		constructSA();
		computeLCP();
	}
	void countingsort(int k) {
		int sum = 0, maxi = max(300, nsz);
		memset(c, 0, sizeof(c));
		for (int i = 0; i < nsz; i++) c[i + k < nsz ? RA[i + k] : 0]++;
		for (int i = 0; i < maxi; i++) {
			int t = c[i]; c[i] = sum; sum += t;
		}
		for (int i = 0; i < nsz; i++) tmpSA[c[SA[i] + k < nsz ? RA[SA[i] + k] : 0]++] = SA[i];
		for (int i = 0; i < nsz; i++) SA[i] = tmpSA[i];
	}
	void constructSA() {
		int r;
		for (int i = 0; i < nsz; i++) RA[i] = T[i];
		for (int i = 0; i < nsz; i++) SA[i] = i;
		for (int k = 1; k < nsz; k <<= 1) {
			countingsort(k);
			countingsort(0);
			tmpSA[SA[0]] = r = 0;
			for (int i = 1; i < nsz; i++) tmpRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
			for (int i = 0; i < nsz; i++) RA[i] = tmpRA[i];
			if (RA[SA[nsz - 1]] == nsz - 1) break;
		}
	}
	void computeLCP() {
		int L = 0;
		Phi[SA[0]] = -1;
		for (int i = 1; i < nsz; i++) Phi[SA[i]] = SA[i - 1];
		for (int i = 0; i < nsz; i++) {
			if (!~Phi[i]) {PLCP[i] = 0; continue;}
			while (T[i + L] == T[Phi[i] + L] && T[i + L] != '$') L++;
			PLCP[i] = L;
			L = max(L - 1, 0);
		}
		for (int i = 0; i < nsz; i++) LCP[i] = PLCP[SA[i]];
	}
} sa;

const int maxn = 1000010;
const int magic = 500;
int n, m, q;
char s[maxn];
char t[maxn];
int id[maxn];
pi ans[maxn];

struct Query {
	int x, y, l, r, idx;
	Query(int x, int y, int l, int r, int idx) : x(x), y(y), l(l), r(r), idx(idx) {}
	Query(const Query& rhs) : x(rhs.x), y(rhs.y), l(rhs.l), r(rhs.r), idx(rhs.idx) {}
	int operator < (const Query& rhs) {
		if (x / magic != rhs.x / magic) return x / magic < rhs.x / magic;
		return mp(y, idx) < mp(rhs.y, rhs.idx);
	}
};

vector<Query> que;

int f[maxn][25];
void build() {
	FOR(i, 0, n) f[i][0] = sa.LCP[i];
	for (int l = 0, k; (k = 1 << l) < n; l++) {
		for (int i = 0; i + k < n; i++) {
			f[i][l + 1] = min(f[i][l], f[i + k][l]);
		}
	}
}
int query(int a, int b) {
	int l = __lg(b - a);
	return min(f[a][l], f[b - (1 << l) + 1][l]);
}

int st[4 * maxn];
pi val[4 * maxn];
void build(int node, int L, int R) {
	if (L == R) {
		val[node] = mp(0, L);
		return;
	}
	build(node << 1, L, L + R >> 1);
	build((node << 1) + 1, (L + R >> 1) + 1, R);
	val[node] = min(val[node << 1], val[(node << 1) + 1]);
}
void update(int node, int i, int L, int R, int z) {
	if (i < L || i > R) return;
	if (L == R) {
		st[node] += z;
		val[node] = mp(-st[node], L);
		return;
	}
	update(node << 1, i, L, L + R >> 1, z);
	update((node << 1) + 1, i, (L + R >> 1) + 1, R, z);
	val[node] = min(val[node << 1], val[(node << 1) + 1]);
}
pi query(int node, int l, int r, int L, int R) {
	if (l > R || r < L) return mp(1, 0);
	if (l <= L && r >= R) return val[node];
	return min(query(node << 1, l, r, L, L + R >> 1), query((node << 1) + 1, l, r, (L + R >> 1) + 1, R));
}

void solve() {
	scanf("%s", s);
	n = strlen(s);
	s[n++] = '$';
	scanf("%d", &m);
	FOR(i, 1, m + 1) {
		scanf("%s", t);
		int k = strlen(t);
		FOR(j, 0, k) s[n] = t[j], id[n++] = i;
		s[n++] = '$';
	}
	sa.init(s); build(); build(1, 1, m);
	scanf("%d", &q);
	FOR(i, 0, q) {
		int l, r, pl, pr; scanf("%d%d%d%d", &l, &r, &pl, &pr); pl--; pr--;
		int x, y;
		int z = sa.RA[pl], k = pr - pl + 1;
		int lo = 0, hi = z;
		while (lo < hi) {
			int mi = lo + hi >> 1;
			if (query(mi, z) < k) lo = mi + 1; else hi = mi;
		}
		if (query(lo, z) >= k) x = lo - 1; else x = z;
		lo = z + 1, hi = n - 1;
		while (lo < hi) {
			int mi = lo + hi + 1 >> 1;
			if (query(z + 1, mi) >= k) lo = mi; else hi = mi - 1;
		}
		if (query(z + 1, lo) >= k) y = lo; else y = z;
		que.pb(Query(x, y, l, r, i));
	}
	sort(all(que));
	int u = 0, v = -1;
	FOR(i, 0, sz(que)) {
		int x = que[i].x;
		int y = que[i].y;
		int l = que[i].l;
		int r = que[i].r;
		while (u > x) {
			u--;
			int k = id[sa.SA[u]];
			if (k) update(1, k, 1, m, 1);
		}
		while (u < x) {
			int k = id[sa.SA[u]];
			if (k) update(1, k, 1, m, -1);
			u++;
		}
		while (v < y) {
			v++;
			int k = id[sa.SA[v]];
			if (k) update(1, k, 1, m, 1);
		}
		while (v > y) {
			int k = id[sa.SA[v]];
			if (k) update(1, k, 1, m, -1);
			v--;
		}
		ans[que[i].idx] = query(1, l, r, 1, m);
	}
	FOR(i, 0, q) cout<<ans[i].se<<" "<<-ans[i].fi<<"\n";
}

int main() {
//	ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}