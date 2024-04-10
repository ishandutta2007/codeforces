#include <bits/stdc++.h>
using namespace std;

#define bit(x) (1 << (x))
#define cnti(x) (__builtin_popcount(x))
#define ctzi(x) (__builtin_ctz(x))

char s[100010];
int b[100010], a[7], d[7], c[64], an;

int main() {
	int n;scanf("%d%s", &n, s);
	for (int i = 2, m = n; i <= m; i++) if (m % i == 0) {
		a[an++] = i;
		while (m % i == 0) m /= i;
	}
	for (int i = 0; i <= an; i++) d[i] = (i == 0 ? 1 : d[i-1] * a[i-1]);
	int m = n / d[an];
	for (int r = 0; r < m; r++) {
		for (int i = 0; i < n/m; i++) {
			int t = 0;
			for (int j = an-1; j >= 0; j--) t = t * a[j] + i % a[j];
			b[t] = s[i*m+r] - '0';
		}
		for (int t = 0; t < n/m; t++) {
			int x = 0;
			for (int i = 0; i < bit(an); i++) {
				int k = ctzi(i);
				c[i] = (i == 0 ? t : c[i-bit(k)] - (t / d[k] % a[k]) * d[k]);
				if (cnti(i) & 1) x += b[c[i]];
				else x -= b[c[i]];
			}
			if (x) return puts("NO"), 0;
		}
	}
	puts("YES");
	return 0;
}