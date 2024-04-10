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

const int MAXN = 10101;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, s, L, R, mid;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

bool chk(int m) {
	int cnt = m, p = (n - 1) >> 1;
	if(n % 2 == 0) cnt += m;
	if(s - cnt >= p * m) return true;
	return false;
}

void solve() {
	read(n), read(s); int L = 0, R = s;
	while(L < R) {
		mid = (L + R + 1) >> 1;
		if(chk(mid)) L = mid;
		else R = mid - 1;
	}
	printf("%lld\n", L);
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