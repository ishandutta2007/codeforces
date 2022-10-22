#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[200005], dp[200005];
int n;
int main () {
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) scanf ("%lld",&a[i]);
	for (int i = 2; i <= n; i++) a[i] += a[i-1];
	dp[n] = 0; ll mx = a[n];
	for (int i = n-1; i >= 1; i--) {
		dp[i] = mx;
		mx = max(mx,-dp[i]+a[i]);
	}
	printf ("%lld\n",dp[1]);
	return 0;
}