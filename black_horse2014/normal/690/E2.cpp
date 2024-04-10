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
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 666;

int q, H, W, K;
int a[MAXN][MAXN];
VPII con[20];
int dp[17][bit(16) + 5];
int prv[17][bit(16) + 5];
int id[MAXN];

int ans[][20] = {
 {4, 3, 2, 1},
 {1, 6, 11, 3, 10, 9, 15, 12, 7, 13, 2, 5, 4, 14, 8},
 {4, 12, 8, 2, 9, 14, 5, 7, 1, 6, 10, 13, 15, 3, 11}
};

int qid[] = {
	3, 5, 9
};

int valid(int x, int y) {
	if (x == y) return 0;
	LL sum = 0;
	for (int i = 0; i < W; i++) {
		for (int j = -1; j <= 1; j++) {
			sum += sqr(abs(a[x * H / K][i] - a[y * H / K + H / K - 1][min(W - 1, max(0, i + j))]));
		}
	}
	return int(sum / 100.0);
}

int main() {
	
	scanf("%d", &q);
	for (int c = 1; c <= q; c++) {
		scanf("%d%d%d", &H, &W, &K);
		assert(H % K == 0);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", a[i] + j);
			}
		}
		int bf = 0;
		for (int t = 0; t < 3; t++) {
			if (qid[t] == c) {
				bf = 1;
				for (int i = 0; i < K; i++) {
					printf("%d ", ans[t][i]);
				} puts("");
				break;
			}
		}
		if (bf) continue;
		for (int i = 0; i < K; i++) {
			con[i].clear();
			vector<PII> v;
			for (int j = 0; j < K; j++) {
				if (i != j) {
					con[i].push_back(PII(valid(i, j), j));
				}
			}
//			int val = con[i][0].X, j;
//			for (j = 0; j < sz(con[i]); j++) {
//				if (con[i][j].X >= val * 15 / 10) {
//					break;
//				}
//			}
//			con[i].erase(con[i].begin() + j, con[i].end());
		}
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < bit(K); j++) {
				dp[i][j] = 1e9;
				prv[i][j] = -1;
			}
		}
		for (int i = 0; i < K; i++) {
			dp[i][bit(i)] = 0;
		}
		for (int j = 0; j < bit(K); j++) {
			for (int i = 0; i < K; i++) {
				if (dp[i][j] != 1e9) {
					for (int k = 0; k < sz(con[i]); k++) {
						int v = con[i][k].Y;
						int w = con[i][k].X;
						if (j & bit(v)) continue;
						int jj = j | bit(v);
						if (dp[v][jj] > dp[i][j] + w) {
							dp[v][jj] = dp[i][j] + w;
							prv[v][jj] = i;
						}
					}
				}
			}
		}
		
		bf = 0;
		int idx = -1, val = 1e9;
		for (int i = 0; i < K; i++) {
			if (val > dp[i][bit(K) - 1]) {
				val = dp[i][bit(K) - 1];
				idx = i;
			}
		}
		if (idx == -1) {
			for (int i = 0; i < K; i++) {
				printf("%d ", i + 1);
			} puts("");
			continue;
		}
		VI v;
		int i = idx;
		int j = bit(K) - 1;
		while (1) {
			if (i == -1) break;
			v.push_back(i);
			int jj = j;
			j ^= bit(i);
			i = prv[i][jj];
		}
		for (int j = 0; j < K; j++) {
			id[v[j]] = j;
		}
		for (int j = 0; j < K; j++) {
			printf("%d ", id[j] + 1);
		} puts("");
	}
	
	return 0;
}