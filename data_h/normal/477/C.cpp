#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 2222;
const int INF = 1111111;

char s[N], p[N];
int n, m;
int cost[N][N];
int f[N][N];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%s", p + 1);
	m = strlen(p + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++) {
			cost[i][j] = INF;
		}
	for(int i = 1; i <= n + 1; i++) {
		cost[i][m + 1] = 0;
	}
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= 1; j--) {
			cost[i][j] = min(cost[i][j], cost[i + 1][j] + 1);
			if (s[i] == p[j]) {
				cost[i][j] = min(cost[i][j], cost[i + 1][j + 1]);
			}
		}
	for(int i = 0; i <= n + 1; i++)
		for(int j = 0; j <= n + 1; j++) {
			f[i][j] = -INF;
		}
	f[1][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= n; j++) {
			f[i + 1][j] = max(f[i + 1][j], f[i][j]);
			f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j]); 
			if (cost[i][1] != INF && i + cost[i][1] + m <= n + 1 && j + cost[i][1] <= n) {
				f[i + cost[i][1] + m][j + cost[i][1]] = max(f[i + cost[i][1] + m][j + cost[i][1]]
					, f[i][j] + 1);
			}
		}
	for(int i = 0; i <= n; i++) {
		printf("%d%c", f[n + 1][i], i == n ? '\n' : ' ');
	} 
	return 0;
}