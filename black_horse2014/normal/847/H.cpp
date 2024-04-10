#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int a[N];
int b[N], c[N];
long long sum1[N], sum2[N];

int main() {
	int n; scanf("%d", &n);
	long long sum = 0;
	for (int i = 0; i < n; i ++) scanf("%d", a + i), sum += a[i];
	b[0] = a[0];
	sum1[0] = a[0];
	for (int i = 1; i < n; i ++) {
		b[i] = max(b[i-1] + 1, a[i]);
		sum1[i] = sum1[i - 1] + b[i];
	}
	c[n - 1] = a[n - 1];
	sum2[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i --) {
		c[i] = max(c[i+1] + 1, a[i]);
		sum2[i] = sum2[i + 1] + c[i];
	}
	long long cur = 1e18;
	for (int i = 0; i < n; i ++) {
		if (b[i] > c[i + 1]) cur = min(cur, sum1[i] + sum2[i + 1]);
	}
	cout << cur - sum << endl;
	return 0;
}