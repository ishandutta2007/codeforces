#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	while(n > 0 and m > 0 and max(n, m) >= 2) {
		if(n < m) swap(n, m);
		n -= 2;
		m -= 1;
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}