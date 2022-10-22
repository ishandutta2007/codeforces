#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+9, BASE = 31, INF = 1e9, ED = 1e3+1;
#define all(x) (x).begin(),(x).end()
char grid[1005][1005];
bool bad[1005][1005];
char fin[1005][1005];
int main() {
	int n,m;
	scanf ("%d %d",&n,&m);
	for (int i = 1; i <= n; i++) {
		scanf ("%s",grid[i]+1);
		for (int j = 1; j <= m; j++) fin[i][j] = '.';
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (grid[i][j] == '.'){
			for (int gol = 0; gol >= -2; gol--) {
				for (int gou = 0; gou >= -2; gou--) {
					if (gou == -1 && gol == -1) continue;
					int ni = i+gou, nj = j+gol;
					if (ni >= 1 && nj >= 1) bad[ni][nj] = 1;
				}
			}
		}
	for (int i = 1; i <= n-2; i++)
	 	for (int j = 1; j <= m-2; j++)
			if (!bad[i][j]) {
				fin[i][j] = fin[i][j+1] = fin[i][j+2] = fin[i+1][j] = fin[i+1][j+2] = fin[i+2][j] = fin[i+2][j+1] = fin[i+2][j+2] = '#';
			}
	for (int i = 1; i <= n; i++)
		for (int j =1; j <= m; j++)
			if (fin[i][j] != grid[i][j])
				return !printf ("NO\n");
	printf ("YES\n");
    return 0;
}