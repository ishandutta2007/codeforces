#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int a[5];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	a[4] = n; a[2] = 2 * n;
	for (int i = 1; i <= k; i++) {
		int value;
		scanf("%d", &value);
		while (value > 0 && (a[1] || a[2] || a[4])) {
			if (value >= 4) {
				if (a[4]) {
					value -= 4;
					a[4]--;
				} else {
					if (a[2]) {
						value -= 2;
						a[2]--;
					} else {
						value--;
						a[1]--;
					}
				}
			}
			if (!(a[1] || a[2] || a[4])) break;
			if (value == 3) {
				if (a[2]) {
					value -= 2;
					a[2]--;
				} else {
					if (a[1]) {
						value--;
						a[1]--;
					} else {
						value -= 3;
						a[4]--;
					}
				}
			}
			if (!(a[1] || a[2] || a[4])) break;
			if (value == 2) {
				if (a[2]) {
					value -= 2;
					a[2]--;
				} else {
					if (a[4]) {
						value -= 2;
						a[4]--;
						a[1]++;
					} else {
						value--;
						a[1]--;
					}
				}
			}
			if (!(a[1] || a[2] || a[4])) break;
			if (value == 1) {
				if (a[1]) {
					value--;
					a[1]--;
				} else {
					if (a[4]) {
						value--;
						a[4]--;
						a[2]++;
					} else {
						value--;
						a[2]--;
					}
				}
			}
		}
		if (value > 0) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}