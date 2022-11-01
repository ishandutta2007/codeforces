#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1111;

int n, m, q;
int le[N][N], ri[N][N], up[N][N], dw[N][N];
int mat[N][N];

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			scanf("%d", &mat[i][j]);
		} 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if (mat[i][j] != 0) {
				up[i][j] = up[i - 1][j] + 1;
				le[i][j] = le[i][j - 1] + 1;
			}
		}
		for(int j = m; j >= 1; j--) {
			if (mat[i][j] != 0) {
				ri[i][j] = ri[i][j + 1] + 1;
			}
		}
	}
	for(int i = n; i >= 1; i--) {
		for(int j = 1; j <= m; j++) {
			if (mat[i][j]) {
				dw[i][j] = dw[i + 1][j] + 1;
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		int op, x, y;
		scanf("%d %d %d", &op, &x, &y);
		if (op == 1) {
			mat[x][y] ^= 1;
			for(int j = 1; j <= m; j++) {
				le[x][j] = (mat[x][j] ? le[x][j - 1] + 1 : 0);
			}
			for(int j = m; j >= 1; j--) {
				ri[x][j] = (mat[x][j] ? ri[x][j + 1] + 1 : 0);
			}
			for(int j = 1; j <= n; j++) {
				up[j][y] = (mat[j][y] ? up[j - 1][y] + 1 : 0);
			}
			for(int j = n; j >= 1; j--) {
				dw[j][y] = (mat[j][y] ? dw[j + 1][y] + 1 : 0);
			}
		} else {
			int ans = 0;
			int l, r, mv; 
			for(l = r = y, mv = up[x][y]; l >= 1; l--) {
				mv = min(mv, up[x][l]);
				while(r <= m && up[x][r] >= mv)
					r++;
				ans = max(ans, (r - l) * mv);
			}
			for(l = r = y, mv = up[x][y]; r <= m; r++) {
				mv = min(mv, up[x][r]);
				while(l >= 1 && up[x][l] >= mv)
					l--;
				ans = max(ans, (r - l) * mv);
			}
			
			for(l = r = y, mv = dw[x][y]; l >= 1; l--) {
				mv = min(mv, dw[x][l]);
				while(r <= m && dw[x][r] >= mv)
					r++;
				ans = max(ans, (r - l) * mv);
			}
			for(l = r = y, mv = dw[x][y]; r <= m; r++) {
				mv = min(mv, dw[x][r]);
				while(l >= 1 && dw[x][l] >= mv)
					l--;
				ans = max(ans, (r - l) * mv);
			}
			
			for(l = r = x, mv = le[x][y]; l >= 1; l--) {
				mv = min(mv, le[l][y]);
				while(r <= n && le[r][y] >= mv)
					r++;
				ans = max(ans, (r - l) * mv);
			}
			for(l = r = x, mv = le[x][y]; r <= n; r++) {
				mv = min(mv, le[r][y]);
				while(l >= 1 && le[l][y] >= mv)
					l--;
				ans = max(ans, (r - l) * mv);
			}
			
			for(l = r = x, mv = ri[x][y]; l >= 1; l--) {
				mv = min(mv, ri[l][y]);
				while(r <= n && ri[r][y] >= mv)
					r++;
				ans = max(ans, (r - l) * mv);
			}
			for(l = r = x, mv = ri[x][y]; r <= n; r++) {
				mv = min(mv, ri[r][y]);
				while(l >= 1 && ri[l][y] >= mv)
					l--;
				ans = max(ans, (r - l) * mv);
			}
			printf("%d\n", ans);
		}
		
	}
	return 0;
}