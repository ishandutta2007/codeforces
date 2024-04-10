#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = (1 << 12) + 5;
const int maxm = 105;
int f[maxn][maxm], c[maxn], w[maxn], g[maxn], h[maxn];
int n, m, Q, ALL, now, a;
char s[maxn];

int main() {
	cin >> n >> m >> Q;
	rep (i, 1, n) scanf("%d", &w[i]);
	rep (i, 1, m) {
		scanf("%s", s);
		now = 0;
		for (int j = 0; s[j]; j++)
			now = now * 2 + s[j] - '0';
		c[now]++;
	}
	ALL = (1 << n) - 1;
	rep (i, 0, ALL) rep (j, 0, n - 1)
		if (i >> j & 1) h[i] += w[n-j];
	rep (i, 0, ALL) rep (j, 0, ALL)
		if (h[(~(i^j))&ALL] <= 100) 
			f[j][h[(~(i^j))&ALL]] += c[i];
	rep (i, 0, ALL) rep (j, 1, 100)
		f[i][j] += f[i][j-1];
	while (Q--) {
		scanf("%s%d", s, &a);
		now = 0;
		for (int j = 0; s[j]; j++)
			now = now * 2 + s[j] - '0';
		printf("%d\n", f[now][a]);
	}	
	return 0;
}