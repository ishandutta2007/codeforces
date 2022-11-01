#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 111111;

int cost[N];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int x;
		scanf("%d %d", &x, &cost[i]);
	}
	sort(cost + 1, cost + m + 1);
	for(int i = 1; i <= m; i++) {
		long long r = (m - i + 1), cnt = 0;
		if (r % 2 == 1) {
			cnt = r * (r - 1) / 2 + 1;
		} else {
			cnt = r * (r - 1) / 2 + r / 2;
		}
		if (cnt <= n) {
			long long ans = 0;
			for(int j = i; j <= m; j++)
				ans += cost[j];
			printf("%I64d\n", ans);
			break;
		}
	}
	return 0;
}