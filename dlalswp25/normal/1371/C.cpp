#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll a, b, n, m;
		scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
		if(a + b < n + m) { puts("No"); continue; }
		if(min(a, b) < m) { puts("No"); continue; }
		puts("Yes");
	}
	return 0;
}