#include <stdio.h>
#define NoS {puts("-1"); return 0; }
int ans, a, b, f, k, now, need;
int main() {
	scanf("%d%d%d%d", &a, &b, &f, &k);
	now = b;
	if (k == 1 && (b < f || b < a - f)) NoS
	else if (k >= 2 && (b < a - f << 1)) NoS
	else if (k > 2 && (b < f << 1)) NoS;
	now -= f;
	for (int i = 1; i < k; i++) {
		need = i & 1 ? a - f << 1 : f << 1;
		if (now < need) now = b, ans++;
		now -= need;
	}
	if ((k & 1) && (now < a - f)) ans++;
	else if ((k & 1 ^ 1) && (now < f)) ans++;
	printf("%d\n", ans);
	return 0;
}