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

int val[2][MAXN];
int C[2];

vector< pair<int, int> > V[2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N; cin >> N >> C[0] >> C[1];
	for (int i = 1; i <= N; i++) {
		char str[11]; int b, p;
		scanf("%d%d%s", &b, &p, str);
		int id = str[0] - 'C';
		if (p > C[id]) continue;
		V[id].push_back(make_pair(p, b));
	}
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		sort(all(V[i]));
		int cur = 0;
		for (int j = 0; j < sz(V[i]); j++) val[i][j] = cur, chkmax(cur, V[i][j].second);
		val[i][sz(V[i])] = cur;
		for (int j = 0, k = sz(V[i])-1; k > 0; k--) {
			while (j < sz(V[i]) && V[i][j].first + V[i][k].first <= C[i]) j++;
			if (min(k, j) > 0) chkmax(ans, V[i][k].second + val[i][min(k, j)]);
		}
	}
	if (!V[0].empty() && !V[1].empty()) {
		chkmax(ans, val[0][sz(V[0])] + val[1][sz(V[1])]);
	}
	cout << ans << endl;
	return 0;
}