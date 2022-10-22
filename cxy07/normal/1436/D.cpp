//Code By CXY07
#include<bits/stdc++.h>
using namespace std;

//#define FILE
#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
#define vec vector

const int MAXN = 2e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;

int n, m, ans;
int a[MAXN], dp[MAXN], siz[MAXN];
vec<int> G[MAXN];

template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}

void DFS(int x) {
	int son = 0;
	for(auto to : G[x]) {
		DFS(to);
		siz[x] += siz[to];
		dp[x] += dp[to];
		son++;
	}
	dp[x] += a[x];
	if(!son) return (void) (siz[x] = 1);
}

signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 2, f; i <= n; ++i) {
		read(f);
		G[f].pb(i);
	}
	for(int i = 1; i <= n; ++i) read(a[i]);
	DFS(1);
	for(int i = 1; i <= n; ++i)
		ans = max(ans, (int)ceil((double)((double)dp[i] / siz[i])));
	printf("%lld\n", ans);
	return 0;
}