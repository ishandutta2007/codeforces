#include <bits/stdc++.h>
using namespace std;

const int MX = 105;

int a[MX];

int main() {
	
//	freopen("5.in", "r", stdin);
//	freopen("5.out", "w", stdout);
	
	int n; scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++) scanf("%d", a + i);
	
	int cnt = 0;
	for (int i = 1; i <= 2 * n; i += 2) {
		for (int j = i + 1; j <= 2 * n; j++) if (a[i] == a[j]) {
			for (int k = j; k > i; k--) a[k] = a[k - 1], cnt++;
			cnt--;
			break;
		}
	}
	
	printf("%d\n", cnt);
	
	return 0;
	
}