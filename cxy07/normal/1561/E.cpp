//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
//#define int long long
#define file(FILENAME) freopen(FILENAME".in", "r", stdin), freopen(FILENAME".out", "w", stdout)
#define randint(l, r) (rand() % ((r) - (l) + 1) + (l))
#define LINE() cout << "LINE = " << __LINE__ << endl
#define debug(x) cout << #x << " = " << x << endl
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

const int MAXN = 3010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int a[MAXN];
vec<int> Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void rev(int n) { reverse(a + 1, a + n + 1); Ans.pb(n); }

pii Get(int n) {
	int p1, p2;
	for(int i = 1; i <= n; ++i) if(a[i] == n) { p1 = i; break; }
	for(int i = 1; i <= n; ++i) if(a[i] == n - 1) { p2 = i; break; }
	return mp(p1, p2);
}

void go(int n) {
	if(n == 1) return;
	pii cur = Get(n);
	rev(cur.fst); cur = Get(n);
	if(cur.fst > cur.scd + 1) rev(cur.fst), cur = Get(n);
	else if(cur.fst < cur.scd - 1) rev(cur.scd - 1), cur = Get(n);
	assert(abs(cur.fst - cur.scd) == 1);
	if(cur.fst < cur.scd) rev(cur.scd + 1), cur = Get(n);
	rev(cur.fst); cur = Get(n); assert(cur.fst == 1 && cur.scd == 2);
	rev(n); go(n - 2);
}

void solve() {
	read(n); Ans.clear();
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1; i <= n; ++i)
		if((a[i] & 1) != (i & 1)) return puts("-1"), void();
	go(n); printf("%ld\n", Ans.size());
	for(auto x : Ans) printf("%d ", x);
	putchar('\n');
}

signed main () {
#ifdef FILE
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
#endif
	read(T);
	while(T--) solve();
	return 0;
}