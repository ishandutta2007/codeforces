//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
#define debug(x) cout << #x << " = " << x << endl
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define LINE() cout << "LINE = " << __LINE__ << endl
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define vec vector

const int MAXN = 5010;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, k, E;
int F[MAXN], a[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
	return 1;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

int qpow(int x, int b) {
	int res = 1;
	for(; b; b >>= 1, (x *= x) %= mod) if(b & 1) (res *= x) %= mod;
	return res;
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n), read(k);
	for(int i = 1; i <= n; ++i) read(a[i]);
	F[0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j; --j) F[j] = (a[i] * F[j] % mod - F[j - 1]) % mod;
		F[0] = F[0] * a[i] % mod;
	}
	int fack = 1, ns = 1, in = inv(n);
	for(int i = 0; i <= n; ++i) {
		(E += F[i] * fack % mod * ns % mod) %= mod;
		ns = ns * in % mod;
		fack = fack * (k - i) % mod;
	}
	E = ((F[0] - E) % mod + mod) % mod;
	printf("%lld\n", E);
	return 0;
}