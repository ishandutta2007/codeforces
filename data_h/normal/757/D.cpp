#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const int N = 75 + 7;
const int C = 20;
const int M = 1 << 20;
const int MOD = 1e9 + 7;

int f[N][M];
int n, nxt[N];
char s[N];

void add(int &a, int b) {
	if ((a += b) >= MOD) {
		a -= MOD;
	}
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	nxt[n + 1] = n + 1;
	for (int i = n; i >= 1; i--) {
		if (s[i] == '1') {
			nxt[i] = i;
		} else {
			nxt[i] = nxt[i + 1];
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		add(f[i][0], 1);
		for (int mask = 0; mask < (1 << C); mask++) {
			for (int j = 0; j <= C; j++) {
				if (mask >> j & 1) continue;
				if (mask < (1 << j) && mask) add(ans, f[i][mask]);
				break;
			}
			for (int j = nxt[i + 1], cur = 0; j <= n && j <= nxt[i + 1] + 4; j++) {
				cur = (cur << 1) | (s[j] == '1');
				if (cur != 0 && cur <= C) {
					add(f[j][mask | (1 << (cur - 1))], f[i][mask]);
				}
			}
		}
	}
	printf("%d\n", ans);
}