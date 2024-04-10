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

int T, n, m, a, s;

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &m);
		s = 0;
		rep(i, 1, n) {
			scanf ("%d", &a);
			s += a;
		}
		printf (s == m ? "YES\n" : "NO\n");
	}
	return 0;
}