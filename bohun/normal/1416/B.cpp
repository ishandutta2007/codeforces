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

const int N = 5e4 + 500;

int T, n, a[N], roz;
int x[N], y[N], z[N];
 
int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		int s = 0;
		rep(i, 1, n) { 
			scanf ("%d", a + i);
			s += a[i];
		}
		if (s % n != 0) {
			printf ("-1\n");
			continue;
		}
		roz = 0;
		rep(i, 2, n) {
			++roz;
			x[roz] = 1;
			y[roz] = i;
			z[roz] = (i - a[i] % i) % i;
			a[1] -= z[roz];
			a[i] += z[roz];
			
			++roz;
			x[roz] = i;
			y[roz] = 1;
			z[roz] = a[i] / i;
			a[1] += z[roz] * i;
			a[i] = 0;
		}
		assert(a[1] == s);
		int q = s / n;
		rep(i, 2, n) {
			++roz;
			x[roz] = 1;
			y[roz] = i;
			z[roz] = q;
		}
		printf ("%d\n", roz);
		rep(i, 1, roz)
			printf ("%d %d %d\n", x[i], y[i], z[i]);
	}
	
	return 0;
}