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
 
using ll = long long;
using ld = long double;
using namespace std;

int n, t[10005][3], res[100005];

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		rep(j, 0, 2)
			rep(i, 0, n - 1)
				scanf ("%d", &t[i][j]);
		int last = -1;
		rep(i, 0, n - 1) {
			rep(j, 0, 2) {
				if (t[i][j] == last) continue;
				if (i == n - 1 && t[i][j] == res[0]) continue;
				res[i] = last = t[i][j];
				break;
			}
			printf ("%d ", res[i]);
		}
		puts("");
	}
	return 0;
}