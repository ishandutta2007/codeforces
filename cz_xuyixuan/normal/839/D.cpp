#include<bits/stdc++.h>
using namespace std;
#define MAXN	1000005
#define P	1000000007
long long rec[MAXN], value[MAXN];
int cnt[MAXN];
int main() {
	int n, m = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
		m = max(m, x);
	}
	for (int i = 2; i <= m; i++)
		for (int j = i + i; j <= m; j += i)
			cnt[i] += cnt[j];
	value[1] = 1;
	for (int i = 2; i <= n; i++)
		value[i] = value[i - 1] * 2 % P;
	for (int i = 2; i <= n; i++)
		value[i] = value[i] * i % P;
	long long ans = 0;
	for (int i = 2; i <= m; i++) {
		long long tmp = (i - rec[i]) % P;
		ans = (ans + tmp * value[cnt[i]]) % P;
		for (int j = i; j <= m; j += i)
			rec[j] = (rec[j] + tmp) % P;
	}
	printf("%I64d\n", (ans % P + P) % P);
	return 0;
}