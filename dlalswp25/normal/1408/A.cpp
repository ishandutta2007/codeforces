#include <bits/stdc++.h>

using namespace std;

int N;
int A[3][105];
int ans[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int j = 0; j < 3; j++) for(int i = 1; i <= N; i++) scanf("%d", &A[j][i]);
		ans[1] = A[0][1];
		for(int i = 2; i <= N; i++) {
			for(int j = 0; j < 3; j++) {
				if(ans[i - 1] == A[j][i] || (i == N && ans[1] == A[j][i])) continue;
				ans[i] = A[j][i]; break;
			}
		}
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}