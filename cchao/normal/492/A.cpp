#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; scanf("%d", &n);
	int ans = 0, idx = 0, cur = 0, sum = 0;
	while(true) {
		idx++;
		cur += idx;
		sum += cur;
		if(sum <= n) ans = idx;
		else break;
	}
	printf("%d\n", ans);
	return 0;
}