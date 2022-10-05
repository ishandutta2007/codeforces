#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define _rep(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 3005;
int h[maxn], a[maxn], n;
LL f[maxn], g[maxn], mn;

int main() {
	scanf("%d", &n);
	rep (i, 1, n) scanf("%d", &h[i]), a[i] = h[i] - i;
	sort(a + 1, a + n + 1);
	rep (i, 1, n) f[i] = abs(h[1] - (a[i] + 1));
	rep (i, 2, n) {
		rep (j, 1, n) g[j] = f[j];
		memset(f, 0x3f, sizeof f);
		mn = 2e18;
		rep (j, 1, n) {
			mn = min(mn, g[j]);
			f[j] = mn + abs(h[i] - (a[j] + i));
			//printf("%d %d %I64d\n", i, a[j]+i, f[j]);
		}
	}
	mn = 2e18;
	rep (i, 1, n) mn = min(mn, f[i]);
	printf("%I64d\n", mn);
	return 0;
}