#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		if(n >= k) {
			if((n % 2) == (k % 2)) printf("0\n");
			else printf("1\n");
		}
		else {
			printf("%d\n", k - n);
		}
	}
	return 0;
}