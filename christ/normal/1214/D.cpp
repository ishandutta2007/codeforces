#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 3e6 + 5, MOD = 1e9 + 7;
int cnt[MN];
int main () {
	int n,m;
	scanf ("%d %d",&n,&m);
	vector<vector<char>> grid(n+1,vector<char>(m+1));
	vector<vector<bool>> poss(n+1,vector<bool>(m+1)), poss2(n+2,vector<bool>(m+2));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf (" %c",&grid[i][j]);
	poss[1][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) if (grid[i][j]=='.')
			poss[i][j] = poss[i][j] || poss[i-1][j] || poss[i][j-1];
	poss2[n][m] = 1;
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--) if (grid[i][j]=='.') {
			poss2[i][j] = poss2[i][j] || poss2[i+1][j] || poss2[i][j+1];
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cnt[i+j-2] += poss[i][j] && poss2[i][j];
		}
	}
	if (!poss[n][m]) return !printf ("0\n");
	for (int i = 1; i < n + m - 2; i++) {
		if (cnt[i] == 1) return !printf ("1\n");
	}
	printf ("2\n");
	return 0;
}