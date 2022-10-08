#include <stdio.h>
char s[15];
int chk[105];
int movie_chk[105][3]; // 0:  , 1:   , 2: 
int movie_ans[105][2]; // 0:min, 1:max
int ans[105];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int	M, K, N, i, t, t2, j, tot_min=999999, tot_max=0;
	scanf("%d %d", &M, &K);
	for(i = 1; i <= K; i++) {
		scanf("%d", &t);
		chk[t] = 1;
	}
	scanf("%d", &N);
	for(i = 1; i <= N; i++) {
		scanf("%s", s);
		scanf("%d", &t2);
		for(j = 1; j <= t2; j++) {
			scanf("%d", &t);
			if(chk[t] == 1) movie_chk[i][0]++;
			else if(t == 0) movie_chk[i][2]++;
			else movie_chk[i][1]++;
		}
		if(movie_chk[i][2] > M-K-movie_chk[i][1]) movie_ans[i][0] = movie_chk[i][0]+movie_chk[i][2]-M+K+movie_chk[i][1];
		else movie_ans[i][0] = movie_chk[i][0];
		if(movie_chk[i][2] > K-movie_chk[i][0]) movie_ans[i][1] = K;
		else movie_ans[i][1] = movie_chk[i][0]+movie_chk[i][2];
	}
	for(i = 1; i <= N; i++) {
		ans[i] = 2;
		for(j = 1; j <= N; j++) {
			if(i == j) continue;
			if(movie_ans[i][0] < movie_ans[j][1]) break;
		}
		if(j == N+1) ans[i] = 0;
		for(j = 1; j <= N; j++) {
			if(i == j) continue;
			if(movie_ans[i][1] < movie_ans[j][0]) break;
		}
		if(j != N+1) ans[i] = 1;
	}
	for(i = 1; i <= N; i++) printf("%d\n", ans[i]);
	return 0;
}