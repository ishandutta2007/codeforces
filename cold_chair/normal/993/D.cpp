#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define db double
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

const int N = 1e5 + 5;

int n;
struct node {
	int x, y;
} a[N];

int cmp(node a, node b) {return a.x < b.x;}

db f[55][55][55], ans;

int pd(db ans) {
	memset(f, 127, sizeof f);
	f[0][0][0] = 0;
	fo(i, 1, n) {
		if(a[i].x == a[i - 1].x) {
			fo(j, 0, i - 1) {
				int nj = j ? j - 1 : j;
				fo(k, 0, i - 1) {
					if(f[i - 1][j][k] + a[i].x - ans * a[i].y < f[i][nj][k])
						f[i][nj][k] = f[i - 1][j][k] + a[i].x - ans * a[i].y;
					if(f[i - 1][j][k] < f[i][j][k + 1]) f[i][j][k + 1] = f[i - 1][j][k];
				}
			}
		} else {
			fo(j, 0, i - 1) fo(k, 0, i - 1)
				f[i - 1][j + k][0] = min(f[i - 1][j + k][0], f[i - 1][j][k]);
			fo(j, 0, i - 1) {
				int nj = j ? j - 1 : j;
				if(f[i - 1][j][0] + a[i].x - ans * a[i].y < f[i][nj][0])
					f[i][nj][0] = f[i - 1][j][0] + a[i].x - ans * a[i].y;
				if(f[i - 1][j][0] < f[i][j][1]) f[i][j][1] = f[i - 1][j][0];
			}
		}
	}
	return f[n][0][0] < 0;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &a[i].x);
	fo(i, 1, n) scanf("%d", &a[i].y);
	sort(a + 1, a + n + 1, cmp);
	for(db l = 0, r = 1e8 + 1; r - l > 1e-5; ) {
		db m = (l + r) / 2;
		if(pd(m)) ans = m, r = m; else l = m;
	}
	ll as = ceil((ans - 1e-5) * 1000);
	printf("%I64d\n", as);
}