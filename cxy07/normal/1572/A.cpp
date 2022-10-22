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

const int MAXN = 201010;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m, Ans, cnt;
int d[MAXN], v[MAXN];
vec<int> G[MAXN];
queue<int> Q;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }
 
void solve() {
	read(n); Ans = cnt = 0;
	for(int i = 1; i <= n; ++i) d[i] = v[i] = 0, G[i].clear();
	for(int i = 1, k; i <= n; ++i) {
		read(k);
		for(int j = 1, to; j <= k; ++j) {
			read(to); G[to].pb(i), d[i]++;
		}
	} while(Q.size()) Q.pop();
	for(int i = 1; i <= n; ++i) 
		if(!d[i]) Q.push(i), v[i] = 1;
	while(Q.size()) {
		int x = Q.front(); Q.pop();
		Ans = max(Ans, v[x]);
		cnt++;
		for(auto to : G[x]) {
			v[to] = max(v[to], v[x] + (to < x));
			if((--d[to]) == 0) Q.push(to);
		}
	}
	if(n != cnt) puts("-1");
	else printf("%d\n", Ans);
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