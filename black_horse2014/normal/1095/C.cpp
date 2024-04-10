#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	int n, k; cin >> n >> k;
	for (int i = 0; n; i++) {
		if (n & 1) pq.push(i);
		n /= 2;
	}
	while (pq.size() < k) {
		int c = pq.top(); pq.pop();
		if (c == 0) {
			puts("NO");
			return 0;
		}
		pq.push(c - 1); pq.push(c-1);
	}
	if (pq.size() > k) {
		puts("NO");
		return 0;
	}
	puts("YES");
	while (pq.size() > 0) {
		int c = pq.top(); pq.pop();
		printf("%d ", (1 << c));
	}
	puts("");
	return 0;
}