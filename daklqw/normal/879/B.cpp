#include <stdio.h>
#include <vector>
long long k;
int n, max, cnt, x;
std::vector<int> a;
int main() {
	scanf("%d%I64d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &x), max = max < x ? x : max, a.push_back(x);
	for (int i = 1; i < n; i++) {
		if (a[0] < a[1]) cnt = 1, a.push_back(a[0]), a.erase(a.begin());
		else cnt++, a.push_back(a[1]), a.erase(a.begin() + 1);
		if (cnt == k) {
			printf("%d\n", a[0]); return 0;
		}
	}
	printf("%d\n", max);
	return 0;
}