#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	int ans = max(n, n/10);

	int d = n % 10;

	ans = max(ans, (n/100)*10 + d);

	cout << ans << endl;

	return 0;
}