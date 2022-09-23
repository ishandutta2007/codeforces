#include <bits/stdc++.h>

using namespace std;

char A[202020];
int L[4][202020];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", A + 1);
		int N = strlen(A + 1);
		for(int i = 1; i <= 3; i++) {
			for(int j = 1; j <= N; j++) {
				if(A[j] == i + '0') L[i][j] = j;
				else L[i][j] = L[i][j - 1];
			}
		}

		int ans = N + 1;
		for(int i = 1; i <= N; i++) {
			int t = i;
			for(int j = 1; j <= 3; j++) t = min(t, L[j][i]);
			if(t) ans = min(ans, i - t + 1);
		}

		if(ans > N) puts("0");
		else printf("%d\n", ans);
	}
	return 0;
}