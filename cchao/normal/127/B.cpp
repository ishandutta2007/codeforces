#include <bits/stdc++.h>
using namespace std;

int n, a[110];
map<int, int> m;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		m[a[i]]++;
	}
	int ans = 0;
	for(auto it : m)
		ans += it.second / 2;
	printf("%d\n", ans / 2);
	return 0;
}