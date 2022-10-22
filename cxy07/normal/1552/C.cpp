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

const int MAXN = 210;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, k, Ans;
int L[MAXN], R[MAXN], vis[MAXN];
vec<int> pos;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

bool in(int id, int x) {
	return L[id] <= x && x <= R[id];
}

int ok(int i, int j) {
	return (in(i, L[j]) + in(i, R[j]) == 1);
}

void solve() {
	read(n), read(k); Ans = 0; pos.clear();
	for(int i = 1; i <= n * 2; ++i) vis[i] = false;
	for(int i = 1; i <= k; ++i) {
		read(L[i]), read(R[i]);
		if(L[i] > R[i]) swap(L[i], R[i]);
		vis[L[i]] = vis[R[i]] = true;
	}
	for(int i = 1; i <= n * 2; ++i) 
		if(!vis[i]) pos.pb(i);
	for(int i = 0; i < n - k; ++i) {
		L[k + 1 + i] = pos[i];
		R[k + 1 + i] = pos[i + n - k];
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j < i; ++j)
			Ans += ok(i, j);
	printf("%d\n", Ans);
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