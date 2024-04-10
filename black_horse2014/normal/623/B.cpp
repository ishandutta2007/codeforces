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

const int MAXN = 1111111;

vector<int> V;

void factor(int x) {
	for (int i = 2; 1LL * i * i <= x; i++) {
		if (x % i != 0) continue;
		while (x % i == 0) x /= i;
		V.push_back(i);
	}
	if (x > 1) V.push_back(x);
}

const long long INF = 1LL<<60;

int p[MAXN];
long long L[MAXN], R[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, a, b; scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = -1; i <= 1; i++) {
		factor(p[1] + i);
		factor(p[n] + i);
	}
	sort(all(V));
	V.erase(unique(all(V)), V.end());
	long long ans = 1LL * (n - 1) * a;
	for (int i = 0; i < sz(V); i++) {
		int x = V[i];
		L[0] = 0;
		for (int j = 1; j <= n; j++) {
			if (p[j] % x == 0) {
				L[j] = L[j-1];
			} else if ((p[j]-1) % x == 0 || (p[j]+1) % x == 0) {
				L[j] = L[j-1] + b;
			} else {
				L[j] = INF;
			}
		}
		R[n+1] = 0;
		for (int j = n; j > 0; j--) {
			if (p[j] % x == 0) {
				R[j] = R[j+1];
			} else if ((p[j]-1) % x == 0 || (p[j]+1) % x == 0) {
				R[j] = R[j+1] + b;
			} else {
				R[j] = INF;
			}
		}
		long long ret = INF;
		for (int j = n; j >= 0; j--) {
			if (R[j+1] < INF) {
				chkmin(ret, R[j+1] + 1LL * a * j);
			}
			if (L[j] < INF) {
				chkmin(ans, ret + L[j] - 1LL * a * j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}