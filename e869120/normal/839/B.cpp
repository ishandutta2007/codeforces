#include<iostream>
using namespace std;
int p, n, a[10009], A, B, C;
int main() {
	cin >> p >> n; B = 2 * p, C = p;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] == 2 && B > 0) { a[i] = 0; B--; }
	}
	for (int i = 0; i < n; i++) {
		while (a[i] >= 3 && C > 0) {
			if (a[i] >= 4) { a[i] -= 4; C--; }
			else { a[i] -= 3; C--; }
		}
	}
	for (int i = 0; i < n; i++) {
		while (a[i] >= 2 && B > 0) { a[i] -= 2; B--; }
	}
	for (int i = 0; i < n; i++) {
		while (a[i] >= 2 && C > 0) { a[i] -= 2; C--; A++; }
	}
	for (int i = 0; i < n; i++) {
		bool OK = true;
		while (OK) {
			OK = false;
			while (a[i] >= 1 && A > 0) { a[i] -= 1; A--; OK = true; }
			while (a[i] >= 1 && B > 0) { a[i] -= 1; B--; OK = true; }
			while (a[i] >= 1 && C > 0) { a[i] -= 1; C--; A++; OK = true; }
		}
	}
	bool OK = true; for (int i = 0; i < n; i++) { if (a[i] >= 1)OK = false; }
	if (OK == true)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}