#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
long long a[200000], n, q, l, r, ret;
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)a[i] += a[i - 1];
	for (int i = 1; i <= q; i++) {
		cin >> l >> r;
		long long Y = a[r] - a[l - 1];
		if (Y > 0)ret += Y;
	}
	cout << ret << endl;
	return 0;
}