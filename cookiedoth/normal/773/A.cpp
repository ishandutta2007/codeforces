#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long x, y, p, q;
		cin >> x >> y >> p >> q;
		long long left = 0;
		long long right = 2000000000;
		while (right - left > 1) {
			long long mid = (left + right) / 2;
			if (p * mid >= x && (q - p) * mid >= y - x) {
				right = mid;
			}
			else {
				left = mid;
			}
		}
		if (p * right >= x && (q - p) * right >= y - x) {
			cout << p * right - x + (q - p) * right - y + x << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
    return 0;
}