#include<iostream>
#include<algorithm>
using namespace std;
int L = -1000000000, R = 1000000000, a[300000], b[300000], t[300000], n;
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> a[i] >> b[i]; }
	for (int i = n - 1; i >= 0; i--) { t[i] = t[i + 1] - a[i]; }
	for (int i = 0; i < n; i++) {
		if (b[i] == 1) { L = max(L, 1900 - t[i]); }
		if (b[i] == 2) { R = min(R, 1899 - t[i]); }
	}
	if (R == 1000000000)cout << "Infinity" << endl;
	else if (L > R)cout << "Impossible" << endl;
	else cout << R << endl;
	return 0;
}