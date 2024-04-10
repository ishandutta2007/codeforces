#include <iostream>
#include <string>

using namespace std;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

int main (void) {
	ios_base::sync_with_stdio(0);

	string str;
	cin >> str;
	int strSize = str.size();
	string tempStr(strSize, ' ');

	int m;
	cin >> m;

	int i, j, l;

	ff (i, m) {
		int a, b;
		long k;
		cin >> a >> b >> k;
		--a;
		k %= (b - a);

		if (k == 0) {
			// cout << __LINE__ << str << endl;
			continue;
		}

		int p = (b - a) / k;

		ff (j, k) {
			char carry = str[b - k + j];
			for (l = a + j; l < b; l += k) {
				tempStr[l] = carry;
				carry = str[l];
			}
		}

		fff (j, a, b) {
			str[j] = tempStr[j];
		}

		// cout << __LINE__ << str << endl;

	}

	cout << str;

	return 0;
}