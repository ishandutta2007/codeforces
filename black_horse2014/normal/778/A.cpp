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

char s[222222], t[222222];
int n, m, a[222222];
int chk[222222];

bool can(int mid) {
	memset(chk, 0, sizeof chk);
	for (int i = 1; i <= mid; i++) chk[a[i]] = 1;
	for (int i = 1, j = 1; i <= n; i++) {
		if (chk[i]) continue;
		if (t[i] == s[j]) j++;
		if (j > m) return 1;
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%s%s", t + 1, s + 1);
	n = strlen(t+1);
	m = strlen(s+1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int lo = 0, hi = n;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (can(mid)) lo = mid;
		else hi = mid;
	}
	cout << lo << endl;
	return 0;
}