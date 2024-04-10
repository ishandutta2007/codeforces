#include <iostream>
#include <algorithm>
using namespace std;

int n, a[10009], maxn = 0;

void query(int l, int r) {
	bool flag = false;
	for (int i = l; i < r - 1; i++) {
		if (a[i] > a[i + 1]) flag = true;
	}
	if (flag == false) maxn = max(maxn, r - l);

	if (r - l >= 2) {
		query(l, (l + r) >> 1);
		query((l + r) >> 1, r);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	query(0, n);
	cout << maxn << endl;
	return 0;
}