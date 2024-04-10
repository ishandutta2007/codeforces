#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using pil = pair<int,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define mp make_pair
const int MN = 42, BASE = 131, MOD = 1e9+7;
int psa[MN][MN][MN][MN], cnt[MN][MN][MN][MN], xd[MN][MN];char grid[MN][MN]; 
int main () { 
	int n,m,q;
	scanf ("%d %d %d",&n,&m,&q);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf (" %c",&grid[i][j]);
			xd[i][j] = grid[i][j] == '1' ? j : xd[i][j-1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			for (int i2 = i; i2 <= n; i2++) {
				for (int j2 = j; j2 <= m; j2++) {
					int lst = max(j,xd[i2][j2]+1);
					cnt[i][j][i2][j2] += (j2 - lst + 1) + cnt[i][lst][i2-1][j2];
					psa[i][j][i2][j2] = psa[i][j][i2][j2-1] + psa[i][j][i2-1][j2] - psa[i][j][i2-1][j2-1] + cnt[i][j][i2][j2];
				}
			}
		}
	}
	while (q--) {
		int a,b,c,d;
		scanf ("%d %d %d %d",&a,&b,&c,&d);
		printf ("%d\n",psa[a][b][c][d]);
	}
    return 0;
}