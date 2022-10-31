#include <bits/stdc++.h>
using namespace std;

int d[220][220] = {};
const int inf = 1000000000;
int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < 220; ++i) for(int j = 0; j < 220; ++j) d[i][j] = inf;
	d[0][0] = 0;
	for(int t = 1; t <= n; ++t) {
		int x, y; scanf("%d%d", &x, &y);		
		for(int i = 0; i < 220; ++i) {
			d[t][i] = min(d[t][i], d[t-1][i] + y);
			if(i >= x) d[t][i] = min(d[t][i], d[t-1][i - x]);
		}
		// for(int i = 0; i < 5; ++i) printf("%d ", d[t][i]); puts("");
	}
	for(int i = 1; i < 220; ++i) {
		// printf("%d %d\n", i, d[n][i]);
		if(i >= d[n][i]) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}