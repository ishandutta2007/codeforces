#include<bits/stdc++.h>
using namespace std;

const int maxn = 4000009, MOD = 51123987;
int pre[maxn], suf[maxn], r[maxn], n, p, mx, tot;
char s[maxn], str[maxn];

void manachar(char s[], int &n) {
	for (int i=1; i<=n; i++) {
		str[i<<1] = s[i]; str[i<<1|1] = '#';
	}
	str[0] = '@'; str[1] = '#'; str[(n+1)<<1] = '$';
	p = mx = 0; n = n * 2 + 1;
	for (int i=1; i<=n; i++) {
		r[i] = max(0, min(r[2*p-i], mx-i));
		while (i+r[i] <= n && str[i-r[i]] == str[i+r[i]]) r[i]++;
		if (i + r[i] > mx) { mx = i + r[i]; p = i; }
		// putchar(str[i]);
		// printf("  %d\n", r[i]);
	}
}

int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	manachar(s, n);
	for (int i=1; i<=n; i++) {
		pre[i]++; pre[i+r[i]]--; 
		suf[i]++; suf[i-r[i]]--;
		tot = (tot + r[i] / 2) % MOD;
	}
	for (int i=1; i<=n; i++) 
		pre[i] = (pre[i-1] + pre[i]) % MOD;
	for (int i=1; i<=n; i++) 
		if (str[i] == '#') pre[i] = 0;
	for (int i=1; i<=n; i++)
		pre[i] = (pre[i-1] + pre[i]) % MOD;
	for (int i=n; i>=1; i--)
		suf[i] = (suf[i+1] + suf[i]) % MOD;
	for (int i=1; i<=n; i++)
		if (str[i] == '#') suf[i] = 0;
	tot = 1LL * tot * (tot - 1) / 2 % MOD;
	for (int i=3; i<=n-2; i++)
		if (str[i] == '#') {
			tot = (tot - 1LL * pre[i-1] * suf[i+1] % MOD + MOD) % MOD;
			// printf("%d %d %d\n", i, pre[i-1], suf[i+1]);
		}
	printf("%d\n", tot);
	return 0;
}