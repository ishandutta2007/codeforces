#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000005;
int a[maxn], n, l = -1e9, r = 1e9;
char s[maxn];

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	scanf("%s", s+1);
	for (int i=2; i<=n; i++)
		if (s[i] == '1' && s[i-1] == '0') {
			l = max(l, a[i] + 1);
			l = max(l, a[i-1] + 1);
			l = max(l, a[i-2] + 1);
			l = max(l, a[i-3] + 1);
			l = max(l, a[i-4] + 1);
		}
		else if (s[i] == '0' && s[i-1] == '1') {
			r = min(r, a[i] - 1);
			r = min(r, a[i-1] - 1);
			r = min(r, a[i-2] - 1);
			r = min(r, a[i-3] - 1);
			r = min(r, a[i-4] - 1);
		}
	printf("%d %d\n", l, r);
	return 0;
}