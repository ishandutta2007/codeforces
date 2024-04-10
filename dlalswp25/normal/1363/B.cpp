#include <bits/stdc++.h>

using namespace std;

char S[1010];
int L[1010][2];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", S + 1);
		int N = strlen(S + 1);

		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < 2; j++) {
				if(S[i] == j + '0') L[i][j] = L[i - 1][j] + 1;
				else L[i][j] = L[i - 1][j];
			}
		}

		int ans = 1010101010;
		int z = 0, o = 0;
		for(int i = N; i >= 0; i--) {
			ans = min(ans, L[i][1] + z);
			ans = min(ans, L[i][0] + o);

			if(S[i] == '0') z++;
			else o++;
		}
		printf("%d\n", ans);
	}
	return 0;
}