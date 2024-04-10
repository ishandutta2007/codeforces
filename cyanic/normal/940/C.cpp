#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;
int n, k, use[30], last;
char s[maxn], mn = 127, mx = 0;

int main() {
	scanf("%d%d%s", &n, &k, s+1);
	for (int i=1; i<=n; i++) {
		use[s[i]-'a'] = 1;
		mn = min(mn, s[i]);
		mx = max(mx, s[i]);
	}
	if (k > n) {
		for (int i=1; i<=n; i++) putchar(s[i]);
		for (int i=n+1; i<=k; i++) putchar(mn);
		return 0;
	}
	last = k;
	while (s[last] == mx) last--;
	for (int i=1; i<=k-1&&i<=last-1; i++) putchar(s[i]);
	int i = min(k, last);
	for (int j=0; j<=25; j++)
		if (use[j] && j > s[i]-'a') {
			putchar('a' + j); break;
		}
	while (i < k) putchar(mn), i++;
	return 0;
}