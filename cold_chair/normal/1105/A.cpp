#include<cstdio>
#include<algorithm>
#define pp printf
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define abs(a) ((a) > 0 ? (a) : -(a))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int n, a[1005], x, y, xx;

int pd(int x) {
	if(x <= 0) return 1e9;
	int s = 0;
	fo(i, 1, n) s += min(abs(x - a[i]), min(abs(x + 1 - a[i]), abs(x - 1 - a[i])));
	return s;
}

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	fo(i, 1, n) scanf("%d", &a[i]);
	x = 1; y = pd(1);
	fo(i, 1, 100) if(pd(i) < y) x = i, y = pd(x);
	pp("%d %d\n", x, y);
}