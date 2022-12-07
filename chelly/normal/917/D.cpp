#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 101;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void add(pair<int, int> & g, pair<int, int> & f, pair<int, int> & dp, int mul) {
	g.fi = (g.fi + (LL)f.fi * dp.fi) % mod;
	g.se = (g.se + ((LL)dp.se * (LL)f.se) % mod * mul) % mod;
}
pair<int, int> dp[N][N][N];
vector<int> adj[N];
int siz[N], ans[N], c[N][N];
void print(pair<int, int> g) {
	printf("%d %d\n", g.fi, g.se);
}
void dfs(int v, int fa) {
	pair<int, int> f[N][N], g[N][N];
	memset(f, 0, sizeof(f));
	f[1][0] = {1, 1};
	siz[v] = 1;
	for(int y : adj[v]) {
		if(y == fa) continue;
		dfs(y, v);
		memset(g, 0, sizeof(g));
		for(int k(1); k <= siz[v]; k++) {
			for(int l(0); l < siz[v]; l++) {
				for(int i(1); i <= siz[y]; i++) {
					for(int j(0); j < siz[y]; j++) {
						//printf("%d %d %d %d %d\n", v, k, l, i, j);
						add(g[i + k][j + l + 1], f[k][l], dp[y][i][j], 1);
						add(g[k][j + l], f[k][l], dp[y][i][j], i);
						//print(g[i + k][j + l + 1]);
						//print(g[k][j + l]);
					}
				}
			}
		}
		memcpy(f, g, sizeof(f));
		siz[v] += siz[y];
	}
	memcpy(dp[v], f, sizeof(f));
}
int main() {
	int n;
	n = getInt();
	for(int i(0); i < n - 1; i++) {
		int x, y;
		x = getInt();
		y = getInt();
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);
	for(int i(1); i <= n; i++) {
		for(int j(0); j < n; j++) {
			//printf("dp[1][%d][%d] = %d %d\n", i, j, dp[1][i][j].fi, dp[1][i][j].se);
			ans[j] = (ans[j] + (LL)(n - j - 2 <= 0 ? 1 : fastpo(n, n - j - 2, mod)) * dp[1][i][j].se % mod * (j == n - 1 ? 1 : i) % mod) % mod;
		}
	}
	for(int i(0); i <= n; i++) {
		for(int j(0); j <= i; j++) {
			c[i][j] = i == 0 || j == 0 ? 1 : (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	for(int i(n - 2); i >= 0; i--) {
		for(int j(i + 1); j < n; j++) {
			ans[i] = (ans[i] + mod - (LL)ans[j] * c[j][i] % mod) % mod;
		}
	}
	for(int i(0); i < n; i++) {
		printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
	}
}