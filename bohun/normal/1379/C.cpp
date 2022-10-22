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

const int N = 1e5 + 10;

int T;
int n, m, b[N], gdzie[N];
pair<int, int> a[N];
ll suf[N];

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &m);
		rep(i, 1, m) {
			scanf ("%d%d", &a[i].fi, b + i);
			a[i].se = i;
		}
		sort(a + 1, a + m + 1);
		suf[m + 1] = 0;
		per(i, 1, m) {
			suf[i] = suf[i + 1] + a[i].fi;
			gdzie[a[i].se] = i;
		}
		ll best = suf[max(1, m - n + 1)];
		rep(i, 1, m) {
			int p = upper_bound(a + 1, a + m + 1, mp(b[i], 0)) - a;
			ll now = suf[p];
			ll q = n - (m - p + 1);
			if (gdzie[i] < p) {
				q--;
				now += a[gdzie[i]].fi;
			}
			if (q <= 0) continue;
			now += q * b[i];
			best = max(best, now);
		}
		printf ("%lld\n", best);
	}
			
	return 0;
}