#include<cstdio>
#include<bitset>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 1e5 + 5;

int n, a[N], d[N], b[21][N], a2[25], ans[N];

void dg(int x) {
	if(x > 20) {
		if(d[0] < ans[0])
			fo(i, 0, d[0]) ans[i] = d[i];
		return;
	}
	int pos = 0;
	fo(i, 1, n) pos |= a[i] & a2[x];
	if(!pos) dg(x + 1); else {
		int n0 = n;
		fo(i, 1, n0) b[x][i] = a[i];
		d[++ d[0]] = a2[x];
		fo(i, 1, n0) if(b[x][i] & a2[x])
			a[i] = b[x][i] - a2[x]; else a[i] = b[x][i];
		sort(a + 1, a + n0 + 1);
		
		n = 0;
		fo(i, 1, n0) if(i == 1 || a[i] != a[i - 1])
			a[++ n] = a[i];
			
		dg(x + 1);
		d[d[0]] = -a2[x];
		fo(i, 1, n0) if(b[x][i] & a2[x])
			a[i] = b[x][i] + a2[x]; else a[i] = b[x][i];
			
		n = 0;
		fo(i, 1, n0) if(i == 1 || a[i] != a[i - 1])
			a[++ n] = a[i];
			
		dg(x + 1);
		d[0] --;
	}
}

int main() {
//	freopen("e.in", "r", stdin);
	a2[0] = 1; fo(i, 1, 20) a2[i] = a2[i - 1] * 2;
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &a[i]);
	ans[0] = 30; dg(0);
	printf("%d\n", ans[0]);
	fo(i, 1, ans[0]) printf("%d ", ans[i]);
}