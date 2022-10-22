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

const int MAXN = 2e6 + 10;
const int INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m;
int arr[MAXN], dn[MAXN], son[MAXN];
int *cur = arr, *dp[MAXN];
int Ans[MAXN];
vec<int> G[MAXN];

template<typename T> inline bool read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	return a *= f, true;
}

template<typename A, typename ...B>
inline bool read(A &x, B &...y) {return read(x) && read(y...);}

void DFS1(int x, int fa) {
	for(auto to : G[x]) {
		if(to == fa) continue;
		DFS1(to, x);
		if(dn[to] > dn[son[x]]) son[x] = to;
	}
	dn[x] = dn[son[x]] + 1;
}

int DFS2(int x, int fa) {
	Ans[x] = 0; dp[x][0]++;
	if(!son[x]) return Ans[x];
	dp[son[x]] = dp[x] + 1;
	Ans[x] = DFS2(son[x], x) + 1;
	int maxdn = 0;
	for(auto to : G[x]) {
		if(to == fa || to == son[x]) continue;
		dp[to] = cur; cur += dn[to];
		DFS2(to, x);
		for(int i = 0; i < dn[to]; ++i)
			dp[x][i + 1] += dp[to][i];
		maxdn = max(maxdn, dn[to]);
	}
	for(int i = maxdn; i >= 0; --i)
		if(dp[x][i] >= dp[x][Ans[x]]) Ans[x] = i;
	return Ans[x];
}

signed main () {
#ifdef FILE
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif
	read(n);
	for(int i = 1, x, y; i < n; ++i) { 
		read(x), read(y);
		G[x].pb(y), G[y].pb(x);
	}
	DFS1(1, 0);
	dp[1] = cur; cur += dn[1];
	DFS2(1, 0);
	for(int i = 1; i <= n; ++i) printf("%d\n", Ans[i]);
	return 0;
}