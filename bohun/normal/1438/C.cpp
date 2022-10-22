#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
// c0 3f
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 120;

int T, n, m, a[N][N], b[N][N];

void solve() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, n)
		rep(j, 1, m) 
			scanf ("%d", &a[i][j]);
	rep(i, 1, n) {
		rep(j, 1, m) {
			if (a[i][j] % 2 == 0) {
				printf ("%d ", a[i][j] + (i + j) % 2);
			}
			else {
				printf ("%d ", a[i][j] + 1 - (i + j) % 2);
			}
		}
		puts("");
	}
	
}

int main() {
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
		
	return 0;
}