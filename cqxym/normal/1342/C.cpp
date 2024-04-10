#include <bits/stdc++.h>
using namespace std;
int f[100000];
long long solve(long long p, int n) {
	return f[n - 1] * (p / n) + f[p % n];
}
int main() {
	int t;
	scanf("%d", &t);
	while(t --) {
		int a, b, q;
		scanf("%d %d %d", &a, &b, &q);
		int n = a * b;
		for (int i = 1; i < n; i ++) {
			f[i] = f[i - 1];
			if(i % a % b != i % b % a)
			                f[i] ++;
		}
		while(q --) {
			long long l, r;
			scanf("%I64d %I64d", &l, &r);
			printf("%I64d ", solve(r, n) - solve(l - 1, n));
		}
		puts("");
	}
	return 0;
}