#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	int T; cin >> T;
	while (T--) {
		int x; cin >> x;
		if (x == 9) {
			printf("1\n");
			continue;
		}
		int ans = 0;
		if (x & 1) {
			x -= 9;
			ans++;
		}
		if (x < 4) {
			printf("-1\n");
			continue;
		}
		int tmp = x / 2;
		if (tmp & 1) {
			tmp -= 3;
			ans++;
		}
		ans += tmp / 2;
		printf("%d\n", ans);
	}
	return 0;
}