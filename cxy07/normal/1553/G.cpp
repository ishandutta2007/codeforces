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

const int MAXN = 1e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, q, V = 1e6;
int dsu[MAXN], a[MAXN];
int pr[MAXN], cnt;
bool np[MAXN];
vec<int> fact[MAXN];
map<int, bool> mmp[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void sieve(int siz) {
	for(int i = 2; i <= siz; ++i) {
		if(!np[i]) pr[++cnt] = i;
		for(int j = 1; j <= cnt && i * pr[j] <= siz; ++j) {
			np[i * pr[j]] = true;
			if(i % pr[j] == 0) break;
		}
	}
	for(int i = 1; i <= cnt; ++i)
		for(int j = pr[i]; j <= siz; j += pr[i]) fact[j].pb(pr[i]);
}

int find(int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }

void unity(int x, int y) {
	x = find(x), y = find(y);
	if(x != y) dsu[x] = y;
}

void link(int x) { for(auto f : fact[x]) unity(x, f); }

bool ok(int x, int y) {
	for(auto f : fact[x]) if(find(f) == find(y)) return true;
	return false;
}

void solve() {
	int x, y; read(x), read(y);
	x = find(a[x]), y = find(a[y]);
	if(x == y) return puts("0"), void();
	if(mmp[x].count(y)) return puts("1"), void();
	puts("2");
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n), read(q); sieve(V + 1);
	for(int i = 1; i <= V + 1; ++i) dsu[i] = i;
	for(int i = 1; i <= n; ++i) read(a[i]), link(a[i]);
	for(int i = 1; i <= n; ++i)
		for(auto x : fact[a[i] + 1]) {
			for(auto y : fact[a[i]]) mmp[find(x)][find(y)] = mmp[find(y)][find(x)] = 1;
			for(auto y : fact[a[i] + 1]) mmp[find(x)][find(y)] = mmp[find(y)][find(x)] = 1;
		}
	while(q--) solve();
	return 0;
}