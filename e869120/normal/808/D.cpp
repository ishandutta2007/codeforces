#include<iostream>
#include<algorithm>
using namespace std;
long long n, a[100009], b[100009], s;
bool solve() {
	for (int i = 0; i < n; i++)b[i] = a[i];
	for (int i = 1; i <= n; i++)b[i] += b[i - 1];
	for (int i = 0; i < n; i++) {
		int pos1 = lower_bound(b, b + n, (s / 2) + a[i]) - b;
		if (i <= pos1 && b[pos1] == (s / 2) + a[i])return true;
	}
	return false;
}
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> a[i]; s += a[i]; }
	if (s % 2 == 1) { cout << "NO" << endl; return 0; }
	bool OK1 = solve();
	reverse(a, a + n);
	bool OK2 = solve();
	if (OK1 == true || OK2 == true)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}