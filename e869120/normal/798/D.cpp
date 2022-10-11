#include<iostream>
using namespace std;
#pragma warning(disable:4996)

unsigned long long x = 1000000007;
unsigned long long Rand() {
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return x;
}
long long n, a[100005], b[100005], c, d; bool used[100005];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { scanf("%d", &a[i]); c += a[i]; }
	for (int i = 0; i < n; i++) { scanf("%d", &b[i]); d += b[i]; }
	while (true) {
		for (int i = 0; i < n; i++)used[i] = false;
		for (int i = 0; i < (n / 2) + 1; i++) {
			while (true) {
				int Y = Rand() % n;
				if (used[Y] == false) { used[Y] = true; break; }
			}
		}
		long long P = 0, Q = 0;
		for (int i = 0; i < n; i++) {
			if (used[i] == true) { P += a[i]; Q += b[i]; }
		}
		if (c < 2 * P && d < 2 * Q) {
			cout << (n / 2) + 1 << endl;
			bool OK = true;
			for (int i = 0; i < n; i++) {
				if (used[i] == true) { if (OK == false)cout << ' '; OK = false; cout << i + 1; }
			}
			cout << endl;
			break;
		}
	}
	return 0;
}