#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long n, a[1 << 18], sum;
vector<long long> v1, v2;

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]); sum += a[i];
		if (a[i] % 2 == 0) v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int c1 = v1.size() - 1, c2 = v2.size() - 1, ty = 0;
	if (v1.size() < v2.size()) ty = 1;

	while (true) {
		if (ty == 0) { if (c1 < 0) break; sum -= v1[c1]; c1--; }
		if (ty == 1) { if (c2 < 0) break; sum -= v2[c2]; c2--; }
		ty ^= 1;
	}
	printf("%lld\n", sum);
	return 0;
}