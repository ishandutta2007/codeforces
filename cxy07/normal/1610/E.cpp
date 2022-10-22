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

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, Ans;
int a[MAXN];
set<int> S;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

int calc(int p) {
	int res = 0, d = 1, cur = p;
	while(1) {
		++res;
		auto it = S.lower_bound(cur + d);
		if(it == S.end()) return res;
		assert((*it) - cur >= d);
		cur = (*it); d = (*it) - p;
	}
	assert(0);
	return -1;
}

void solve() {
	read(n); S.clear(); Ans = 0;
	for(int i = 1; i <= n; ++i) read(a[i]), S.insert(a[i]);
	for(int L = 1, R; L <= n; L = R + 1) {
		R = L; while(R < n && a[R + 1] == a[L]) ++R;
		Ans = max(Ans, R - L + calc(a[L]));
	}
	printf("%d\n", n - Ans);
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