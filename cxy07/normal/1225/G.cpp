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

const int MAXN = 17;
const int MAXS = 2010;
const int SIZ = (1 << 16) + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, k, sum;
int a[MAXN];
multiset<pii> idx;
bitset<MAXS> dp[SIZ];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void DFS(int S, int o, int c) {
	if(!S) return;
	if(o * k <= sum && dp[S][o * k]) return DFS(S, o * k, c + 1);
	for(int i = 1, T; i <= n; ++i) {
		if(!((S >> (i - 1)) & 1) || o < a[i]) continue;
		T = S ^ (1 << (i - 1));
		if(!dp[T][o - a[i]]) continue;
		idx.insert(mp(c, a[i])), DFS(T, o - a[i], c); return;
	}
}

signed main () {
#ifdef FILE
	freopen("CF1225G.in", "r", stdin);
	freopen("CF1225G.out", "w", stdout);
#endif
	read(n), read(k);
	for(int i = 1; i <= n; ++i) read(a[i]), sum += a[i];
	dp[0].set(0);
	for(int S = 1; S < (1 << n); ++S) {
		for(int i = 1, T; i <= n; ++i) {
			if(!(S >> (i - 1)) & 1) continue;
			T = S ^ (1 << (i - 1));
			dp[S] |= (dp[T] << a[i]);
		}
		for(int i = sum / k; i >= 1; --i)
			if(dp[S][i * k]) dp[S].set(i);
	}
	if(!dp[(1 << n) - 1][1]) return puts("NO"), 0;
	puts("YES"); DFS((1 << n) - 1, 1, 0);
	while((int)idx.size() > 1) {
		pii A = *prev(idx.end()); idx.erase(prev(idx.end()));
		pii B = *prev(idx.end()); idx.erase(prev(idx.end()));
		assert((A.fst) == (B.fst)); 
		printf("%d %d\n", A.scd, B.scd);
		int c = A.fst, p = (A.scd) + (B.scd);
		while(p % k == 0) --c, p /= k;
		idx.insert(mp(c, p));
	}
	return 0;
}