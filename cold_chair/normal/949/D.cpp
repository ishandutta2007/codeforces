#include<cstdio>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define abs(a) ((a) > 0 ? (a) : -(a))
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

const int N = 1e5 + 5;

int n, d, b, a[N], ans;

int pd(int m) {
	int l = m + 1, r = b;
	fo(i, 1, n) {
		int x = a[i];
		while(l <= n - m) {
			if(!x) break;
			if(abs(i - l) <= (ll) d * min(l, n - l + 1)) {
				if(x >= r) {
					x -= r;
					l ++; r = b;
				} else {
					r -= x; break;
				}
			} else break;
		}
	}
	return l > n - m;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %d", &n, &d, &b);
	fo(i, 1, n) scanf("%d", &a[i]);
	for(int l = 0, r = n / 2; l <= r; ) {
		int m = l + r >> 1;
		if(pd(m)) ans = m, r = m - 1; else l = m + 1;
	}
	printf("%d", ans);
}