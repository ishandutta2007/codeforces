#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
int a[55], b[55];
int amin, bmin;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		amin = bmin = inf;
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			amin = min(amin, a[i]);
		}
		for(int i = 1; i <= n; i++) {
			scanf("%d", b + i);
			bmin = min(bmin, b[i]);
		}
		long long sum = 0;
		for(int i = 1; i <= n; i++) {
			int xi = a[i] - amin, yi = b[i] - bmin;
			int k = min(xi, yi);
			sum += xi + yi - k;
		}
		printf("%lld\n", sum);
	}
	return 0;
}