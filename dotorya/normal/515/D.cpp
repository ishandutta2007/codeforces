#include <stdio.h>
const int n_mx = 2000 + 50;
const int m_mx = 2000 + 50;
char d[n_mx][m_mx];
int cnt[n_mx][m_mx];
struct data {
	data() {
		data(0,0);
	}
	data(int a, int b) {
		x = a, y = b;
	}
	int x, y;
} Q[n_mx*m_mx], tmp;
int main() {
	int N, M, i, j, t, st = 1, en = 1;
	scanf("%d %d", &N, &M);
	for(i = 1; i <= N; i++) scanf("%s", &d[i][1]);
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= M; j++) {
			if(d[i][j] == '*') {
				cnt[i][j] = -1;
				continue;
			}
			t = 0;
			if(d[i-1][j] == '.') t++;
			if(d[i+1][j] == '.') t++;
			if(d[i][j-1] == '.') t++;
			if(d[i][j+1] == '.') t++;
			cnt[i][j] = t;
		}
	}
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= M; j++) {
			if(cnt[i][j] == 0) break;
			if(cnt[i][j] == 1) Q[en++] = data(i, j);
		}
		if(j != M+1) break;
	}
	if(i != N+1) {
		printf("Not unique");
		return 0;
	}
	while(st < en) {
		tmp = Q[st];
		i = tmp.x, j = tmp.y;
		if(d[i][j] != '.') {
			st++;
			continue;
		}
		if(cnt[i][j] == 0) break;
		if(d[i-1][j] == '.') {
			d[i-1][j] = '^';
			d[i][j] = 'v';
			cnt[i-1][j+1]--;
			cnt[i-1][j-1]--;
			cnt[i-2][j]--;
			if(cnt[i-1][j+1] <= 1) Q[en++] = data(i-1, j+1);
			if(cnt[i-1][j-1] <= 1) Q[en++] = data(i-1, j-1);
			if(cnt[i-2][j] <= 1) Q[en++] = data(i-2, j);
		}
		else if(d[i+1][j] == '.') {
			d[i+1][j] = 'v';
			d[i][j] = '^';
			cnt[i+1][j+1]--;
			cnt[i+1][j-1]--;
			cnt[i+2][j]--;
			if(cnt[i+1][j+1] <= 1) Q[en++] = data(i+1, j+1);
			if(cnt[i+1][j-1] <= 1) Q[en++] = data(i+1, j-1);
			if(cnt[i+2][j] <= 1) Q[en++] = data(i+2, j);
		}
		else if(d[i][j+1] == '.') {
			d[i][j+1] = '>';
			d[i][j] = '<';
			cnt[i][j+2]--;
			cnt[i-1][j+1]--;
			cnt[i+1][j+1]--;
			if(cnt[i-1][j+1] <= 1) Q[en++] = data(i-1, j+1);
			if(cnt[i+1][j+1] <= 1) Q[en++] = data(i+1, j+1);
			if(cnt[i][j+2] <= 1) Q[en++] = data(i, j+2);
		}
		else {
			d[i][j-1] = '<';
			d[i][j] = '>';
			cnt[i][j-2]--;
			cnt[i-1][j-1]--;
			cnt[i+1][j-1]--;
			if(cnt[i-1][j-1] <= 1) Q[en++] = data(i-1, j-1);
			if(cnt[i+1][j-1] <= 1) Q[en++] = data(i+1, j-1);
			if(cnt[i][j-2] <= 1) Q[en++] = data(i, j-2);
		}
		st++;
	}
	if(st < en) {
		printf("Not unique");
		return 0;
	}
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= M; j++) {
			if(d[i][j] == '.') break;
		}
		if(j != M+1) break;
	}
	if(i != N+1) {
		printf("Not unique");
		return 0;
	}
	for(i = 1; i <= N; i++) {
		for(j = 1; j <= M; j++) printf("%c", d[i][j]);
		printf("\n");
	}
	return 0;
}