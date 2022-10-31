#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;
int a[27], b[5];
long long sum, dp[(1 << 24) + 3];
int main() {
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	scanf("%d", &m);
	for(int i = 0; i < m; i++) scanf("%d", b + i);
	dp[0] = 1;
	for(int i = 1; i < (1 << n); i++) {
		sum = 0;
		for(int j = 0; j < n; j++) if(i & (1 << j)) {
			dp[i] += dp[i ^ (1 << j)];
			sum += a[j];
		}
		for(int j = 0; j < m; j++) if(sum == b[j]) dp[i] = 0;
		dp[i] %= mod;
	}
	printf("%I64d\n", dp[(1 << n) - 1]);
	return 0;
}