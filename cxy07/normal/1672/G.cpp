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

const int MAXN = 4010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans;
char _s[MAXN][MAXN], s[MAXN][MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

namespace sub1 {
	void solve() {
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) Ans += (s[i][j] == '?');
		Ans = qpow(2, Ans); 
		printf("%lld\n", Ans);
	}
}

namespace sub2 {
	void solve() {
		int res = 1;
		for(int i = 1, c, o; i <= n; ++i) {
			c = 0, o = 0;
			for(int j = 1; j <= m; ++j)
				c += (s[i][j] == '?'), o ^= (s[i][j] == '1');
			if(!c && o) { res = 0; break; }
			if(c) res = res * qpow(2, c - 1) % mod;
		}
		(Ans += res) %= mod;
		for(int i = 1; i <= n; ++i) 
			if(s[i][1] != '?') s[i][1] = '0' + '1' - s[i][1];
		for(int i = 2; i <= m; ++i)
			if(s[1][i] != '?') s[1][i] = '0' + '1' - s[1][i];
		res = 1;
		for(int i = 1, c, o; i <= n; ++i) {
			c = 0, o = 0;
			for(int j = 1; j <= m; ++j) 
				c += (s[i][j] == '?'), o ^= (s[i][j] == '1');
			if(!c && o) { res = 0; break; }
			if(c) res = res * qpow(2, c - 1) % mod;
		}
		(Ans += res) %= mod;
		printf("%lld\n", Ans);
	}
}

namespace sub3 {
	int dsu[MAXN], siz[MAXN], ecnt[MAXN];
	int A[MAXN], tot[MAXN];
	int find(int x) { return dsu[x] == x ? x : dsu[x] = find(dsu[x]); }
	bool unity(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return false;
		dsu[x] = y; siz[y] += siz[x], ecnt[y] += ecnt[x];
		return true;
	}
	void solve() {
		for(int i = 1; i <= n + m; ++i) dsu[i] = i, siz[i] = 1;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(s[i][j] != '?') {
					A[i] ^= (s[i][j] - '0'), A[j + n] ^= (s[i][j] - '0');
					continue;
				}
				if(!unity(i, j + n)) ecnt[find(i)]++;
			}
		}
		for(int i = 1; i <= n + m; ++i) tot[find(i)] ^= A[i];
		for(int v = 0, res; v <= 1; ++v) {
			res = 1;
			for(int i = 1; i <= n + m; ++i) {
				if(find(i) ^ i) continue;
				if(siz[i] & 1) {
					if(tot[i] != v) { res = 0; break; }
					else res = res * qpow(2, ecnt[i]) % mod;
				} else {
					if(tot[i]) { res = 0; break; }
					else res = res * qpow(2, ecnt[i]) % mod;
				}
			}
			Ans = (Ans + res) % mod;
		}
		printf("%lld\n", Ans);
	}
}

signed main () {
#ifdef FILE
	freopen("CF1672G.in", "r", stdin);
	freopen("CF1672G.out", "w", stdout);
#endif
	read(n), read(m);
	for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	if((n & 1) && (m & 1) == 0) {
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j) _s[j][i] = s[i][j];
		swap(n, m); memcpy(s, _s, sizeof s);
	}
	if((n & 1) == 0 && (m & 1) == 0) return sub1::solve(), 0;
	if((n & 1) == 0 && (m & 1) == 1) return sub2::solve(), 0;
	if((n & 1) == 1 && (m & 1) == 1) return sub3::solve(), 0;
	return 0;
}