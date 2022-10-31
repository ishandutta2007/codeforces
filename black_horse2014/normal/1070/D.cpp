#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; scanf("%d%d", &n, &k);
	long long rem = 0, dap = 0;
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		bool r = !!rem;
		rem += x;
		long long cn = max(1LL * r, rem / k);
		rem = max(0LL, rem - cn * k);
		dap += cn;
	}
	if (rem) dap++;
	printf("%lld\n", dap);
	return 0;
}