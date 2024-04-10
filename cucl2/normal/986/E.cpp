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

template<int jt> struct ModInt {
	int x;
	ModInt(int v = 0) {x = v; if(x >= jt || x < 0) {x %= jt; if(x < 0) x += jt;}}
	ModInt(ll v) {x = v % jt; if(x < 0) x += jt;}
	operator int() const {return x;}
	friend inline ModInt &operator+=(ModInt &a, const ModInt &b) {a.x += b.x; if(a.x >= jt) a.x -= jt; return a;}
	friend inline ModInt operator+(ModInt a, const ModInt &b) {return a += b;}
	friend inline ModInt operator+(ModInt a, int b) {return a += ModInt(b);}
	friend inline ModInt operator+(int a, ModInt b) {return b += ModInt(a);}
	friend inline ModInt &operator++(ModInt &a) {return a += 1;}
	friend inline ModInt &operator-=(ModInt &a, const ModInt &b) {a.x -= b.x; if(a.x < 0) a.x += jt; return a;}
	friend inline ModInt operator-(ModInt a, const ModInt &b) {return a -= b;}
	friend inline ModInt operator-(ModInt a, int b) {return a -= ModInt(b);}
	friend inline ModInt operator-(int a, ModInt b) {return ModInt(a) - b;}
	friend inline ModInt &operator--(ModInt &a) {return a -= 1;}
	friend inline ModInt &operator*=(ModInt &a, const ModInt &b) {a.x = (ll)a.x * b.x % jt; return a;}
	friend inline ModInt operator*(ModInt a, const ModInt &b) {return a *= b;}
	friend inline ModInt operator*(ModInt a, int b) {return a *= ModInt(b);}
	friend inline ModInt operator*(int a, ModInt b) {return b *= ModInt(a);}
	static inline void exgcd(ll a, ll b, ll &x, ll &y) {b ? (exgcd(b, a % b, y, x), y -= a / b * x) : (x = 1, y = 0);}
	friend inline ModInt inv(const ModInt &a) {ll x, y; exgcd(a, jt, x, y); return x;}
	friend inline ModInt operator/(const ModInt &a, const ModInt &b) {return a * inv(b);}
	friend inline ModInt operator/(ModInt a, int b) {return a * inv(ModInt(b));}
	friend inline ModInt operator/(int a, ModInt b) {return ModInt(a) * inv(b);}
	friend inline ModInt operator/=(ModInt &a, const ModInt &b) {return a = a / b;}
};
const int jt = 1000000007;
typedef ModInt<jt> mint;

const int twt = 1e7 + 5, qwq = 1e6 + 5, iwi = 1 << 17;
int N, Q;
vector<int> nei[iwi];
int fa[20][iwi], lvl[iwi];
int a[iwi];
int sml[twt + 5], it[twt + 5], ti[qwq], mxt[qwq], cnt[qwq], ps;
int t[iwi], id1[iwi], id2[iwi], tm1, tm2;

void inline init() {
	circ(i, 2, twt) if(!sml[i]) {
		ti[++ps] = i;
		it[i] = ps;
		range(j, i, twt, i) if(!sml[j]) {
			sml[j] = i;
		}
	}
}

void inline dfs(int now, int lst) {
	fa[0][now] = lst;
	lvl[now] = lvl[lst] + 1;
	t[now] = ++tm1;
	loop(i, SZ(nei[now])) {
		int to = nei[now][i];
		if(to == lst) continue;
		dfs(to, now);
	}
	id1[now] = tm1;
	id2[now] = ++tm2;
}

int inline lca(int a, int b) {
	if(lvl[a] < lvl[b]) swap(a, b);
	int up = lvl[a] - lvl[b];
	while(up) a = fa[__builtin_ctz(up)][a], up &= up - 1;
	if(a == b) return a;
	range(i, 19, 0, -1) if(fa[i][a] != fa[i][b]) {
		a = fa[i][a], b = fa[i][b];
	}
	return fa[0][a];
}

vector<pair<int, int> > hvt[qwq], hvq[qwq];
int sm[iwi][4];
mint ans[iwi];
vector<mint> mii[qwq];

struct Fenwick {
	int dt[iwi];
	void inline add(int a, int x) {
		for(; a < iwi; a += a & -a) dt[a] += x;
	}
	int inline sum(int a) {
		int res = 0;
		for(; a; a -= a & -a) res += dt[a];
		return res;
	}
} b1, b2;

void inline Add(int a, int x) {
	b1.add(t[a], x);
	b2.add(id2[a], x);
}

int inline Get(int a) {
	if(!a) return 0;
	return b1.sum(id1[a]) - b2.sum(id2[a] - 1);
}

int main() {
	init();
	scanf("%d", &N);
	cont(i, N - 1) {
		int a, b; scanf("%d%d", &a, &b);
		nei[a].pub(b); nei[b].pub(a);
	}
	dfs(1, 0);
	cont(i, 19) cont(j, N) fa[i][j] = fa[i - 1][fa[i - 1][j]];
	cont(i, N) {
		scanf("%d", a + i);
		int x = a[i];
		while(x != 1) {
			int p = sml[x];
			int tms = 0;
			while(x % p == 0) {
				x /= p; ++tms;
			}
			hvt[it[p]].pub(mak(i, tms));
			cnt[it[p]] += tms;
		}
	}
	cont(p, ps) {
		mii[p].pub(1);
		cont(i, cnt[p]) {
			mii[p].pub(mii[p].back() * ti[p]);
		}
	}
	scanf("%d", &Q);
	cont(i, Q) {
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		int c = lca(u, v);
		sm[i][0] = u; sm[i][1] = v;
		sm[i][2] = c; sm[i][3] = fa[0][c];
		while(x != 1) {
			int p = sml[x];
			int tms = 0;
			while(x % p == 0) {
				x /= p; ++tms;
			}
			hvq[it[p]].pub(mak(tms, i));
			mxt[it[p]] = max(mxt[it[p]], tms);
		}
		ans[i] = 1;
	}
 	cont(p, ps) {
		sort(all(hvq[p]));
		int pi = ti[p];
		int ptr = 0;
		cont(t, mxt[p]) {
			loop(i, SZ(hvt[p])) {
				if(hvt[p][i].second < t) continue;
				int to = hvt[p][i].first;
				Add(to, 1);
			}
			while(ptr < SZ(hvq[p]) && hvq[p][ptr].first == t) {
				int id = hvq[p][ptr++].second;
				int res = Get(sm[id][0]) + Get(sm[id][1]);
				res -= Get(sm[id][2]) + Get(sm[id][3]);
				ans[id] *= mii[p][res];
			}
		}
		cont(t, mxt[p]) loop(i, SZ(hvt[p])) {
			if(hvt[p][i].second < t) continue;
			int to = hvt[p][i].first;
			Add(to, -1);
		}
	}
	cont(i, Q) printf("%d\n", (int)ans[i]);
	return 0;
}

/**
 * 
 *  
 *  
 *   BIT  min 
 *    1
 *   HLD log
 *    id1  id2 t
 *    t  id2 
 *    id1  id2 
 *   O(n log^2 n)
 */