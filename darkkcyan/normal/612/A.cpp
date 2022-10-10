#include <iostream>

using namespace std;

#define fff(i, f, t) for (i = f; i < t; ++i)

int main (void) {
	int n, p, q;
	cin >> n >> p >> q >> ws;
	char str[n + 2];
	cin.getline(str, n + 1);

	int i, k, m;

	k = n / p;
	fff (i, 0, k) {
		if ((n - i * p) % q == 0) break;
	}

	if ((n - i * p) % q != 0) {
		cout << -1;
		return 0;
	}

	cout << (i + (n - i * p) / q) << '\n';

	m = i * p;
	for (i = 0; i < m; i += p) {
		for (k = 0; k < p; ++k) {
			cout << str[i + k];
		}
		cout << '\n';
	}

	for (; i < n; i += q) {
		for (k = 0; k < q; ++k) {
			cout << str[i + k];
		}

		cout << '\n';
	}


	return 0;
}