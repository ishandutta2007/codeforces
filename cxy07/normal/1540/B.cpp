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

const int MAXN = 210;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans, iv2 = (mod + 1) >> 1;
int f[MAXN][MAXN], siz[MAXN], Inv[MAXN];
bool on[MAXN];
vec<int> G[MAXN], v;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

bool find(int x, int f, int g) {
	if(x == g) return v.pb(x), on[x] = true, true;
	for(auto to : G[x]) 
		if(to != f && find(to, x, g)) return v.pb(x), on[x] = true, true;
	return false;
}

void Getsize(int x, int f) {
	siz[x] = 1;
	for(auto to : G[x]) {
		if(on[to] || to == f) continue;
		Getsize(to, x); siz[x] += siz[to];
	}
}

int calc(int a, int b) {
	memset(on, false, sizeof on); v.clear();
	find(a, 0, b);
	reverse(v.begin(), v.end());
	for(auto x : v) Getsize(x, 0);
	int res = 0;
	assert((int)v.size() > 1);
	for(int i = 0; i < (int)v.size(); ++i)
		(res += f[i][v.size() - i - 1] * siz[v[i]] % mod * Inv[n]) %= mod;
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n); Inv[1] = 1;
	for(int i = 1, x, y; i < n; ++i) 
		read(x), read(y), G[x].pb(y), G[y].pb(x);
	for(int i = 2; i <= n; ++i) Inv[i] = Inv[mod % i] * (mod - mod / i) % mod;
	for(int i = 1; i <= n; ++i) f[0][i] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			f[i][j] = iv2 * (f[i - 1][j] + f[i][j - 1]) % mod;
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j)
			(Ans += calc(j, i)) %= mod;
	printf("%lld\n", (Ans + mod) % mod);
	return 0;
}