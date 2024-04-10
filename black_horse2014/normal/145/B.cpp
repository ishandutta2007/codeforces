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

int a[4];
int b[2];
int len[2];

int cnt[2][1111111];

char str[] = "47";
int st;

void print() {
	for (int i = len[0]-1; i >= 1; i--) cnt[0][i] = 1;
	cnt[0][0] = a[0] - len[0] + 1;
	for (int i = 0; i < len[1]-1; i++) cnt[1][i] = 1;
	cnt[1][len[1]-1] = a[1] - len[1] + 1;
	for (int i = st; b[i] < len[i]; b[i]++, i ^= 1) {
		for (int j = 0; j < cnt[i][b[i]]; j++) putchar(str[i]);
	}
	puts("");
}

int main() {
	
	for (int i = 0; i < 4; i++) scanf("%d", &a[i]);
	if (abs(a[2] - a[3]) > 1 || max(a[2], a[3]) > min(a[0], a[1])) {
		puts("-1");
		return 0;
	}
	if (a[2] == a[3]) {
		if (a[0] >= a[2]+1) {
			len[0] = a[2]+1;
			len[1] = a[2];
			st = 0;
		} else {
			len[0] = a[2];
			len[1] = a[2]+1;
			if (a[1] < len[1]) {
				puts("-1");
				return 0;
			}
			st = 1;
		}
	} else {
		if (a[2] > a[3]) st = 0;
		else st = 1;
		len[0] = len[1] = max(a[2], a[3]);
	}
	print();
	return 0;
}