#include <bits/stdc++.h>

using namespace std;

int N;
int A[55];
bool chk[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= 100; i++) chk[i] = false;
		for(int i = 1; i <= N; i++) {
			for(int j = i + 1; j <= N; j++) {
				chk[A[j] - A[i]] = true;
			}
		}
		int ans = 0;
		for(int i = 1; i <= 100; i++) ans += chk[i];
		printf("%d\n", ans);
	}
	return 0;
}