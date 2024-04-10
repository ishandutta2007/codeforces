#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll mul(ll a, ll b, ll cap) {
	ll ret = 0;
	while(b) {
		if(b & 1) ret += a;
		a += a;
		b >>= 1;
		ret = min(ret, cap);
		a = min(a, cap);
	}
	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ll s, n, k; scanf("%lld%lld%lld", &s, &n, &k);
		if(k > s) { puts("NO"); continue; }
		if(k == s) { puts("YES"); continue; }
		ll mn = mul(2 * k, n / k, s + 1) + n - (n / k) * k;
		puts(mn > s ? "YES" : "NO");
	}
	return 0;
}