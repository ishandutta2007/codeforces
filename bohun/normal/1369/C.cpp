#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;	

const int N = 2e5 + 10;

int n, k, a[N], w[N];

int main() {				
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &k);
		rep(i, 1, n) scanf ("%d", a + i);
		int ones = 0;
		rep(i, 1, k) scanf ("%d", w + i), ones += w[i] == 1;
		sort(a + 1, a + n + 1);
		sort(w + 1, w + k + 1);
		ll ans = 0;
		per(i, n - k + 1, n) {
			ans += a[i];
			if (i + ones - 1 >= n)
				ans += a[i];
		}
		int j = n - k;
		rep(i, 1, k) {
			if (w[i] == 1) continue;
			j -= (w[i] - 2);
			ans += a[j];
			j--;
		}
		printf ("%lld\n", ans);
	}
	return 0;
}