#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N];
int k[N];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			k[i] = a[i];
		}
		sort(a + 1, a + n + 1);
		bool flag = true;
		for(int i = 2; i <= n; i++) {
			if(a[i] != k[i] && a[i] % a[1]) {
				flag = false;
				break;
			}
		}
		flag ? puts("YES") : puts("NO");
	}
	return 0;
}