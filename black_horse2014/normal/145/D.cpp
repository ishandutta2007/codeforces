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

int val[1030];
int tot;

const int MAXN = 1<<18;

int a[MAXN];
int L[2][MAXN], len[MAXN];
long long ans[MAXN];

VI A[MAXN];
VI V;
int n;

long long C(int x, int m) {
	long long ret = 1;
	for (int i = 1; i <= m; i++) ret *= (x-i+1), ret /= i;
	return ret;
}

int get_id(int x) {
	int ret = lower_bound(val, val + tot, x) - val;
	if (ret == tot || val[ret] != x) return -1;
	return ret;
}

void up(int u) {
	L[0][u] = L[0][u+u], L[1][u] = L[1][u+u+1];
	if (L[0][u] == len[u+u]) L[0][u] += L[0][u+u+1];
	if (L[1][u] == len[1+u+u]) L[1][u] += L[1][u+u];
	ans[u] = ans[u+u] + ans[u+u+1] + 1LL*L[1][u+u]*L[0][u+u+1];
}

void update(int u, int l, int r, int x) {
	if (l == r) {
		L[0][u]--; L[1][u] = 0; ans[u] = C(len[u], 2);
		return;
	}
	int mid = l + r >> 1;
	if (x <= mid) update(u + u, l, mid, x);
	else update(u + u + 1, mid + 1, r, x);
	up(u);
}

int prev;
LL ret;

void get(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) {
		ret += ans[u] + 1LL * L[0][u] * prev;
		if (L[0][u] == len[u]) prev += len[u];
		else prev = L[1][u];
		return;
	}
	int mid = l + r >> 1;
	if (ll <= mid) get(u + u, l, mid, ll, rr);
	if (mid < rr) get(u + u + 1, mid + 1, r, ll, rr);
}

void build(int u, int l, int r) {
	len[u] = ((r == sz(V) ? n : V[r]) - (l == 0 ? 0 : V[l-1]));
	if (l == r) {
		L[0][u] = L[1][u] = len[u], ans[u] = C(len[u]+1, 2);
		return;
	}
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(1 + u + u, mid + 1, r);
	up(u);
}

long long query(int l, int r) {
	if (l > r) return 0;
	prev = ret = 0;
	get(1, 0, sz(V), l, r);
	return ret;
}

int seen[1111];

int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j < bit(i); j++) {
			int x = 0;
			for (int k = 0; k < i; k++) {
				x *= 10;
				if (j >> k & 1) {
					x += 7;
				} else {
					x += 4;
				}
			}
			val[tot++] = x;
		}
	}
	sort(val, val + tot);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		a[i] = get_id(x);
		if (~a[i]) {
			V.push_back(i);
			A[a[i]].push_back(V.size()-1);
		}
	}
	for (int i = 0; i < tot; i++) reverse(all(A[i]));
	long long ans = 1LL*(n+2)*(n+1)*n/6;
	int p = n-1, q = 4;
	while (ans % 2 == 0 && q % 2 == 0) q /= 2, ans /= 2;
	ans *= p; ans /= q;
	for (int i = 0; i < sz(V)-1; i++) {
		memset(seen, 0, sizeof seen);
		build(1, 0, sz(V));
		int last = n;
		for (int j = i; j >= 0; j--) {
			int x = a[V[j]];
			if (!seen[x]) {
				seen[x] = 1;
				for (int k = 0; k < A[x].size() && A[x][k] > i; k++) {
					update(1, 0, V.size(), A[x][k]);
					chkmin(last, V[A[x][k]] - 1);
				}
			}
			{
				int st = (j == 0 ? 1 : V[j-1] + 1), en = V[j];
				ans -= 1LL*(en-st+1)*(V[i+1]-V[i])*(C(n-V[i+1]+1, 2) - query(i+2, sz(V)));
			}
			{
				int st = (j == 0 ? 1 : V[j-1] + 1), en = V[j];
				ans -= 1LL*(en-st+1)*C(V[i+1]-V[i]+1, 2)*(n-last);
			}
		}
	}
	cout << ans << endl;
	return 0;
}