#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) {
		int x; cin >> x; --x;
		a[x] = i + 1;
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	return 0;
}