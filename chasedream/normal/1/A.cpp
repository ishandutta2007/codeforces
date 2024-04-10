#include <bits/stdc++.h>
using namespace std;
long long n, m, a;
int main() {
	scanf("%lld %lld %lld", &n, &m, &a);
	printf("%lld\n", ((n - 1) / a + 1) * ((m - 1) / a + 1));
	return 0;
}