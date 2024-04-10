#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;			
	
const int nax = 1e5 + 111;

int n;
int x[nax], y[nax];
int q;
int dx, dy;	

LL wek(int x, int y, int xx, int yy) {
	return (LL) x * yy - (LL) y * xx;
}

int nas(int x) {
	return (x + 1) % n;
}

bool good(int p, int q) {
	int x1 = x[q] - x[p];
	int y1 = y[q] - y[p];
	int x2 = dx - x[p];
	int y2 = dy - y[p];
	return wek(x1, y1, x2, y2) < 0;
}
	

int main() {
	scanf ("%d", &n);
	rep(i, 0, n - 1) scanf ("%d%d", x + i, y + i);
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d%d", &dx, &dy);
		
		int dod = 0;
		int uje = 0;
		
		rep(i, 0, n - 1) {
			int e = nas(i);
			LL z = wek(x[e] - x[i], y[e] - y[i], dx - x[i], dy - y[i]);
			if (z > 0) dod++;
			else uje++;
		}
		
		if (dod && uje) {
			printf("0\n");
			continue;
		}
		
		int j = 0;
		LL ans = (LL) n * (n - 1) * (n - 2) / 6;
		rep(i, 0, n - 1) {
			while (good(i, nas(j))) j = nas(j);
			int k = (i < j ? j - i : n + j - i);
			ans -= (LL) k * (k - 1) / 2;
		}
		printf ("%lld\n", ans);
	}
			
		
	
	return 0;
}