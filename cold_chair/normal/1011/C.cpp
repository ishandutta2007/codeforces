#include<cstdio>
#define db long double
#define fo(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int N = 1e3 + 5;

int n, m, a[N], b[N];

int pd(db p) {
	p -= (m + p) / a[1];
	if(p < 0) return 0;
	fo(i, 2, n) { 
		p -= (m + p) / b[i];
		if(p < 0) return 0;
		p -= (m + p) / a[i];
		if(p < 0) return 0;
	}
	p -= (m + p) / b[1];
	return p >= 0;
}


int main() {
	scanf("%d %d", &n, &m);
	fo(i, 1, n) scanf("%d", &a[i]);
	fo(i, 1, n)	scanf("%d", &b[i]);
	db ans = -1;
	for(db l = 0, r = 1e9 + 1; l <= r; ) {
		db mi = (l + r) / 2;
		if(pd(mi)) ans = mi, r = mi - (1e-8); else l = mi + (1e-8);
	}
	if(ans == -1) printf("-1");else {
		double s = ans;
		printf("%.6lf", s);
	}
}