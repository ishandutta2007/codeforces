#include <bits/stdc++.h>
using namespace std;

const char str[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
const char a[] = "What are you doing while sending ";
const char b[] = "? Are you busy? Will you send ";

const long long INF = 1LL<<60;

long long f[110000];

void print(int n, long long k) {
	if (k > f[n]) {
		putchar('.');
		return;
	}
	if (n == 0) {
		putchar(str[k-1]);
		return;
	}
	int l = strlen(a);
	if (k <= l) {
		putchar(a[k-1]);
		return;
	}
	if (k == l+1) {
		putchar('""');
		return;
	}
	l++;
	if (k <= l + f[n-1]) {
		print(n-1, k - l);
		return;
	}
	if (k == l + f[n-1] + 1) {
		putchar('""');
		return;		
	}
	l++;
	int ll = strlen(b);
	if (k <= ll + l + f[n-1]) {
		putchar(b[k - l - f[n-1] - 1]);
		return;
	}
	if (k == ll + l + f[n-1] + 1) {
		putchar('""');
		return;
	}
	ll++;
	if (k == f[n] - 1) {
		putchar('""');
		return;		
	}
	if (k == f[n]) {
		putchar('?');
		return;
	}
	print(n-1, k - l - f[n-1] - ll);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int q; scanf("%d", &q);
	f[0] = strlen(str);
	for (int i = 1; i <= 100000; i++) f[i] = min(INF, 2 * f[i-1] + 4 + strlen(a) + strlen(b) + 1);
	for (int i = 0; i < q; i++) {
		int n; long long k; scanf("%d%lld", &n, &k);
		print(n, k);
	}
	puts("");
	return 0;
}