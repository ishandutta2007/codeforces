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

const int MX = 22;
int a[MX][MX], b[MX][MX];
int n, m;

bool test() {
	for (int c1 = 0; c1 < m; c1++) {
		for (int c2 = c1; c2 < m; c2++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) b[i][j] = a[i][j];
			}
			for (int i = 0; i < n; i++) {
				swap(b[i][c1], b[i][c2]);
			}
			int bf = true;
			for (int i = 0; bf && i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (j != b[i][j]) {
						swap(b[i][j], b[i][b[i][j]]);
						break;
					}
				}
				for (int j = 0; j < m; j++) if (b[i][j] != j) {
					bf = false;
					break;
				}
			}
			if (bf) return 1;
		}
	}
	return 0;
}

int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			a[i][j]--;
		}
	}
	if (test()) puts("YES");
	else puts("NO");
	return 0;
}