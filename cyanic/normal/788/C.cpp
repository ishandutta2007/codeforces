#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 1005;
int f[maxn], g[maxn], A, B, n, x, a, now;
int d[maxn<<1], q[maxn<<1], l, r;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	scanf("%d%d", &x, &n);
	rep (i, 1, n) {
		scanf("%d", &a);
		if (a == x) return puts("1"), 0;
		if (a > x) {
			A = max(A, a - x);
			f[a-x] = 1;
		}
		else {
			B = max(B, x - a);
			g[x-a] = 1;
		}
	}
	memset(d, -1, sizeof d);
	q[r++] = maxn; d[maxn] = 0;
	while (l < r) {
		a = q[l++];
		rep (i, 1, A)
			if (f[i] && a - i >= 0 && d[a-i] <= 0) {
				d[a-i] = d[a] + 1;
				q[r++] = a - i;
			}
		rep (i, 1, B)
			if (g[i] && a + i < maxn * 2 && d[a+i] <= 0) {
				d[a+i] = d[a] + 1;
				q[r++] = a + i;
			}
	}
	if (d[maxn]) cout << d[maxn] << endl;
	else puts("-1");
	return 0;
}