#include <bits/stdc++.h>

using namespace std;

int N;
int ans[1010][1010];

int main() {
	scanf("%d", &N);
	int c = 0;

	for(int i = 0; i < N; i += 4) {
		for(int j = 0; j < N; j += 4) {
			for(int k = 0; k < 4; k++) {
				for(int l = 0; l < 4; l++) {
					ans[i + k][j + l] = c;
					c++;
				}
			}
		}
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			printf("%d ", ans[i][j]);
		}
		puts("");
	}
	return 0;
}