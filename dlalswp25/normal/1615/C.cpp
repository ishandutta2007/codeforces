#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];
char B[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		scanf("%s", B + 1);
		int ans = N + 1;

		int zero = 0, one = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] != B[i]) {
				if(A[i] == '0') zero++;
				else one++;
			}
		}

		if(zero == one) ans = min(ans, zero + one);

		zero = one = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == B[i]) {
				if(A[i] == '0') zero++;
				else one++;
			}
		}
		if(zero + 1 == one) ans = min(ans, zero + one);

		printf("%d\n", ans > N ? -1 : ans);
	}
	return 0;
}