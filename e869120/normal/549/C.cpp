#include<iostream>
using namespace std;
int n, k, a[200009], p, q, c;
int main() {
	cin >> n >> k; k = n - k; for (int i = 1; i <= n; i++) { cin >> a[i]; if (a[i] % 2 == 1)p++; else q++; }
	if ((k % 2 == 1 && (p <= k / 2 || (n % 2 == 1 && q <= k / 2))) || (k % 2 == 0 && n % 2 == 1 && q <= k / 2))c = 1;
	if ((k >= 1 && (k + c) % 2 == 1) || (k == 0 && p % 2 == 1))cout << "Stannis" << endl;
	else cout << "Daenerys" << endl;
	return 0;
}