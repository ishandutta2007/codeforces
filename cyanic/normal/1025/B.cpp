#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long LL;

const int maxn = 150005;
int a[maxn], b[maxn], n;

void check(int x) {
	// printf("%d\n", x);
	rep (i, 2, n) {
		// printf("%d   %d   %d\n", i, a[i] % x, b[i] % x);
		if (a[i] % x != 0 && b[i] % x != 0)
			return;
	}
	printf("%d\n", x);
	exit(0);
}

int main() {
	scanf("%d", &n);
	rep (i, 1, n) 
		scanf("%d%d", &a[i], &b[i]);
	if (n == 1) {
		printf("%d\n", a[1]);
		return 0;
	}
	
	for (int i=2; i*i<=a[1]; i++)
		if (a[1] % i == 0) {
			check(i);
			while (a[1] % i == 0)
				a[1] /= i;
		}
	if (a[1] >= 2) check(a[1]);
	
	for (int i=2; i*i<=b[1]; i++)
		if (b[1] % i == 0) {
			check(i);
			while (b[1] % i == 0)
				b[1] /= i;
		}
	if (b[1] >= 2) check(b[1]);
	
	puts("-1");
	return 0;
}