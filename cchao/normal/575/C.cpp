#include <bits/stdc++.h>
using namespace std;
const int maxn = 20, inf = INT_MAX;
int ans;
struct KM {
	int n, w[maxn][maxn];
	int lx[maxn], ly[maxn], match[maxn], slack[maxn];
	bool s[maxn], t[maxn];
	inline bool hungary(int x) {
		s[x] = true;
		for(int y = 0; y < n; ++y)
			if(!t[y] && lx[x] + ly[y] == w[x][y]) {
				t[y] = true;
				if(match[y] == -1 || hungary(match[y])) {
					match[y] = x;
					return true;
				}
			}
			else slack[y] = min(slack[y], lx[x] + ly[y] - w[x][y]);
		return false;
	}
	inline int solve() {
		int magic;
		magic = 0;
		for(int i = 0; i < n; ++i) {
			lx[i] = *max_element(w[i], w[i] + n);
			magic += lx[i];
		}
		if(magic <= ans) return 0;
		memset(match, -1, n << 2);
		memset(ly, 0, n << 2);
		for(register int i = 0; i < n; ++i) {
			for(;;) {
				memset(s, 0, n);
				memset(t, 0, n);
				memset(slack, 0x7f, n<<2);
				if(hungary(i)) break;
				else {
					int a = inf;
					for(register int j = 0; j < n; ++j) if(!t[j] && slack[j] < a)
						a = slack[j];
					magic = 0;
					for(register int j = 0; j < n; ++j) {
						if(s[j]) lx[j] -= a;
						if(t[j]) ly[j] += a;
						magic += lx[j] + ly[j];
					}
					if(magic <= ans) {
						return 0;
					}
				}
			}
		}
		ans = magic;
		return magic;
	}
} sol;
int main() {
	auto bmb = clock() + 1.9 * CLOCKS_PER_SEC;
	int n;
	scanf("%d", &n);
	sol.n=n;
	int a[20][20], b[20][20];
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scanf("%d", &b[i][j]);
	ans = 0;
	int m = n >> 1;
	for(int i = 0; i < (1 << (n-1)); ++i) if(__builtin_popcount(i) == m) {
		for(int j = 0; j < n; ++j) {
			memcpy(sol.w[j], (i & (1 << j)) ? a[j] : b[j], n<<2);
		}
		sol.solve();
		for(int j = 0; j < n; ++j) {
			memcpy(sol.w[j], (i & (1 << j)) ? b[j] : a[j], n<<2);
		}
		sol.solve();
		if(clock() >= bmb) break;
	}
	printf("%d\n", ans);
	return 0;
}