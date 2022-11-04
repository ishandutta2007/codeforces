#include<cstdio> 
#include<cstring>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int N = 1e5 + 5;

int n, m, a[N], ans, b[N];

int pd(int p) {
	int sum = 0;
	fo(i, 1, n)	sum += b[i] / p;
	return sum >= m;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &m, &n);
	fo(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int n0 = 0;
	fo(i, 1, n) if(i == 1 || a[i] != a[i - 1]) {
		b[++ n0] = 1;
	} else b[n0] ++;
	n = n0;
	for(int l = 1, r = 1e9; l <= r; ) {
		int mi = l + r >> 1;
		if(pd(mi)) {
			l = mi + 1;
			ans = mi;
		} else r = mi - 1;
	}
	printf("%d", ans);
}