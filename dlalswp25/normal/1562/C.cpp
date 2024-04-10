#include <bits/stdc++.h>

using namespace std;

int N;
char A[20202];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		bool ok = false;
		for(int i = 1; i <= N / 2; i++) {
			if(A[i] == '0') {
				printf("%d %d %d %d\n", i, N, i + 1, N);
				ok = true;
				break;
			}
		}
		if(ok) continue;
		for(int i = N / 2 + 1; i <= N; i++) {
			if(A[i] == '0') {
				printf("%d %d %d %d\n", 1, i, 1, i - 1);
				ok = true;
				break;
			}
		}
		if(ok) continue;
		printf("%d %d %d %d\n", 1, N - 1, 2, N);
	}
	return 0;
}