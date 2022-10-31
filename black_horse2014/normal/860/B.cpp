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

const int MAXN = 70000 + 10;

char s[MAXN][11];

vector<long long> a[MAXN];
map<long long, int> M;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			long long x = 0;
			for (int k = j; k < 9; k++) {
				x = x * 11 + (s[i][k] - '0' + 1);
				a[i].pb(x);
			}
		}
		sort(all(a[i]));
		a[i].erase(unique(all(a[i])), a[i].end());
		for (int j = 0; j < sz(a[i]); j++) M[a[i][j]]++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sz(a[i]); j++) {
			if (M[a[i][j]] == 1) {
				long long x = a[i][j];
				vector<int> d;
				while (x) d.push_back(x % 11), x /= 11;
				reverse(all(d));
				for (int k = 0; k < sz(d); k++) putchar(d[k]-1 + '0');
				puts("");
				break;
			}
		}
	}
	return 0;
}