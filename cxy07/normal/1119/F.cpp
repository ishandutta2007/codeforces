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

const int MAXN = 2.5e5 + 10;
const LL INF = 2e15;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, LIM;
int X[MAXN], Y[MAXN], W[MAXN];
int ind[MAXN], perm[MAXN];
LL Ans[MAXN], dp[MAXN][2]; // 0 : ind <= limit; 1 : ind <= limit + 1, use fa
bool added[MAXN], vis[MAXN], act[MAXN];
vec<int> valid;
vec<pii> G[MAXN], es[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

struct SET {
	LL sum; set<pii> S1, S2;
	void add(pii x) { S2.insert(x); }
	void del(pii x) {
		if(S1.count(x)) S1.erase(x), sum -= x.fst;
		else if(S2.count(x)) S2.erase(x);
	}
	LL query(int x) {
		if(x > (int)S1.size() + (int)S2.size()) return INF;
		while((int)S1.size() > x) {
			auto it = prev(S1.end());
			sum -= it->fst; S2.insert(*it); S1.erase(it);
		}
		while((int)S1.size() < x) {
			auto it = S2.begin();
			sum += it->fst; S1.insert(*it); S2.erase(it);
		}
		return sum;
	}
} S[MAXN];

void add_edge(int x) {
	act[x] = true;
	for(auto to : es[x]) {
		S[to.fst].del(mp(to.scd, x));
		if(!act[to.fst]) continue;
		G[x].pb(mp(to.fst, to.scd));
		G[to.fst].pb(mp(x, to.scd));
	}
}

void DFS(int x, int fa) {
	vis[x] = true; assert(ind[x] > LIM);
	LL sum0 = 0, dts = 0; dp[x][0] = dp[x][1] = INF;
	vec<LL> dt; dt.clear();
	for(auto _to : G[x]) {
		int to = _to.fst, w = _to.scd;
		if(to == fa) continue;
		DFS(to, x); sum0 += dp[to][0];
		dt.pb(dp[to][1] + w - dp[to][0]);
	}
	sort(dt.begin(), dt.end());
	for(int i = 0, c; i <= (int)dt.size(); ++i) {
		if(i) dts += dt[i - 1];
		c = max(ind[x] - i - LIM, 0);
		dp[x][0] = min(dp[x][0], S[x].query(c) + dts);
		c = max(ind[x] - i - 1 - LIM, 0);
		dp[x][1] = min(dp[x][1], S[x].query(c) + dts);
	}
	dp[x][0] += sum0, dp[x][1] += sum0;
}

signed main () {
#ifdef FILE
	freopen("CF1119F.in", "r", stdin);
	freopen("CF1119F.out", "w", stdout);
#endif
	read(n);
	for(int i = 1; i < n; ++i) {
		read(X[i]), read(Y[i]), read(W[i]);
		ind[X[i]]++, ind[Y[i]]++;
		es[X[i]].pb(mp(Y[i], W[i]));
		es[Y[i]].pb(mp(X[i], W[i]));
		S[X[i]].add(mp(W[i], Y[i]));
		S[Y[i]].add(mp(W[i], X[i]));
		Ans[0] += W[i];
	}
	for(int i = 1; i <= n; ++i) perm[i] = i;
	sort(perm + 1, perm + n + 1, [&](int a, int b) { return ind[a] > ind[b]; });
	for(int i = n - 1, p = 1; i >= 1; --i) {
		LIM = i;
		while(p <= n && ind[perm[p]] > i) { valid.pb(perm[p]); add_edge(perm[p++]); }
		for(auto x : valid) if(!vis[x]) { DFS(x, 0), Ans[i] += dp[x][0]; }
		for(auto x : valid) vis[x] = false;
	}
	for(int i = 0; i < n; ++i) printf("%lld ", Ans[i]);
	return 0;
}