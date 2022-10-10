#include <iostream>

using namespace std;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

int main (void) {
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;

	int i, k, m;

	ff (i, t) {
		long long a;
		cin >> a;
		long long result = a * (a + 1) / 2;
		long long t = 1;
		long long p = 0;

		while (t <= a) {
			t <<= 1;
			p += t;
		}

		result -= p;
		cout << result << '\n';
	}

	return 0;
}