#include <bits/stdc++.h>

using namespace std;

int ans[105][105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N & 1) {
			for(int i = 1; i <= N; i++) {
				for(int j = i + 1; j <= N; j++) {
					if(j <= i + N / 2) ans[i][j] = 1;
					else ans[i][j] = -1;
				}
			}
		}
		else {
			for(int i = 1; i <= N; i++) {
				for(int j = i + 1; j <= N; j++) {
					if(j < i + N / 2) ans[i][j] = 1;
					else if(j == i + N / 2) ans[i][j] = 0;
					else ans[i][j] = -1;
				}
			}
		}
		for(int i = 1; i <= N; i++) for(int j = i + 1; j <= N; j++) printf("%d ", ans[i][j]);
		puts("");
	}
	return 0;
}