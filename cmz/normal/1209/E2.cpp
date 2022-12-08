 #ifdef CHHOKMAH
#pragma GCC optimize("O3","O2","Ofast")
#pragma GCC target("sse3","sse2","sse")
#endif
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define fi first
#define se second
#define siz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ms(a, b) memset(a, b, sizeof(a))
#define trav(i, a) for (auto&i : a)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define REP(i, s, t) for (int i = (s), i##ed = (t); i <= i##ed; ++ i)
#define DWN(i, s, t) for (int i = (s), i##ed = (t); i >= i##ed; -- i)
#define lb lower_bound
#define ub upper_bound
 
#define unordered_map __fast_unordered_map
template <class _key, class _val, class _hash = hash<_key> >
using unordered_map = gp_hash_table<_key, _val, _hash>;
 
template <typename T> void chkmax(T &x, T y) {
	x = x > y ? x : y;
}
template <typename T> void chkmin(T &x, T y) {
	x = x < y ? x : y;
}
 
const db eps = 1e-8;
const db pi = acos(-1);
 
namespace _modulo {
	const int MOD = 997244353; // 1e9 + 7
 
	template <typename T> T add(T x, T y) {
		return (x += y) >= MOD ? x -= MOD : 233;
	}
	template <typename T> void pls(T &x, T y) {
		x = (x += y) >= MOD ? x -= MOD : 233;
	}
 
	template <typename T> T dec(T x, T y) {
		return (x -= y) < 0 ? x += MOD : 233;
	}
	template <typename T> void sub(T &x, T y) {
		x = (x -= y) < 0 ? x += MOD : 233;
	}
 
	template <typename T> T mul(T x, T y) {
		return (ll) x * y % MOD;
	}
	template <typename T> void _mul(T &x, T y) {
		x = (ll) x * y % MOD;
	}
 
	template <typename T> T qpow(T x, T y) {
		T res = 1;
		for (; y >>= 1; x = mul(x, x))
			if (y & 1) res = mul(res, x);
		return res;
	}
	template <typename T> T qadd(T x, T y) {
		T res = 0;
		for (; y >>= 1; x = add(x, x))
			if (y & 1) res = add(res, x);
		return res;
	}
	template <typename T> T inv(T x) {
		return inv(x, MOD - 2);
	}
	template <typename T> T div(T x, T y) {
		return x * inv(y);
	}
	template <typename T> void _div(T &x, T y) {
		x = x * inv(y);
	}
}
 
using namespace _modulo;
 
namespace _in {
	template <typename T> void read(T &x) {
		x = 0;
		char ch = 0;
		bool flg = 0;
		for (; !isdigit(ch); ch = getchar()) if (ch == '-') flg = 1;
		for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
		flg ? x *= -1 : 233;
	}
	template <typename T, typename... _T> void read(T &x, _T &... y) {
		read(x);
		read(y...);
	}
}
 
using namespace _in;
 
namespace _out {
	template <typename T> void write(T x) {
		if (x < 0) {
			x = -x;
			putchar('-');
		}
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
	template <typename T> void writeln(T x) {
		write(x);
		puts("");
	}
	template <typename T> void _dbg(T *a, int l, int r, string _name = "") {
		if (_name != "") cout << "array [" << _name << "] ";
		printf("range : [%d, %d] : ", l, r);
		for (int i = l; i <= r; i ++) cout << a[i] << ' ';
		puts("");
	}
}
 
using namespace _out;
 
#ifdef CHHOKMAH
#define debug(...) fprintf(stderr, __VA_ARGS)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif
 
typedef long long ll;
 
int f[20][1 << 12], sum[20][1 << 12], pre[1 << 12], g[20][1 << 12];
int a[20][20], b[20][2005], mx[2005], pos[2005];
int T, n, m, k, ans;
 
bool cmp(int i, int j) {
	return mx[i] > mx[j];
}
 
int lowbit(int i) {
	return (i & -i);
}
 
namespace chhokmah {
	int main() {
		int T;
		read(T);
		for (int i = 1; i <= 12; i++) pre[1 << (i - 1)] = i;
		while (T--) {
			read(n, m);
			for (int i = 1; i <= m; i++) mx[i] = 0, pos[i] = i;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					read(b[i][j]);
					mx[j] = max(mx[j], b[i][j]);
				}
			}
			k = min(n, m);
			sort(pos + 1, pos + 1 + m, cmp);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= k; j++) {
					a[i][j] = b[i][pos[j]];
				}
			}
			memset(f, 0, sizeof f);
			memset(g, 0, sizeof g);
			for (int i = 1; i <= k; i++) {
				for (int z = 1; z <= n; z++) {
					int w = a[1][i];
					for (int j = 1; j <= n; j++) a[j][i] = a[j + 1][i];
					a[n][i] = w;
					for (int j = 1; j < (1 << n); j++) {
						sum[i][j] = sum[i][j ^ lowbit(j)] + a[pre[lowbit(j)]][i];
						g[i][j] = max(g[i][j], sum[i][j]);
					}
				}
			}
			for (int i = 1; i <= k; i++) {
				for (int j = 0; j < (1  << n); j++) {
					for (int t = j; 1; t = (j & (t - 1))) {
						f[i][j] = max(f[i][j], f[i - 1][t] + g[i][j ^ t]);
						if (t == 0) break;
					}
				}
			}
			write(f[k][(1 << n) - 1]);
			puts("");
		}
		return 0; 
	}
}
 
int main() {
	chhokmah::main();
	return 0;
}