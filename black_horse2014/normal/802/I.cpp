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

const int MAXN = 222222;

char s[MAXN];
int L[MAXN], C[MAXN], E[MAXN][26], P[MAXN], ID[MAXN], cnt[MAXN];
int n, m, cur;

void extend(int c) {
	int x = cur, y = cur = ++m;
	L[cur] = L[x] + 1, C[cur] = 1;
	for (; x && !E[x][c]; x = P[x]) E[x][c] = y;
	if (!x) P[y] = 1;
	else {
		int z = E[x][c];
		if (L[z] == L[x] + 1) P[y] = z;
		else {
			int u = ++m; L[u] = L[x] + 1, memcpy(E[u], E[z], sizeof(E[u])), P[u] = P[z], P[z] = P[y] = u;
			for (; x && E[x][c] == z; x = P[x]) E[x][c] = u;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		memset(E, 0, sizeof E);
		memset(L, 0, sizeof L);
		memset(P, 0, sizeof P);
		memset(C, 0, sizeof C);
		m = cur = 1;
		scanf("%s", s);
		n = strlen(s);
		for (int i = 0; s[i]; i++) extend(s[i] - 'a');
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= m; i++) cnt[L[i]]++;
		for (int i = 1; i <= n; i++) cnt[i] += cnt[i-1];
		for (int i = m; i > 0; i--) ID[cnt[L[i]]--] = i;
		for (int i = m, u; i > 0; i--) u = ID[i], C[P[u]] += C[u];
		unsigned long long ans = 0;
		for (int i = 1; i <= m; i++) ans += 1ULL*C[i]*C[i]*(L[i]-L[P[i]]);
		cout << ans << endl;
	}
	return 0;
}