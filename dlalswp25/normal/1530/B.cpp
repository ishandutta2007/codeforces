#include <bits/stdc++.h>

using namespace std;

int H, W;
char A[25][25];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &H, &W);
		for(int i = 1; i <= H + 1; i++) for(int j = 1; j <= W + 1; j++) A[i][j] = '0';
		for(int j = 1; j <= W; j += 2) A[1][j] = '1';
		for(int i = 3; i <= H; i += 2) A[i][W] = '1';
		for(int j = W - 2; j >= 1; j -= 2) A[H][j] = '1';
		for(int i = H - 2; i >= 3; i -= 2) A[i][1] = '1';
		for(int i = 1; i <= H; i++) {
			for(int j = 1; j <= W; j++) {
				printf("%c", A[i][j]);
			}
			puts("");
		}
	}
	return 0;
}