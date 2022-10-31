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

map<string, int> M, S;

char t[55], s[55];
int tn, L, ans;

void dfs(char *s, int cur) {
	if (cur == L) {
		t[tn] = 0;
		if (!S.count(t)) S[t] = 1, ans += M[t];
		return;
	}
	if (s[cur] == '?') {
		dfs(s, cur+1);
		for (int j = 0; j < 5; j++) {
			t[tn++] = 'a'+j;
			dfs(s, cur+1);
			t[--tn] = 0;
		}
	} else {
		t[tn++] = s[cur];
		dfs(s, cur+1);
		t[--tn] = 0;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		char s[55]; memset(s, 0, sizeof s);
		scanf("%s", s);
		M[s]++;
	}
	for (int i = 0; i < m; i++) {
		char s[55]; memset(s, 0, sizeof s);
		scanf("%s", s);
		S.clear();
		memset(t, 0, sizeof t);
		L = strlen(s);
		tn = ans = 0;
		dfs(s, 0);
		printf("%d\n", ans);
	}
	return 0;
}