#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long solve(long long N, long long K, vector<long long>E) {
	sort(E.begin(), E.end());
	long long minx = (1LL << 60), minid = 0;
	for (int i = 0; i < (int)E.size() - K; i++) {
		long long mid = (E[i + K] + E[i]) / 2LL;
		if (minx > (E[i + K] - E[i])) {
			minx = (E[i + K] - E[i]);
			minid = mid;
		}
	}
	return minid;
}

int main() {
	long long t, n, k; scanf("%lld", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%lld%lld", &n, &k);
		vector<long long>e; for (int j = 0; j < n; j++) { long long a; scanf("%lld", &a); e.push_back(a); }
		printf("%lld\n", solve(n, k, e));
	}
	return 0;
}