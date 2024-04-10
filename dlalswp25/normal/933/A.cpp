#include <stdio.h>
#include <algorithm>

using namespace std;

int fw[2005][2005][3];
int rev[2005][2005][3];
int A[2005];
int two[2005];

int main() {
	int N; scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	for(int i = N - 1; i >= 0; i--) {
		two[i] = two[i + 1];
		if(A[i] == 2) two[i]++;
	}
	for(int i = 0; i < N; i++) {
		if(A[i] == 1) fw[i][i][1] = 1;
		else fw[i][i][2] = 1;
		for(int j = i + 1; j < N; j++) {
			if(A[j] == 1) {
				fw[i][j][1] = fw[i][j - 1][1] + 1;
				fw[i][j][2] = fw[i][j - 1][2];
			}
			else {
				fw[i][j][1] = fw[i][j - 1][1];
				fw[i][j][2] = max(fw[i][j - 1][1], fw[i][j - 1][2]) + 1;
			}
		}
	}
	for(int i = N - 1; i >= 0; i--) {
		if(A[i] == 1) rev[i][i][1] = 1;
		else rev[i][i][2] = 1;
		for(int j = i - 1; j >= 0; j--) {
			if(A[j] == 1) {
				rev[i][j][1] = rev[i][j + 1][1] + 1;
				rev[i][j][2] = rev[i][j + 1][2];
			}
			else {
				rev[i][j][1] = rev[i][j + 1][1];
				rev[i][j][2] = max(rev[i][j + 1][1], rev[i][j + 1][2]) + 1;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i; j < N; j++) {
			if(i) {
				ans = max(ans, fw[0][i - 1][1] + rev[j][i][1] + fw[j + 1][N - 1][1]);
				ans = max(ans, fw[0][i - 1][1] + rev[j][i][1] + fw[j + 1][N - 1][2]);
				ans = max(ans, fw[0][i - 1][1] + rev[j][i][2] + two[j + 1]);
				ans = max(ans, fw[0][i - 1][2] + two[i]);
			}
			else {
				ans = max(ans, rev[j][i][1] + fw[j + 1][N - 1][1]);
				ans = max(ans, rev[j][i][1] + fw[j + 1][N - 1][2]);
				ans = max(ans, rev[j][i][2] + two[j + 1]);
			}
		}
	}
	printf("%d", ans);
	return 0;
}