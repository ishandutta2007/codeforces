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

const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int T, n, m;
int perm[MAXN], buk[MAXN];
int pos[MAXN], to[MAXN];
bool vis[MAXN];
vec<int> Ans;

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar(); }
	while(c >= '0' && c <= '9') { a = a * 10 + (c ^ 48); c = getchar(); }
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) { return read(x) && read(y...); }

void DFS(int x) {
	if(vis[x]) return;
	vis[x] = true; DFS(to[x]);
}

bool chk(int dt) {
	for(int i = 1; i <= n; ++i) {
		vis[i] = false, to[i] = 0;
		pos[perm[i]] = i;
	}
	for(int i = 1, at; i <= n; ++i) {
		at = (i + dt - 1 + n) % n + 1;
		to[at] = pos[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) DFS(i), ++cnt;
	if(n - cnt <= m) return true;
	return false;
}

void solve() {
	read(n), read(m); Ans.clear();
	memset(buk, 0, sizeof(int) * (n + 5));
	for(int i = 1, dt; i <= n; ++i) {
		read(perm[i]);
		if(perm[i] <= i) dt = i - perm[i];
		else dt = n + i - perm[i];
		buk[dt]++;
	}
	for(int i = 0; i < n; ++i)
		if(buk[i] >= n - (m << 1) && chk(i)) Ans.pb(i);
	printf("%ld ", Ans.size());
	for(auto x : Ans) printf("%d ", x);
	putchar('\n');
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