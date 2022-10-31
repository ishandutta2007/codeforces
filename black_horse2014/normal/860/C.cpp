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

const int MAXN = 100000 + 10;

int chk[2000000];
int d[MAXN], a[MAXN], b[MAXN];
char s[MAXN][10];

vector<int> V[2];
set<int> S[2], T[2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	int m = 0;
	for (int i = 0; i < n; i++) scanf("%s%d", s[i], &a[i]), m += a[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		int &flg = d[i];
		for (int j = 0; flg && s[i][j]; j++) if (s[i][j] < '0' || s[i][j] > '9') flg = 0;
		if (s[i][0] == '0') flg = 0;
		if (flg) {
			b[i] = 0;
			for (int j = 0; s[i][j]; j++) b[i] = b[i] * 10 + s[i][j] - '0';
			if (b[i] > n) b[i] = 0;
			if (a[i]) flg &= (1 <= b[i] && b[i] <= m);
			else flg &= (m + 1 <= b[i] && b[i] <= n);
		}
		if (!flg) ans++;
	}
	int add = 1;
	for (int i = 0; add && i < n; i++) {
		if (!d[i] && !b[i]) add = 0;
	}
	if (!ans) add = 0;
	if (add) ans += add;
	for (int i = 1; i <= m; i++) S[1].insert(i);
	for (int i = m+1; i <= n; i++) S[0].insert(i);
	for (int i = 0; i < n; i++) if (d[i]) S[a[i]].erase(b[i]);
	for (int i = 0; i < n; i++) if (!d[i] && b[i]) S[!a[i]].erase(b[i]), T[a[i]].insert(b[i]);
	memset(chk, -1, sizeof chk);
	for (int i = 0; i < n; i++) chk[b[i]] = i;
	cout << ans << endl;
	if (add) {
		for (int i = 0; i < 2; i++) for (set<int> :: iterator it = T[i].begin(); it != T[i].end(); it++) V[i].pb(*it);
		printf("move %d %d\n", V[0].back(), n + 1);
		for (int j = sz(V[1])-1; j >= 0; j--) {
			printf("move %d %d\n", V[1][j], V[0][j]);
			if (j) printf("move %d %d\n", V[0][j-1], V[1][j]);
		}
		printf("move %d %d\n", n + 1, V[1][0]);
		return 0;
	}
	while (1) {
		if (T[0].empty() && T[1].empty()) break;
		for (int id = 0; id < 2; id++) if (!T[id].empty() && !S[id].empty()) {
			set<int> :: iterator it = T[id].begin();
			set<int> :: iterator it1 = S[id].begin();
			printf("move %d %d\n", *it, *it1);
			int u = *it, v = *it1;
			S[!id].insert(u);
			S[id].erase(v);
			T[id].erase(u);
			d[chk[u]] = 1;
		}
	}
	assert(T[0].empty() && T[1].empty());
	for (int i = 0; i < n; i++) {
		if (!d[i]) {
			set<int> :: iterator it = S[a[i]].begin();
			int u = *it;
			printf("move %s %d\n", s[i], u);
			d[i] = 1;
			S[a[i]].erase(u);
		}
	}
	return 0;
}