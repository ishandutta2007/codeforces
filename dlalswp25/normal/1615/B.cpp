#include <bits/stdc++.h>

using namespace std;

const int MX = 200000;

int A[202020][20];

int main() {
	for(int i = 1; i <= MX; i++) {
		for(int j = 0; j < 20; j++) {
			A[i][j] = A[i - 1][j];
			if(i & 1 << j) A[i][j]++;
		}
	}
	int tc; scanf("%d", &tc);
	while(tc--) {
		int l, r; scanf("%d%d", &l, &r);
		int ans = 0;
		for(int i = 0; i < 20; i++) {
			ans = max(ans, A[r][i] - A[l - 1][i]);
		}
		printf("%d\n", r - l + 1 - ans);
	}
	return 0;
}