#include <iostream>

using namespace std;

int main() {
	long long X, Y; cin >> X >> Y;
	long long Z, T; cin >> Z >> T;

	int n;
	cin >> n;

	int res = 0;

	for (int i = 0; i < n; ++i) {
		long long a, b, c;
		cin >> a >> b >> c;
		long long D1 = X * a + Y * b + c > 0 ? 1 : -1;
		long long D2 = Z * a + T * b + c > 0 ? 1 : -1;
		if (D1 != D2)
			++res;
	}
	cout << res << endl;
	return 0;
}