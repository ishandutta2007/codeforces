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

const int N = 2e5 + 5;

int t, n, l, a[N];
ld L[N], R[N];

void solve() {
	scanf ("%d%d", &n, &l);
	rep(i, 1, n)
		scanf ("%d", a + i);
	rep(i, 1, n)
		L[i] = L[i - 1] + (ld) (a[i] - a[i - 1]) / i;
	R[n + 1] = 0;
	a[n + 1] = l;
	per(i, 1, n)
		R[i] = R[i + 1] + (ld) (a[i + 1] - a[i]) / (n - i + 1);
	rep(i, 0, n) {
		if (L[i] <= R[i + 1] && R[i + 1] <= L[i + 1]) {
			ld droga = a[i + 1] - a[i] - (i + 1) * (R[i + 1] - L[i]);
			printf ("%.10Lf\n", R[i + 1] + droga / (n + 2));
			return;
		}
	}
	per(i, 0, n + 1) {
		if (R[i] <= L[i - 1] && L[i - 1] <= R[i - 1]) {
			ld droga = a[i] - a[i - 1] - (n - i + 1 + 1) * (L[i - 1] - R[i]);
			printf ("%.10Lf\n", L[i - 1] + droga / (n + 2));
			return;
		}
	}
}
	

int main() {
	scanf ("%d", &t);
	while (t--)
		solve();
	
	return 0;
}