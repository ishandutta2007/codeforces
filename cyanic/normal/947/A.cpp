#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000009;
int p[maxn], f[maxn], tot, x2, x0 = maxn;

void init() {
	for (int i=2; i<maxn; i++) {
		if (!f[i]) p[++tot] = i;
		for (int j=1; j<=tot&&i*p[j]<maxn; j++) {
			f[i*p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
	memset(f, 0x3f, sizeof f);
	for (int i=1; i<=tot; i++)
		for (int j=2*p[i]; j<maxn; j+=p[i])
			f[j] = min(f[j], j - p[i] + 1);
}

int main() {
	scanf("%d", &x2); init();
	for (int i=f[x2]; i<=x2; i++)
		x0 = min(x0, f[i]);
	printf("%d\n", x0);
	return 0;
}