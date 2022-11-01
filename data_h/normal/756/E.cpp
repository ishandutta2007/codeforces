#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cassert>
using namespace std;

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;
const int LEN = 8, MAGIC = 1e8;

int a[N], b[N];
int n;
char bignum[N];

long long m[N];
int tot;

int f[N], g[N];

int add(int a, int b) {
	a += b;
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
	//assert(a >= 0 && a < MOD);
	return a;
}

int divide(int d) {
	long long remain = 0;
	for (int i = tot - 1; i >= 0; i--) {
		remain = remain * MAGIC + m[i];
		m[i] = remain / d;
		remain = remain % d;
	}
	while (tot > 1 && m[tot - 1] == 0) tot--;
	return remain;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
	}
	a[n] = 1e9 + 7;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
	}
	{
		scanf("%s", bignum);
		tot = 0;
		int cur = 0, l = strlen(bignum);
		for (int i = l - 1; i >= 0; i -= LEN) {
			cur = 0;
			for (int j = max(0, i - LEN + 1); j <= i; j++) {
				cur = cur * 10 + bignum[j] - '0';
			}
			m[tot++] = cur;
		}
	}
	// printf("%lld %lld\n", m[0], m[1]);
	int carry = 0;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		int new_carry = carry + b[i], s = 0;
		fill(g, g + new_carry + 1, 0);
		for (int j = 0; j <= new_carry; j++) {
			s = add(s, f[j]);
			if (j > b[i]) {
				s = add(s, -f[j - b[i] - 1]);
			}
			g[j] = s;
		}
		fill(f, f + carry + 1, 0);
		// printf("a[%d] = %d carry = %d newcarry = %d %d %d\n", i, a[i], carry, new_carry, g[0], g[1]);
		if (a[i] > 1) {
			int remainder = divide(a[i]);
			// printf("remainder = %d\n", remainder);
			// for (int j = 0; j < tot; j++) {
			// 	printf("%08lld", m[j]);
			// }
			// puts("");
			for (int ii = remainder, jj = 0; ii <= new_carry; ii += a[i], jj++) {
				f[jj] = g[ii];
			}

			carry = (new_carry - remainder) / a[i];
		} else if (a[i] == 1) {
			for (int i = 0; i <= new_carry; i++) f[i] = g[i];
			carry = new_carry;
		} else {
			assert(false);
		}
		// if (carry < 100) {
		// 	for (int j = 0; j <= carry; j++) {
		// 		printf("%d ", f[j]);
		// 	}
		// 	puts("");
		// }
	}
	if (tot == 1 && m[0] == 0) {
		printf("%d\n", f[0]);
	} else {
		puts("0");
	}
	return 0;
}