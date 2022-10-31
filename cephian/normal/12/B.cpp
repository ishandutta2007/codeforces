#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	string a, b;
	cin >> a >> b;

	if (a != "0") {

		int z = 0;
		string a2 = "";
		for (int i = 0; i < a.size(); ++i)
			if (a[i] == '0')
				++z;
			else
				a2 += a[i];

		sort(a2.begin(), a2.end());
		string z0 = "";

		while (z) {
			z0 += '0';
			--z;
		}
		a = a2.substr(0, 1) + z0 + a2.substr(1, 1000);

	}
	if (a == b)
		cout << "OK\n";
	else
		cout << "WRONG_ANSWER\n";

	return 0;
}