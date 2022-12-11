#include <iostream>
using namespace std;
int n, x, a[100005], m;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
//		a[i] -= i - 1;
//		if (a[i] <= 0) {
//			printf("%d\n", i);
//			return 0;
//		}
//		a[i] += i - 1;
	}
	m = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) m = min(m, a[i]);
	for (int i = 1; i <= n; i++) a[i] -= m / n * n;
	for (int i = 1; i <= n; i++) {
		if (a[i] - i + 1 <= 0) {
			printf("%d\n", i);
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) a[i] -= n;
	for (int i = 1; i <= n; i++) {
		if (a[i] - i + 1 <= 0) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}