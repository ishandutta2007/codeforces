#include <bits/stdc++.h>
using namespace std;

vector<int> cn[5500];
int c[5500];
int main() {
// 	freopen("in.txt", "r", stdin);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		cn[x].push_back(i - 1);
	}
	int cur = 0;
	for (int i = 1; i <= 5000; i++) {
		if (cn[i].size() > k) return puts("NO"), 0;
		for (int x : cn[i]) {
			c[x] = cur;
			cur = (cur + 1) % k;
		}
	}
	puts("YES");
	for (int i = 0; i < n; i++) printf("%d%c", c[i] + 1, " \n"[i == n - 1]);
	return 0;
}