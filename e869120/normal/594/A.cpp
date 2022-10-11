#include<iostream>
#include<algorithm>
using namespace std;
int n, a[200009];
int solve(int p) {
	int minx = 1e9;
	for (int i = 0; i < n - p; i++)minx = min(minx, a[i + p] - a[i]);
	return minx;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	if (n % 2 == 1) {
		if (n == 3)cout << solve(1) << endl; else cout << solve(2) << endl;
	}
	else { cout << solve(n / 2) << endl; }
	return 0;
}