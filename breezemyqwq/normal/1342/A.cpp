#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long x, y, a, b;
		cin >> x >> y >> a >> b;
		if(x == 0) cout << abs(y) * a << endl;
		else if(y == 0) cout << abs(x) * a << endl;
		else if(2 * a < b) {
			cout << a * (abs(x) + abs(y)) << endl;
		}
		else {
			long long mn1, mn2;
			mn1 = (abs(x) + abs(y)) * a;
			if((x > 0 && y > 0) || (x < 0 && y < 0)) {
				int num = min(abs(x), abs(y));
				mn2 = num * b + (max(abs(x), abs(y)) - num) * a;
				cout << min(mn1, mn2) << endl;
			}
			else {
				int num = min(abs(x), abs(y));
				mn2 = num * b + (abs(x) + abs(y)) * a;
				cout << mn2 << endl;
			}
		}
	}
	return 0;
}