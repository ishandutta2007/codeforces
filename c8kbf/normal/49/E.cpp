#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 50+8;

_ n[2], k, b[maxn][maxn];
char a[2][maxn];
struct pr {
	char a, b, c;
} c[maxn];
bool dp[2][maxn][maxn][maxn];

int main() {
	
	scanf(" %s %s%lld", a[0]+1, a[1]+1, &k);
	for(_ i = 0; i <= 1; ++i) n[i] = strlen(a[i]+1);
	for(_ i = 1; i <= k; ++i) scanf(" %c->%c%c", &c[i].a, &c[i].b, &c[i].c);
	for(_ i = 0; i <= 1; ++i) for(_ j = 1; j <= n[i]; ++j) dp[i][j][j][a[i][j]-'a'] = true;
	for(_ i = 0; i <= 1; ++i) for(_ l = 2; l <= n[i]; ++l) for(_ x = 1; ; ++x) {
		_ y = x+l-1;
		if(y > n[i]) break;
		for(_ z = x; z <= y-1; ++z) for(_ p = 1; p <= k; ++p) dp[i][x][y][c[p].a-'a'] |= dp[i][x][z][c[p].b-'a'] && dp[i][z+1][y][c[p].c-'a'];
	}
	memset(b, 4, sizeof b);
	b[0][0] = 0;
	for(_ i = 1; i <= n[0]; ++i) for(_ j = 1; j <= n[1]; ++j) for(_ k = 0; k < i; ++k) for(_ l = 0; l < j; ++l) for(_ c = 0; c <= 25; ++c) if(dp[0][k+1][i][c] && dp[1][l+1][j][c]) b[i][j] = min(b[i][j], b[k][l]+1);
	if(b[n[0]][n[1]] > 1E11) puts("-1");
	else printf("%lld\n", b[n[0]][n[1]]);
		
	return 0;
}