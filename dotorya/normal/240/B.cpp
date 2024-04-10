#include <stdio.h>
int sum[205];
int d[205];
int ans[205][40050][2];
int min(int a, int b) {
	if(a<b) return a;
	else return b;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, A, B, i, j;
	scanf("%d", &N);
	scanf("%d %d", &A, &B);
	for(i = 1; i <= N; i++) {
		scanf("%d", &d[i]);
		sum[i] = sum[i-1]+d[i];
	}
	for(i = 1; i <= N; i++) for(j = 0; j <= sum[N]; j++) ans[i][j][0] = ans[i][j][1] = 999999999;
	ans[1][0][0] = 0, ans[1][d[1]][1] = 0;
	for(i = 2; i <= N; i++) {
		for(j = 0; j <= sum[i]; j++) ans[i][j][0] = min(ans[i-1][j][0], ans[i-1][j][1]+min(d[i-1], d[i]));
		for(j = d[i]; j <= sum[i]; j++) ans[i][j][1] = min(ans[i-1][j-d[i]][0]+min(d[i-1], d[i]), ans[i-1][j-d[i]][1]);
	}
	int Ans = 999999999;
	for(i = sum[N]-A; i <= B; i++) {
		Ans = min(ans[N][i][0], Ans);
		Ans = min(ans[N][i][1], Ans);
	}
	if(Ans == 999999999) printf("-1");
	else printf("%d\n", Ans);
	return 0;
}