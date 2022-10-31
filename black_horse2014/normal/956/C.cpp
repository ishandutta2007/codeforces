#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int m[N], ma[N];

int main() {
	int n; scanf("%d", &n);
	long long up = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", m + i);
		up += m[i];
		ma[i] = max(ma[i - 1], m[i]);
	}
	for (int i = n - 1; i >= 1; i--) ma[i] = max(ma[i], ma[i + 1] - 1);
	long long sum = 0;
	for (int i = 1; i <= n; i++) sum += ma[i];
	printf("%lld\n", sum - up);
	return 0;
}