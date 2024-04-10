#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N >= 20) { puts("NO"); continue; }
		puts("YES");
		int x = 1;
		for(int i = 1; i <= N; i++) {
			printf("%d ", x);
			x *= 3;
		}
		puts("");
	}
	return 0;
}