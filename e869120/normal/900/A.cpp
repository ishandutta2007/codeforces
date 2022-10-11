#include <iostream>
using namespace std;

int n, x[100009], y[100009], c1, c2;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		if (x[i] > 0) c1++;
		if (x[i] < 0) c2++;
	}
	if (c1 <= 1 || c2 <= 1) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}