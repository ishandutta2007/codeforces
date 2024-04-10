#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 222222;

vector<int> adj[MAXN];
vector<long long> V;

int n, m;
int e[MAXN], chk[MAXN];
long long c[MAXN], dis[MAXN];
int cnt[2][66],pw[66];

void dfs(int u, int p, long long d) {
  	chk[u] = 1, dis[u] = d;
  	for (int k = 0; k < 60; k++) cnt[d>>k&1][k]++;
  	for (int i = 0; i < sz(adj[u]); i++) {
		int j = adj[u][i], v = e[j] ^ u;
		long long w = c[j];
		if (v == p) continue;
		if (!chk[v]) {
		  	dfs(v, u, d ^ w);
		} else {
		  	V.push_back(dis[u]^dis[v]^w);
		}
  	}
}

const int MOD = 1e9+7;

long long solve(int u) {
	V.clear();
	memset(cnt, 0, sizeof cnt);
	dfs(u, 0, 0);
	int j = 0;
	for (int i = 0; j < sz(V) && i < 60; i++) {
		for (int k = j; k < sz(V); k++) {
			if (V[k]>>(59-i) & 1) {
			    if (k > j) {
					swap(V[j], V[k]);
					break;
			    }
			}
		}
		if (V[j]>>(59-i) & 1) {
			for (int k = 0; k < sz(V); k++) {
				if (k != j) {
					if (V[k]>>(59-i) & 1) V[k] ^= V[j];
				}
			}
			j++;
		}
	}
	if (j < sz(V)) V.resize(j);
	long long sum = 0;
	for (int i = 0; i < j; i++) sum |= V[i];
	int ret = 0, cur = 1;
	for (int i = 1; i < V.size(); i++) cur = cur * 2 % MOD;
	int tot = cnt[0][0] + cnt[1][0];
	int temp = 1LL * tot * (tot - 1) / 2 % MOD;
	for (int i = 0; i < 60; i++) {
		if (sum >> i & 1) {
			ret = (ret + 1LL * cur * temp % MOD * pw[i]) % MOD;
		} else {
			ret = (ret + 1LL * cnt[0][i] * cnt[1][i] % MOD * pw[i] % MOD * pw[V.size()]) % MOD; 
		}
	}
	return ret;
}

int main() {
	
	int n, m; scanf("%d%d", &n, &m);
	pw[0] = 1;
	for (int i = 1; i < 66; i++) pw[i] = pw[i-1] * 2 % MOD;
	for (int i = 0; i < m; i++) {
		int u, v; long long w;
		scanf("%d%d%lld", &u, &v, &w);
		adj[u].push_back(i);
		adj[v].push_back(i);
		e[i] = u ^ v, c[i] = w;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) if (!chk[i]) ans = (ans + solve(i)) % MOD;
	cout << ans << endl;
	return 0;
}