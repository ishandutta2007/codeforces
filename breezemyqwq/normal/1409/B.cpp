#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int a, b, x, y, n;
		scanf("%d%d%d%d%d", &a, &b, &x, &y, &n);
		int ta = max(x, a - n), tb = max(y, b - n);
		if(ta > tb) {
			swap(a, b);
			swap(x, y);
		}
		if(a - x <= n) {
			n -= a - x;
			a = x;
			b = max(y, b - n);
		} 
		else a -= n;
		long long tmp = 1ll * a * b;
		printf("%lld\n", tmp);
	}
	return 0;
}