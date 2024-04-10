#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			ans |= a;
		}
		printf("%d\n", ans);
	}
	return 0;
}