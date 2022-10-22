#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define all(x) x.begin(), x.end()

using namespace std;

int n;
LL a[10], W;
LL b[10];

int main() {
	srand(1337);
	scanf ("%lld", &W);
	LL sum = 0;
	rep(i, 1, 8) {
		scanf ("%lld", a + i);
		sum += a[i] * i;
	}
	if (sum <= W || !sum) {
		return printf ("%lld\n", sum), 0;
	}
	LL ans = 0;
	sum = 0;
	rep(i, 1, 8) {
		LL x = (W - sum) / i;
		b[i] = min(a[i], x);
		sum += b[i] * i;
	}
	rep(i, 1, 1000000) {
		ans = max(ans, sum);
		int r = rand() % 8 + 1;
		if (b[r] < a[r]) {
			sum += r;
			b[r]++;
		}
		while (sum > W) {
			r = rand() % 8 + 1;
			if (b[r]) {
				sum -= r;
				b[r]--;
			}
		}
	}
	printf ("%lld", ans);
			
		
		
	
	return 0;
}