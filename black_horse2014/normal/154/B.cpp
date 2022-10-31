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

const int MAXN = 111111;

int prm[MAXN], prn;
bool p[MAXN];

int chk[MAXN], vis[MAXN];

int main() {
	
	for (int i = 2; i < MAXN; i++) if (!p[i]) {
		prm[prn++] = i;
		for (int j = 2*i; j < MAXN; j += i) p[j] = 1;
	}
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char t[111]; int x; scanf("%s%d", t, &x);
		int y = x;
		vector<int> d;
		for (int j = 0; j < prn && 1LL*prm[j]*prm[j] <= y; j++) {
			if (y % prm[j] == 0) {
				while (y % prm[j] == 0) y /= prm[j];
				d.pb(prm[j]);
			}
		}
		if (y > 1) d.pb(y);
		if (t[0] == '+') {
			if (chk[x]) {
				puts("Already on");
				continue;
			}
			int ans = 0;
			for (int j = 0; !ans && j < d.size(); j++) ans = vis[d[j]];
			if (ans) {
				printf("Conflict with %d\n", ans);
				continue;
			}
			puts("Success");
			chk[x] = 1;
			for (int j = 0; j < d.size(); j++) vis[d[j]] = x;
		} else {
			if (!chk[x]) {
				puts("Already off");
				continue;
			}
			puts("Success");
			chk[x] = 0;
			for (int j = 0; j < d.size(); j++) vis[d[j]] = 0;
		}
	}
	return 0;
}