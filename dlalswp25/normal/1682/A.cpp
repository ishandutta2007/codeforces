#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int ans = (N & 1 ? 1 : 2);
		for(int i = (N + 1) / 2 - 1; i >= 1; i--) {
			if(A[i] == A[(N + 1) / 2]) ans += 2;
			else break;
		}
		printf("%d\n", ans);
	}
	return 0;
}