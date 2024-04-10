#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int n, m, k;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	if (k > n + m - 2) {
		cout << -1 << endl;
		return 0;
	}
	long long result = max(1LL * n * (m / (k + 1)), 1LL * m * (n / (k + 1)));
	for(int i = 1; i <= n; ) {
		int next = n / (n / i);
		int lft = max(0, k - (next - 1));
		result = max(result, 1LL * (n / i) * (m / (lft + 1)));
		i = next + 1;
	}
	cout << result << endl;
	return 0;
}