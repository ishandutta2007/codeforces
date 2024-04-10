#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

	string a;
	cin >> a;
	ll ans = 1;

	int last = 0;
	for (int i = 1; i <= a.length(); ++i) {

		if (i == a.length() || (a[i] + a[i - 1] != '0' + '9')) {
			if ((i - last) > 1 && ((i - last) & 1))
				ans *= (i - last + 1) / 2;
			last = i;
		}
	}
	cout << ans << "\n";
	return 0;
}