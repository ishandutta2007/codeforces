#include<iostream>
#include<algorithm>
using namespace std;
int prime[2500000], n, a[2000], H;
int main() {
	for (int i = 2; i*i <= 2400000; i++) {
		for (int j = i*i; j <= 2400000; j += i)prime[j] = 1;
	}
	cin >> n; for (int i = 0; i < n; i++) { cin >> a[i]; if (a[i] == 1)H++; }
	if (H == n) { cout << n << endl; for (int i = 0; i < n; i++) { if (i)cout << ' '; cout << a[i]; }cout << endl; return 0; }
	if (H >= 1) {
		for (int i = 0; i < n; i++) {
			if (a[i] != 1) { if (prime[1 + a[i]] == 0) { cout << 1 + H << endl; cout << a[i]; for (int j = 0; j < H; j++)cout << " 1"; cout << endl; return 0; } }
		}
	}
	if (H >= 2) { cout << H << endl; for (int i = 0; i < H; i++) { if (i)cout << ' '; cout << "1"; }cout << endl; return 0; }
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (prime[a[i] + a[j]] == 0) {
				cout << "2" << endl; cout << a[i] << ' ' << a[j] << endl;
				return 0;
			}
		}
	}
	cout << "1" << endl; cout << a[0] << endl;
	return 0;
}