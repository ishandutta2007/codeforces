#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		int tmp = y - x;
		int lst = -1;
		for(int i = 1; i <= tmp; i++) {
			if(tmp % i == 0 && tmp / i + 1 <= n) {
				lst = i;
				break;
			}
		}
		if(tmp / lst + (x - 1) / lst + 1 >= n) {
			for(int i = 1; i <= n; i++) {
				printf("%d ", y);
				y -= lst;
			}
		}
		else {
			int k = tmp / lst + (x - 1) / lst + 1;
			int now = y;
			for(int i = 1; i <= k; i++) {
				printf("%d ", now);
				now -= lst;
			}
			for(int i = 1; i <= n - k; i++) {
				y += lst;
				printf("%d ", y);
			}
		}
		puts("");
	}
	return 0;
}