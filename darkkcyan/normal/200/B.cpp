#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	double s = 0;
	for (int a, i = 0; i < n; ++i) cin >> a, s += a;
	cout << fixed <<  (s / n);
	return 0;
}