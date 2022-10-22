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

const int MAXN = (1 << 17) + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, g;
int buk[MAXN];
vec<pii> Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void run(int x, int dt) {
	if(x <= 2) return;
	if(lowbit(x) == x) return run(x - 1, dt), void();
	int p = (1 << __lg(x));
	for(int i = 1; p + i <= x; ++i)
		Ans.pb(mp((p + i) * dt, (p - i) * dt));
	run(p - (x - p) - 1, dt);
	run(x - p, dt << 1);
}

void solve() {
	read(n); Ans.clear();
	g = 1 << (__lg(n - 1) + 1);
	for(int i = 0; i <= (g << 1); ++i) buk[i] = 0;
	if(n == 2) return puts("-1"), void();
	run(n, 1); 
	for(int i = 1; i <= n; ++i) buk[i]++;
	for(auto x : Ans) {
		assert(buk[x.fst] && buk[x.scd]);
		buk[x.fst]--, buk[x.scd]--;
		buk[x.fst + x.scd]++, buk[abs(x.fst - x.scd)]++;
	}
	if(!buk[0]) {
		for(int i = 1; i <= g; i <<= 1)
			if(buk[i] > 1) {
				buk[i] -= 2, buk[0]++, buk[2 * i]++;
				Ans.pb(mp(i, i)); g = max(g, 2 * i);
				break;
			}
	}
	assert(buk[0]);
	for(int i = 1, p; i <= g; i <<= 1)
		while(buk[i]--) {
			p = i;
			while(p < g) { Ans.pb(mp(p, 0)), Ans.pb(mp(p, p)); p <<= 1; }
		}
	Ans.pb(mp(g, 0));
	printf("%ld\n", Ans.size());
	for(auto x : Ans) printf("%d %d\n", x.fst, x.scd);
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