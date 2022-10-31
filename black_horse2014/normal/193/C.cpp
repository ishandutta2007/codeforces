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

const int MAXN = 333333;

int n, A, B, C, AB, AC, BC, a, b, c, ab, ac, bc, abc;

char str[3][MAXN];

bool solve() {
	if (AB + BC + AC & 1) return 0;
	if (A + B + AB & 1) return 0;
	if (B + C + BC & 1) return 0;
	if (2 * max(AB, max(BC, AC)) > AB + BC + AC) return 0;
	if (2 * max(A, max(B, AB)) > AB + A + B) return 0;
	if (2 * max(B, max(C, BC)) > BC + C + B) return 0;
	if (2 * max(A, max(C, AC)) > AC + C + A) return 0;
	int a1 = (AB + AC - BC) / 2, b1 = (AB + BC - AC) / 2, c1 = (BC + AC - AB) / 2;
	int a2 = (B + C - BC) / 2, b2 = (A + C - AC) / 2, c2 = (A + B - AB) / 2;
	abc = max(max(a2 - a1, b2 - b1), max(0, c2 - c1));
	bc = a2 - abc, ac = b2 - abc, ab = c2 - abc;
	a = a1 - a2 + abc, b = b1 - b2 + abc, c = c1 - c2 + abc;
	return 1;
}

void make(int m, int state) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			if (state >> j & 1) str[j][n+i] = 'b';
			else str[j][n+i] = 'a';
		}
	}
	n += m;
}

int main() {
	cin >> AB >> AC >> A >> BC >> B >> C;
	if (!solve()) {
		puts("-1");
		return 0;
	}
	make(abc, 7), make(bc, 6), make(ac, 5), make(ab, 3), make(a, 1), make(b, 2), make(c, 4);
	cout << n << endl;
	for (int i = 0; i < 3; i++) puts(str[i]);
	for (int i = 0; i < n; i++) putchar('a');
	puts("");
	return 0;
}