#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <string>

using namespace std;

long long ans, a[110000];
int n;

long long gcd(long long x, long long y) {
	if (y == 0)
		return x;
	return gcd(y, x % y);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%I64d\n", &a[i]);	
	ans = 0;
	for(int i = 1; i <= n; i++)
		ans += a[i];
	sort(a + 1, a + n + 1);
	long long sum = a[1];
	for(int i = 2; i <= n; i++) {
		long long res = 0;
		res = (long long)(i - 1) * a[i] - sum;
		ans += 2 * res;
		sum += a[i];
	}
	long long g = gcd(ans, n);
	printf("%I64d %I64d\n", ans / g, n / g);
	return 0;
}