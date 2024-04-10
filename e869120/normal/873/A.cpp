#include <iostream>
using namespace std;
int n, k, x, a[100009], s;
int main() {
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) { cin >> a[i]; if (i >= n - k)s += x; else s += a[i]; }
	cout << s << endl;
	return 0;
}