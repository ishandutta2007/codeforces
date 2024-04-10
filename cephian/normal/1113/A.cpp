#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, v;
	cin >> n >> v;
	int t = 1, cost = 0;
	for(int w = 1; w <= n; ++w) {
		--t;
		int add = max(min(v,n-w)-t, 0);
		t += add;
		cost += add*w;
	}
	cout << cost << "\n";
}