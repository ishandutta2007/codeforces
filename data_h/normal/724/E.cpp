#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

const int N = 1e4 + 7;
const long long INF = (1LL << 60);

int product[N], sold[N];
long long f[N];
int n, c;

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) scanf("%d", &product[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &sold[i]);
	std::fill(f, f + n + 1, INF);
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			f[j] = std::min(f[j] + product[i] + 1LL * c * j, f[j - 1] + sold[i]);
		}
		f[0] = f[0] + product[i];
	}
	long long ans = INF;
	for (int i = 0; i <= n; i++) {
		ans = std::min(ans, f[i]);
	}
	printf("%I64d\n", ans);
	return 0;
}