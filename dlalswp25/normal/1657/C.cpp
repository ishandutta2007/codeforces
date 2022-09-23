#include <bits/stdc++.h>

using namespace std;

int N;
char A[505050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int lst = 0, ans = 0;
		int p = 1;
		while(p < N) {
			if(A[p] == '(') {
				ans++; lst = p + 1;
				p += 2;
				continue;
			}
			for(p++; p <= N; p++) {
				if(A[p] == ')') {
					ans++; lst = p;
					break;
				}
			}
			p++;
		}
		printf("%d %d\n", ans, N - lst);
	}
	return 0;
}