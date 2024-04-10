#include<bits/stdc++.h>
using namespace std;

const int maxn = 200005;
int a[maxn], n, s, f, best, p, l, r, now;

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]), a[i+n] = a[i];
	for (int i=1; i<=2*n; i++) a[i] += a[i-1];
	scanf("%d%d", &s, &f);
	for (int i=1; i<=n; i++) {
		l = s + 1 - i; r = f - i;
		if (l <= 0) l += n;
		while (r < l) r += n;
		now = a[r] - a[l-1];
		if (now > best) best = now, p = i;
	}
	printf("%d\n", p);
	return 0;
}