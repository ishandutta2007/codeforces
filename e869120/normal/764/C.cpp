#include<iostream>
#pragma warning(disable:4996)
using namespace std;
int n, c[120000], a[120000], b[120000], cnt, x[120000]; bool flag = false;
int main() {
	cin >> n; for (int i = 0; i < n - 1; i++) { scanf("%d%d", &a[i], &b[i]); }
	for (int i = 1; i <= n; i++)cin >> c[i];
	for (int i = 0; i < n - 1; i++) { if (c[a[i]] != c[b[i]]) { x[a[i]]++; x[b[i]]++; cnt++; } }
	for (int i = 1; i <= n; i++) {
		if (cnt == x[i]) { cout << "YES" << endl; cout << i << endl; flag = true; break; }
	}
	if (flag == false)cout << "NO" << endl;
	return 0;
}