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

const int MAXN = 12e4 + 12;

int cnt[MAXN], a[MAXN], b[MAXN], c[MAXN], d[MAXN], used[MAXN];
VI V[MAXN];

set<PII> S;

int get(int x, int y, int z) {
	cnt[x]--, cnt[y]++, cnt[z]++;
	int ret = max(cnt[x], max(cnt[y], cnt[z]));
	cnt[x]++, cnt[y]--, cnt[z]--;
	return ret;
}

VI ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= 4*n; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		V[a[i]].push_back(i);
		V[b[i]].push_back(i);
		V[c[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) cnt[i] = 4;
	for (int i = 1; i <= 4*n; i++) d[i] = get(a[i], b[i], c[i]), S.insert(PII(d[i], i));
	for (int times = 0; times < 4*n; times++) {
		set<PII> :: iterator it = S.begin();
		int i = it->second;
		S.erase(it);
		used[i] = 1;
		if (d[i] > 9) {
			puts("NO");
			return 0;
		}
		ans.push_back(i);
		cnt[a[i]]--, cnt[b[i]]++, cnt[c[i]]++;
		for (int j = 0; j < sz(V[a[i]]); j++) {
			int k = V[a[i]][j];
			if (used[k]) continue;
			int now = get(a[k], b[k], c[k]);
			if (d[k] == now) continue;
			S.erase(PII(d[k], k));
			d[k] = now;
			S.insert(PII(d[k], k));
		}
		for (int j = 0; j < sz(V[b[i]]); j++) {
			int k = V[b[i]][j];
			if (used[k]) continue;
			int now = get(a[k], b[k], c[k]);
			if (d[k] == now) continue;
			S.erase(PII(d[k], k));
			d[k] = now;
			S.insert(PII(d[k], k));
		}
		for (int j = 0; j < sz(V[c[i]]); j++) {
			int k = V[c[i]][j];
			if (used[k]) continue;
			int now = get(a[k], b[k], c[k]);
			if (d[k] == now) continue;
			S.erase(PII(d[k], k));
			d[k] = now;
			S.insert(PII(d[k], k));
		}
	}
	puts("YES");
	for (int i = 0; i < 4*n; i++) printf("%d ", ans[i]);
	return 0;
}