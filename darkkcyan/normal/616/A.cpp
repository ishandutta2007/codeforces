#include <iostream>
#include <string>

using namespace std;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

int main (void) {
	ios_base::sync_with_stdio(0);

	string a, b;
	cin >> a >> b;

	int i, j;

	i = j = 0;
	while (a[i] == '0') ++i;
	while (b[j] == '0') ++j;

	if (a.size() - i > b.size() - j) {
		cout << ">\n";
	} else if (a.size() - i < b.size() - j) {
		cout << "<\n";
	} else {
		bool haveSol = false;
		while (i < a.size()) {
			if (a[i] > b[j]) {
				cout << ">\n";
				haveSol = true;
				break;
			} else if (a[i] < b[j]) {
				haveSol = true;
				cout << "<\n";
				break;
			}
			++i;
			++j;
		}

		if (!haveSol) {
			cout << "=\n";
		}
	}

	return 0;
}