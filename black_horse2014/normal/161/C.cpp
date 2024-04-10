#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
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

int L[2], R[2];
int a[2], b[2];
int c[2][2];

int main() {
	for (int i = 0; i < 2; i++) scanf("%d%d", &L[i], &R[i]);
	int ans = 0;
	for (int i = 29; i >= 0; i--) {
		for (int j = 0; j < 2; j++) {
			a[j] = (((L[j]-1)>>i)+1)/2;
			b[j] = ((R[j]>>i)+1)/2;
		}
		if (a[0] >= b[0] || a[1] >= b[1]) continue;
		for (int j = 0; j < 2; j++) {
			c[0][j] = (a[j]+b[j]-1)/2;
			c[1][j] = (a[j]+b[j])/2;
			c[0][j] = 2*c[0][j]+1, c[1][j] = 2*c[1][j]+1;
		}
		for (int j = 0; j < 2; j++) {
			int x = min(bit(i), (c[j][0]*bit(i) - L[0]+1));
			int y = min(bit(i)-1, R[0] - c[j][0]*bit(i));
			for (int k = 0; k < 2; k++) {
				int xx = min(x, c[k][1]*bit(i) - L[1]+1);
				int yy = min(y, R[1] - c[k][1]*bit(i));
				chkmax(ans, xx + yy);
			}
		}
	}
	cout << ans << endl;
	return 0;
}