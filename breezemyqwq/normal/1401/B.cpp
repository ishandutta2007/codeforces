#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b, c, x, y, z, sum = 0;
		scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
		int k = min(c, y);
		c -= k, y -= k;
		sum += k + k;
		k = b - x - y;
		if(k > 0) {
			sum -= min(k, z) * 2;
		}		
		printf("%d\n", sum);
	}
	return 0;
}