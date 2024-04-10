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

int con[MAXN][26];
int ans[MAXN];

int process(vector<int> a){
	int ret = a.size() - 1;
	for (int j = 0; j < 26; j++) {
		vector<int> b;
		for (int i = 0; i < a.size(); i++) if(con[a[i]][j]) b.pb(con[a[i]][j]);
		if(b.size() <= 1) continue;
		ret += process(b);
	}
	return ret;
}

void dfs(int u, int d) {
	vector<int> ret;
	for (int i = 0; i < 26; i++) {
		if (con[u][i]) {
			ret.push_back(con[u][i]);
		}
	}
	ans[d] += process(ret)+1;
	for (int i = 0; i < 26; i++) {
		if (con[u][i]) dfs(con[u][i], d + 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; char c[3];
		scanf("%d%d%s", &u, &v, c);
		con[u][c[0] - 'a'] = v;
	}
	dfs(1, 1);
	int mx = -1, id = 0;
	for (int i = 1; i <= n; i++) if (ans[i] > mx) mx = ans[i], id = i;
	printf("%d\n%d\n", n - mx, id);
	return 0;
}