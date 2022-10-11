#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int n, a[200009], b[200009];
int main() {
	cin >> n; for (int i = 1; i <= n; i++)cin >> a[i];
	if (n % 2 == 1) {
		for (int i = 2; i <= n; i += 2)b[i] = i;
		for (int i = 1; i <= n; i += 2)b[i] = n - i + 1;
	}
	if (n % 2 == 0) {
		for (int i = 2; i <= n; i += 2) {
			if (i <= n / 2)b[i] = i;
			else b[n + 1 - i] = i;
		}
		for (int i = 1; i <= n / 2; i++)b[n + 1 - i] = n + 1 - b[i];
	}
	for (int i = 1; i <= n; i++) {
		if (i >= 2)cout << ' ';
		cout << a[b[i]];
	}
	cout << endl;
	return 0;
}