#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int A, B; scanf("%d%d", &A, &B);
		int ans = 1010101010;
		for(int i = 0; i < 100; i++) {
			int a = A, b = B + i;
			if(b == 1) continue;
			int cnt = i;
			while(a) { cnt++; a /= b; }
			ans = min(ans, cnt);
		}
		printf("%d\n", ans);
	}
	return 0;
}