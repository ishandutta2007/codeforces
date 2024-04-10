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
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
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
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 333333;
int n, m, K, tot;
int vis[MAXN], chk[MAXN], dis[MAXN], mrk[MAXN];
VI adj[MAXN];
int q[MAXN], r[MAXN];

void bfs() {
  int CN = 0;
  for (int i = 1; i <= n; i++) chk[i] = 0, dis[i] = -1;
  int rn = 0;
	for (int i = 2; i <= n; i++) r[rn++] = i;
		
	while (rn) {
		int S = r[rn - 1];
		rn--;
		tot++;
	  int hd = 0, tl = 0;
	  q[tl++] = S;
	  dis[S] = tot;
	 	
		while (hd < tl) {
		  CN++;
		  for (int i = hd; i < tl; i++) {
			  int u = q[i];
			  for (int j = 0; j < sz(adj[u]); j++) {
				  int v = adj[u][j];
				  if (v == 1) continue;
				  if (chk[v] != CN) chk[v] = CN, vis[v] = 1;
				  else vis[v]++;
				}
			}
			 
		  int rrn = 0, ttl = tl;
		  for (int i = 0; i < rn; i++) {
			  int u = r[i];
			  if (chk[u] == CN && vis[u] == ttl - hd) r[rrn++] = r[i];
			  else q[tl++] = u, dis[u] = tot;
			}
			rn = rrn, hd = ttl;
		}
		
	}
}

int main() {

	scanf("%d%d%d", &n, &m, &K);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if ((n - 1 - adj[1].size()) < K) {
		puts("impossible");
		return 0;
	}
	bfs();
	if (tot > K) {
		puts("impossible");
		return 0;
	}
	memset(chk, 0, sizeof chk);
	for (int i = 0; i < adj[1].size(); i++) {
		int u = adj[1][i];
		chk[u] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (chk[i] == 0) mrk[dis[i]] = 1;
	}
	int i;
	for (i = 1; i <= tot; i++) if (mrk[i] == 0) break;
	if (i <= tot) puts("impossible");
	else puts("possible");

	return 0;
}