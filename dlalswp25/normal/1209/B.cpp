#include <bits/stdc++.h>

using namespace std;

int A[101];
int B[101];
int N;
char X[1010];

int main() {
	scanf("%d", &N);
	scanf("%s", X + 1);
	for(int i = 1; i <= N; i++) scanf("%d%d", &A[i], &B[i]);

	int ans = 0;
	for(int i = 1; i <= 1010; i++) {
		int cnt = 0;
		for(int j = 1; j <= N; j++) {
			if(X[j] == '1') cnt++;
		}
		ans = max(ans, cnt);

		for(int j = 1; j <= N; j++) {
			if(i >= B[j] && (i - B[j]) % A[j] == 0) {
				if(X[j] == '1') X[j] = '0';
				else X[j] = '1';
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}