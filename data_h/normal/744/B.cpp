#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1111;
const int LOG = 10;
const int INF = 1e9 + 7;

int n;
int ans[LOG + 1][2][N];

int main() {
	scanf("%d", &n);
	int m = 0;
	while ((1 << m) < n) m++;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2; j++) {
			vector<int> query;
			for (int k = 0; k < n; k++) {
				if ((k >> i & 1) == j) {
					query.push_back(k);
				}
			}
			printf("%d\n", (int)query.size());
			for (int t = 0; t < query.size(); t++) {
				printf("%d%c", query[t] + 1, t + 1 == query.size() ? '\n' : ' ');
			}
			fflush(stdout);
			for (int t = 0; t < n; t++) {
				scanf("%d", &ans[i][j][t]);
			}
		}
	}
	printf("-1\n");
	for (int i = 0; i < n; i++) {
		int a = INF;
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 2; k++) {
				if ((i >> j & 1) != k) {
					a = min(a, ans[j][k][i]);
				}
			}
		}
		printf("%d%c", a, i + 1 == n ? '\n' : ' ');
	}
	fflush(stdout);
	return 0;
}