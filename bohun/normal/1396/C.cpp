#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;

using namespace std;

const int N = 1e6 + 10;

int n;

ll a[N], r1, r2, r3, d;
ll black[N], white[N], dp[N], suf[N];

void umin(ll &a, ll b) {
	a = min(a, b);
}

int main() {
	scanf ("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
	for (int i = 1; i <= n; ++i) { 
		scanf ("%lld", a + i);
		black[i] = a[i] * r1 + r3;
		white[i] = min((a[i] + 1) * r1, ll(r2));
	}
		
	for (int i = 1; i <= n; ++i) {
		dp[i] = 1e18;
		umin(dp[i], dp[i - 1] + d + black[i]);
		umin(dp[i], dp[i - 1] + 3 * d + white[i] + r1);
		if (i > 1)
			umin(dp[i], dp[i - 2] + 4 * d + white[i - 1] + white[i] + r1 + r1);
	}
	
	for (int i = n - 1; 1 <= i; --i) {
		suf[i] = suf[i + 1] + min(black[i], white[i] + r1);
	}
	
	ll out = 1e18;
	
	for (int e = 1; e <= n; ++e) {
		ll now = dp[e - 1] - (e > 1 ? d : 0) + suf[e] + min(black[n], white[n] + r1 + 2 * d) + 2 * ll(d) * (n - e) + (e > 1 ? d : 0);
		//cat(e);
		//cat(now);
		umin(out, now);
	}
	
	printf ("%lld\n", min(out, dp[n] - d));
	
	return 0;
}