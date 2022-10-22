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

int T, n;
ll k, a[200005];

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &k);
		rep(i, 1, n) {
			scanf("%lld", a + i);
		}
		bool done = 0;
		rep(i, 1, n) {
			if (a[i] <= k && 2 * a[i] >= k) {
				done = 1;
				printf ("1\n%d\n", i);
				break;
			}
		}
		if (done) continue;
		vector <int> q;
		rep(i, 1, n)
			if (a[i] <= k)
				q.pb(i);
		ll sum = 0;
		for (auto x : q)
			sum += a[x];
		if (2 * sum < k) {
			printf ("-1\n");
			continue;
		}
		vector <int> res;
		sum = 0;
		for (auto x : q) {
			sum += a[x];
			res.pb(x);
			if (2 * sum >= k)
				break;
		}
		printf ("%d\n", sz(res));
		for (auto x : res)
			printf ("%d ", x);
		puts("");
	}
	return 0;
}