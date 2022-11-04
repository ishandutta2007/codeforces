#include<cstdio>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int mo = 1e9 + 7;

int n, a[101], f[10001][101], c[101][101];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 0, n) {
		c[i][0] = 1;
		fo(j, 1, i) c[i][j] = (c[i - 1][j - 1] + c[i  -1][j]) % mo;
	}
	fo(i, 1, n) scanf("%d", &a[i]);
	f[0][0] = 1;
	int s = 0;
	fo(i, 1, n) {
		fd(j, s, 0) fo(k, 0, i - 1)
			f[j + a[i]][k + 1] = (f[j + a[i]][k + 1] + f[j][k]) % mo;
		s += a[i];
	}
	int ans = 0;
	sort(a + 1, a + n + 1);
	int la = 1;
	int co = 0; 
	fo(i, 2, n + 1) if(i > n || a[i] != a[i - 1]) co ++;
	fo(i, 2, n + 1) if(i > n || a[i] != a[i - 1]) {
		int g = i - la;
		fo(j, 1, g) if(f[a[i - 1] * j][j] == c[g][j]) ans = ans > j ? ans : j;
		if(co == 2 && f[a[i - 1] * g][g] == 1) ans = n;
		la = i;
	}
	printf("%d", ans);
}