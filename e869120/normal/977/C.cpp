#include <iostream>
#include <algorithm>
using namespace std;

long long n, k, a[200009];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if (k == 0) {
		if (a[0] == 1) cout << "-1" << endl;
		else cout << "1" << endl;
	}
	else {
		if (k == n || a[k - 1] != a[k]) cout << a[k - 1] << endl;
		else cout << "-1" << endl;
	}
	return 0;
}