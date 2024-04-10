#include <iostream>

using namespace std;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

int main (void) {
	ios_base::sync_with_stdio(0);

	long long a, b, k, t;

	cin >> k >> a >> b;

	t = a % k;
	if (t != 0) {
		a -= t;
		if (t > 0) a += k;
	}

	t = b % k;
	if (t != 0) {
		b -= t;
		if (t < 0) b -= k;
	}

	// cout << a << ' ' << b << '\n';

	long long result = (b - a) / k + 1;
	cout << result << '\n';

	return 0;
}