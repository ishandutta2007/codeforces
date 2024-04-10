#include <iostream>
using namespace std;

int n, a[100009], b[100009]; long double E = 1, P;

int main() {
	cin >> n >> P;
	for (int i = 0; i < n; i++) { cin >> a[i]; E *= 1.0L*(a[i] - 1) / a[i]; }
	for (int i = 0; i < n; i++) { cin >> b[i]; E *= 1.0L*(b[i] - 1) / b[i]; }
	if (E < 1e-11) { cout << "-1" << endl; }
	else printf("%.12Lf\n", (P / E) - P);
	return 0;
}