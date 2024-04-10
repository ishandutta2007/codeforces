#include<iostream>
#include<algorithm>
using namespace std;
long long n, k, a[200000], minx = 1e18, cnt;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> a[i], minx = min(minx, a[i]);
	for (int i = 0; i < n; i++) { if ((a[i] - minx) % k != 0) { cout << "-1" << endl; return 0; } cnt += (a[i] - minx) / k; }
	cout << cnt << endl;
	return 0;
}