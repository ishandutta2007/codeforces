#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 100005;
ll f[maxn], mx, col, mx2, col2, a, b;
int v[maxn], c[maxn], n, Q;

int main() {
	scanf("%d%d", &n, &Q);
	rep (i, 1, n) scanf("%d", &v[i]);
	rep (i, 1, n) scanf("%d", &c[i]);
	while (Q--) {
		scanf("%I64d%I64d", &a, &b);
		memset(f, 0xc0, sizeof f);
		mx = mx2 = col = col2 = 0;
		rep (i, 1, n) {
			f[c[i]] = max(f[c[i]], f[c[i]] + v[i] * a);
			if (c[i] == col) f[c[i]] = max(f[c[i]], mx2 + v[i] * b);
			else f[c[i]] = max(f[c[i]], mx + v[i] * b);
			if (f[c[i]] >= mx) {
				if (col != c[i]) mx2 = mx; 
				mx = f[c[i]]; col = c[i];
			}
			else if (f[c[i]] > mx2 && c[i] != col)
				mx2 = f[c[i]];
		}
		printf("%I64d\n", mx);
	}	
	return 0;
}