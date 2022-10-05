#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
#define cmax(a,b) (b>a?a=b:0)
using namespace std;
typedef long long LL;

const int maxn = 20;
int f[1<<16][125], r[maxn], b[maxn], c[maxn];
int n, R, B, ALL, ans = 1e9; string s;

int main() {
	cin >> n;
	rep (i, 1, n) {
		cin >> s >> r[i] >> b[i];
		c[i] = (s == "B");
		R += r[i]; B += b[i];
	}
	memset(f, -1, sizeof f);
	ALL = (1 << n) - 1; f[0][0] = 0;
	rep (i, 0, ALL - 1) rep (j, 0, 120) if (f[i][j] != -1) {
		int cr = 0, cb = 0;
		rep (k, 1, n)
			if (i >> (k - 1) & 1) 
				if (c[k]) cb++;
				else cr++;
		rep (k, 1, n)
			if (!(i >> (k - 1) & 1))
				cmax(f[i|1<<(k-1)][j+min(b[k], cb)], f[i][j] + min(r[k], cr));
	}
	rep (i, 0, 120) if (f[ALL][i] != -1) 
		ans = min(ans, max(B - i, R - f[ALL][i]));
	printf("%d\n", ans + n);
	return 0;
}