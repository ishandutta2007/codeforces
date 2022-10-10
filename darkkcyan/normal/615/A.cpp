#include <iostream>

using namespace std;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

int main (void) {
	ios_base::sync_with_stdio(0);

	int m, n;
	cin >> n >> m;
	bool arr[m] = {0};

	int i, j;

	ff (i, n) {
		int t;
		cin >> t;
		ff (j, t) {
			int num;
			cin >> num;
			-- num;
			arr[num] = true;
		}
	}

	bool result = true;
	ff (i, m) {
		if (arr[i] == false) {
			result = false;
			break;
		}
	}

	if (result == true) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	return 0;
}