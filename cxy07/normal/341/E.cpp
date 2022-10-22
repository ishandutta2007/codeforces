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

const int MAXN = 1010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, cnt;
int a[MAXN], p[3];
vec<int> idx;
vec<pii> Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void run(int x, int y) {
	assert(a[y] >= a[x]);
	Ans.pb(mp(x, y));
	a[y] -= a[x]; a[x] += a[x];
}

void solve() {
	while(1) {
		sort(p, p + 3, [&](int x, int y) { return a[x] < a[y]; });
		if(!a[p[0]]) return;
		int k = a[p[1]] / a[p[0]];
		while(k) {
			if(k & 1) run(p[0], p[1]);
			else run(p[0], p[2]);
			k >>= 1;
		}
	}
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i <= n; ++i) { read(a[i]); if(a[i]) idx.pb(i); }
	if((int)idx.size() <= 1) return puts("-1"), 0;
	while((int)idx.size() > 2) {
		bool flag = true;
		for(int i = 0; i < 3; ++i) {
			assert(a[idx.back()]);
			p[i] = idx.back(); idx.pop_back();
		}
		if(!flag) break;
		solve();
		for(int i = 0; i < 3; ++i) if(a[p[i]]) idx.pb(p[i]);
	}
	printf("%ld\n", Ans.size());
	for(auto x : Ans) printf("%d %d\n", x.fst, x.scd);
	return 0;
}