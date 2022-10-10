#include <iostream>
using namespace std;


int main() {
	int n, t;
	cin >> n >> t; --t;
	int a[n];
	for (int i = 0; i < n - 1; ++i) cin >> a[i];
	int pos = 0;
	while (pos != n - 1 and pos != t) {
		pos = pos + a[pos];
	}
	if (pos == t) cout << "YES";
	else cout << "NO";
	return 0;
}