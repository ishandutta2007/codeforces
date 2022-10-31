#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a, b; cin >> n >> m >> a >> b;
	int ans = min((n / m) * b + (n % m) * a, a * n);
	ans = min(ans, (n + m - 1) / m * b);
	cout << ans << endl;
	return 0;
}