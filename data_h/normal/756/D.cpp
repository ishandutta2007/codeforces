#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 5e3 + 7;
const int C = 26;
const int MOD = 1e9 + 7;

int n, a[N], f[N];
int nxt[C], delta[C];
char s[N];

__inline int fix(int x) {
	if (x >= MOD) return x - MOD;
	if (x < 0) return x + MOD;
	return x;
}

__inline void add(int &a, int b) {
	if ((a += b) >= MOD) a -= MOD;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	f[1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int c = 0; c < C; c++) {
			nxt[c] = -1;
			delta[c] = 0;
		}
		int tot = 0;
		for (int j = n; j >= 1; j--) {
			int c = s[j] - 'a';
			if (nxt[c] != -1) {
				add(f[nxt[c]], fix(tot + delta[c]));
			}
			nxt[c] = j;
			delta[c] = fix(MOD - tot);
			add(tot, f[j]);
			f[j] = 0;
		}
		for (int c = 0; c < C; c++) {
			if (nxt[c] != -1) {
				add(f[nxt[c]], fix(tot + delta[c]));
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		add(ans, f[i]);
	}
	printf("%d\n", ans);
	return 0;
}