#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5 + 5, MOD = 1e9 + 7;
int main () {
	int n;
	scanf ("%d",&n);
	vector<int> cnt(100);
	vector<vector<ll>> grid(n+1,vector<ll>(n+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int dist = i + j - 2; assert((1LL << (dist - 1)) <= 1e16);
			if ((++cnt[dist])&1) {
				printf ("%lld%c",grid[i][j] = 0," \n"[j==n]);
			} else {
				printf ("%lld%c",grid[i][j] = (1LL << (dist - 1))," \n"[j==n]);
			}
		}
	}
	fflush(stdout);
	int q;
	scanf ("%d",&q);
	while (q--) {
		ll k;
		scanf ("%lld",&k);
		int curx = 1, cury = 1;
		printf ("1 1\n");
		for (int i = 0; i < 2*n-2; i++) {
			if (i == 2 * n - 3) {
				curx = n; cury = n;
			} else {
				if (k>>i&1) {
					if (curx < n && (grid[curx+1][cury]>>i&1)) ++curx;
					else ++cury;
				} else {
					if (curx<n&&!(grid[curx+1][cury]>>i&1)) ++curx;
					else ++cury;
				}
			}
			printf ("%d %d\n",curx,cury);
		}
		fflush(stdout);
	}
	return 0;
}