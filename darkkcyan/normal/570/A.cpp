#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int a[n] = {0};
	for (int i = 0; i < m; ++i) {
		int b[n] = {0};
		for (int a, k = 0; k < n; ++k) cin >> b[k];
		a[max_element(b, b + n) - b] ++;
	}
	cout << (max_element(a, a + n) - a + 1);
	return 0;
}