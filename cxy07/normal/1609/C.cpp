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

int T, n, e, Ans;
int a[MAXN], L[MAXN], R[MAXN];
bool isp[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

bool isprime(int x) {
	if(x == 1) return false;
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0) return false;
	return true;
}

void solve() {
	read(n), read(e); Ans = 0;
	for(int i = 1; i <= n; ++i) {
		read(a[i]); L[i] = R[i] = 0;
		isp[i] = isprime(a[i]);
	}
	for(int i = 1; i <= n; ++i)
		if(a[i] == 1) {
			L[i]++;
			if(i - e >= 1) L[i] += L[i - e];
		}
	for(int i = n; i >= 1; --i)
		if(a[i] == 1) {
			R[i]++;
			if(i + e <= n) R[i] += R[i + e];
		}
	for(int i = 1, a, b; i <= n; ++i)
		if(isp[i]) {
			a = b = 1;
			if(i - e >= 1) a += L[i - e];
			if(i + e <= n) b += R[i + e];
			Ans += (a * b - 1);
		}
	printf("%lld\n", Ans);
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