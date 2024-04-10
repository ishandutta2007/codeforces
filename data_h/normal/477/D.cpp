#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 5000 + 10;
const int MOD = 1e9 + 7;
const int INF = 111111111;

int lcp[N][N], f[N][N], sum[N][N], g[N][N], minV[N][N];

char s[N];
int n;

__inline void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

__inline void update(int &a, int b) {
	if (b < a) {
		a = b;
	}
}


// or equal
int lesss(int a, int b, int c) {
	a = a - c + 1;
	if (a < 1) {
		return false;
	}
	
	b = b - c + 1;
	int d = lcp[a][b];
	if (d >= c) {
		return true;
	} else {
		return s[a + d] < s[b + d];
	}
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = n; i >= 1; i--)
		for(int j = n; j >= 1; j--) {
			if (s[i] == s[j]) {
				lcp[i][j] = lcp[i + 1][j + 1] + 1;
			} else {
				lcp[i][j] = 0;
			}
		}
	f[0][0] = 1;
	for(int i = 0; i <= n; i++) {
		sum[0][i] = 1;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			if (s[i - j + 1] != '0') {
				add(f[i][j], sum[i - j][j - 1]);
				if (lesss(i - j, i, j)) {
					add(f[i][j], f[i - j][j]);
				}
			} else {
				f[i][j] = 0;
			}
			sum[i][j] = sum[i][j - 1];
			add(sum[i][j], f[i][j]);
		}
		for(int j = i + 1; j <= n; j++) {
			f[i][j] = 0;
			sum[i][j] = sum[i][j - 1];
		}
	}
	
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++) {
			g[i][j] = INF;
		}
	
	for(int i = 1; i <= n; i++) {
		g[0][i] = INF;
		minV[0][i] = 0;
	}
	g[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		minV[i][0] = INF;
		for(int j = 1; j <= i; j++) {
			if (s[i - j + 1] != '0') {
				update(g[i][j], minV[i - j][j - 1] + 1);
				if (lesss(i - j, i, j)) {
					update(g[i][j], g[i - j][j] + 1);
				}
			} else {
				g[i][j] = INF;
			}
			minV[i][j] = minV[i][j - 1];
			update(minV[i][j], g[i][j]);
		}
		for(int j = i + 1; j <= n; j++) {
			g[i][j] = INF;
			minV[i][j] = minV[i][j - 1];
		}
	}
	
	cout << sum[n][n] << endl;
	int answer = -1;
	for(int i = 1; i <= n && i <= 20; i++) {
		if (g[n][i] == INF) {
			continue;
		}
		int cur = 0;
		for(int j = 1; j <= i; j++) {
			cur = cur * 2 + (s[n - i + j] == '1');
		}
		cur += g[n][i];
		if (answer == -1 || answer > cur) {
			answer = cur;
		}
	}
	
	if (answer == -1) {
		for(int i = 1; i <= n; i++) {
			if (g[n][i] != INF) {
				answer = g[n][i];
				int cur = 0;
				for(int j = 1; j <= i; j++) {
					cur = cur * 2 + (s[n - i + j] == '1');
					cur %= MOD;
				}
				answer += cur;
				answer %= MOD;
				break;
			}
		}
	}
	
	cout << answer % MOD << endl;
	return 0;
}