#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int, int> m;

	int n; scanf("%d", &n);
	for(int a, b, i = 0; i < n; ++i) {
		scanf("%d%d", &a, &b);
		m[a] = max(m[a], b);
	}
	int mx = 0;
	for(auto it : m) {
		if(it.second < mx) {
			puts("Happy Alex");
			return 0;
		}
		mx = max(mx, it.second);
	}
	puts("Poor Alex");

	return 0;
}