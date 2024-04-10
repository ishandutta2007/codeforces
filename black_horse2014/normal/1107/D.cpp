#include <bits/stdc++.h>
using namespace std;

const char str[] = "0123456789ABCDEF";

bool a[5500][5500];
int sum[5500][5500];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char s[1500]; scanf("%s", s);
		for (int k = 0; k < n/4; k++) {
			int u = strchr(str, s[k]) - str;
			for (int j = 0; j < 4; j++) a[i][k*4+j] = u>>(3-j)&1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + a[i][j];
		}
	}
	for (int x = n; x >= 1; x--) if (n % x == 0) {
		int m = x;
		bool flg = 1;
		for (int i = 0; flg && i < n/x; i++) {
			for (int j = 0; j < n/x; j++) {
				int tot = sum[(i+1)*x][(j+1)*x] - sum[(i+1)*x][j*x] - sum[i*x][(j+1)*x] + sum[i*x][j*x];
				if (tot % (x * x) != 0) {
					flg = 0;
					break;
				}
			}
		}
		if (flg) {
			cout << x << endl;
			return 0;
		}
	}
	return 0;
}