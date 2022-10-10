#include <iostream>
using namespace std;

int main() {
	long long n, x; cin >> n >> x;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		char ch; long long d;
		cin >> ws >> ch >> d;
		if (ch == '+') x += d;
		else {
			if (x >= d) x -= d;
			else ++ans;
		}
	}
	cout << x << ' ' << ans;
	return 0;
}