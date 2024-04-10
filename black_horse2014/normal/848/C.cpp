#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
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

#define prev as
#define next df

const int MAXN = 1<<18;

vector<int> V[MAXN];
vector<long long> A[MAXN];
set<int> S[MAXN];
int prev[MAXN], next[MAXN], a[MAXN], b[MAXN], t[MAXN], l[MAXN], r[MAXN];
long long sum[MAXN];

void insert(int u, int l, int r, int p) {
	V[u].push_back(prev[p]);
	if (l == r) return;
	int mid = l + r >> 1;
	if (p <= mid) insert(u + u, l, mid, p);
	else insert(u + u + 1, mid + 1, r, p);
}

void add(int u, int l, int r, int p, int s) {
	for (int i = lower_bound(all(V[u]), prev[p]) - V[u].begin() + 1; i <= sz(V[u]); i += i & -i) A[u][i] += s * (p - prev[p]);
	sum[u] += s * (p - prev[p]);
	if (l == r) return;
	int mid = l + r >> 1;
	if (p <= mid) add(u + u, l, mid, p, s);
	else add(u + u + 1, mid + 1, r, p, s);
}

long long get(int u, int p) {
	long long ret = 0;
	for (p = upper_bound(all(V[u]), p) - V[u].begin(); p; p -= p & -p) ret += A[u][p];
	return ret;
}

long long query(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) return sum[u] - get(u, ll - 1);
	int mid = l + r >> 1;
	long long ret = 0;
	if (ll <= mid) ret += query(u + u, l, mid, ll, rr);
	if (mid < rr) ret += query(u + u + 1, mid + 1, r, ll, rr);
	return ret;
}

int seen[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), S[a[i]].insert(i), S[i].insert(0), S[i].insert(n+1);
	for (int i = 1; i <= n; i++) b[i] = a[i];
	for (int i = 1; i <= n; i++) {
		prev[i] = seen[a[i]];
		seen[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) seen[i] = n + 1;
	for (int i = n; i > 0; i--) {
		next[i] = seen[a[i]];
		seen[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) insert(1, 1, n, i);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &t[i], &l[i], &r[i]);
	for (int i = 1; i <= m; i++) {
		if (t[i] == 1) {
			int p = l[i], x = r[i];
			if (x != a[p]) {
				if (prev[p] >= 1) next[prev[p]] = next[p];
				if (next[p] <= n) {
					prev[next[p]] = prev[p];
					insert(1, 1, n, next[p]);
				}
				S[a[p]].erase(p);
				a[p] = x;
				set<int> :: iterator it = S[x].lower_bound(p);
				next[p] = *it, prev[p] = *(--it);
				S[x].insert(p);
				insert(1, 1, n, p);
				if (next[p] <= n) prev[next[p]] = p, insert(1, 1, n, next[p]);
				if (prev[p] >= 1) next[prev[p]] = p;
			}
		}
	}
	for (int i = 0; i < MAXN; i++) sort(all(V[i])), V[i].erase(unique(all(V[i])), V[i].end()), A[i].resize(V[i].size() + 1);
	for (int i = 1; i <= n; i++) seen[i] = 0, S[i].clear(), S[i].insert(0), S[i].insert(n + 1), a[i] = b[i];
	for (int i = 1; i <= n; i++) {
		S[a[i]].insert(i);
		prev[i] = seen[a[i]];
		seen[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) seen[i] = n + 1;
	for (int i = n; i > 0; i--) {
		next[i] = seen[a[i]];
		seen[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) add(1, 1, n, i, 1);
	for (int i = 1; i <= m; i++) {
		if (t[i] == 1) {
			int p = l[i], x = r[i];
			if (x != a[p]) {
				add(1, 1, n, p, -1);
				if (prev[p] >= 1) next[prev[p]] = next[p];
				if (next[p] <= n) {
					add(1, 1, n, next[p], -1);
					prev[next[p]] = prev[p];
					add(1, 1, n, next[p], 1);
				}
				S[a[p]].erase(p);
				a[p] = x;
				set<int> :: iterator it = S[x].lower_bound(p);
				next[p] = *it, prev[p] = *(--it);
				S[x].insert(p);
				add(1, 1, n, p, 1);
				if (next[p] <= n) {
					add(1, 1, n, next[p], -1);
					prev[next[p]] = p;
					add(1, 1, n, next[p], 1);
				}
				if (prev[p] >= 1) next[prev[p]] = p;
			}
		} else {
			printf("%I64d\n", query(1, 1, n, l[i], r[i]));
		}
	}
	return 0;
}