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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, Ans, g, V;
int a[MAXN], pr[MAXN], pcnt;
int f[MAXN], F[MAXN];
bool np[MAXN];

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
		if(!np[i]) pr[++pcnt] = i;
		for(int j = 1; j <= pcnt && i * pr[j] <= siz; ++j) {
			np[i * pr[j]] = true;
			if(i % pr[j] == 0) break;
		}
	}
}

void modadd(int &x, int y) { x += y; (x >= mod) && (x -= mod); }

void suf_add(int *A) {
	for(int i = 1; i <= pcnt; ++i)
		for(int j = V / pr[i]; j >= 1; --j)
			modadd(A[j], A[j * pr[i]]);
}

void suf_del(int *A) {
	for(int i = 1; i <= pcnt; ++i)
		for(int j = 1; j * pr[i] <= V; ++j)
			modadd(A[j], mod - A[j * pr[i]]);
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]), g = __gcd(g, a[i]);
	if(g != 1) return puts("-1"), 0;
	for(int i = 1; i <= n; ++i) {
		if(!f[a[i]]) f[a[i]] = 1;
		Ans -= (a[i] == 1), V = max(V, a[i]);
	}
	sieve(V); memcpy(F, f, sizeof F); suf_add(f); 
	Ans = 1;
	while(!(F[1] % mod)) {
		suf_add(F);
		for(int i = 1; i <= V; ++i) F[i] = (1ll * F[i] * f[i]) % mod;
		suf_del(F); ++Ans;
	}
	printf("%d\n", Ans);
	return 0;
}