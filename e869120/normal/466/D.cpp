#include<iostream>
#include<algorithm>
using namespace std;
long long n, h, a[100000], sum, ret = 1;
int main() {
	cin >> n >> h;
	for (int i = 1; i <= n; i++)cin >> a[i]; a[0] = h; a[n + 1] = h;
	for (int i = 0; i <= n; i++) { if (a[i] > h || abs(a[i] - a[i + 1]) >= 2) { cout << "0" << endl; return 0; } }
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i + 1]) { ret *= 1LL * (h + 1 - a[i]); ret %= 1000000007; }
		else if (a[i] - a[i + 1] == -1) { ret *= 1LL * (h + 1 - a[i + 1]); ret %= 1000000007; }
	}
	cout << ret << endl;
	return 0;
}