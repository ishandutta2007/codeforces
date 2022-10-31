#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, a[N], b[N], c[N];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		sum += b[i];
	}
	if (sum > n) {
		puts("NO");
		return 0;
	}
	for (int i = 0; i < n - sum + 1; i++) {
		memset(c, 0, sizeof(c));
		for (int j = i; j < i + sum; j++) {
			c[a[j]]++;
		}
		bool flag = true;
		for (int j = 1; j <= m && flag; j++)
			if (b[j] != c[j])
				flag = false;
		if (flag) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}