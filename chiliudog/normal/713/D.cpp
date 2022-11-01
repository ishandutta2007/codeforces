#include <iostream>
#include <cstdio>
#include <algorithm>
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define dep(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 1010;
short a[N][N], f[N][N], mx[10][10][N][N], bin[N];
int qry(int x1, int x2, int y1, int y2) {
	int lx = x2 - x1 + 1, ly = y2 - y1 + 1;
	int bx = bin[lx], by = bin[ly];
	return max(
		max(mx[bx][by][x1][y1], mx[bx][by][x2 - (1 << bx) + 1][y2 - (1 << by) + 1]),
		max(mx[bx][by][x1][y2 - (1 << by) + 1], mx[bx][by][x2 - (1 << bx) + 1][y1])
	);
}
int main() {
	int n, m; scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m) scanf("%hd",&a[i][j]);
	rep(i,1,n) rep(j,1,m) if (a[i][j]) f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
	rep(i,1,n) rep(j,1,m) mx[0][0][i][j] = f[i][j];
	rep(t1,0,9) {
		if (t1) {
			rep(i,1,n) rep(j,1,m) if (i + (1 << t1) - 1 <= n)
				mx[t1][0][i][j] = max(mx[t1 - 1][0][i][j], mx[t1 - 1][0][i + (1 << (t1 - 1))][j]);
		}
		rep(t2,1,9) rep(i,1,n) rep(j,1,m) if (j + (1 << t2) - 1 <= m)
			mx[t1][t2][i][j] = max(mx[t1][t2 - 1][i][j], mx[t1][t2 - 1][i][j + (1 << (t2 - 1))]);
	}
	rep(j,0,9) rep(i,(1<<j),(1<<(j+1))) if (i < N) bin[i] = j;

	int q; scanf("%d",&q);
	rep(i,1,q) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int L = min(x2 - x1 + 1, y2 - y1 + 1), ans = 0;
		dep(j,9,0) if (ans + (1 << j) <= L && qry(x1 + ans + (1 << j) - 1, x2, y1 + ans + (1 << j) - 1, y2) >= ans + (1 << j))
			ans += 1 << j;
		printf("%d\n",ans);
	}
	return 0;
}