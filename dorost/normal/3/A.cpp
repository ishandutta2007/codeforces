/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	string a, b;
	cin >> a >> b;
	int x = a[0] - b[0], y = a[1] - b[1];
	cout << max(abs(x), abs(y)) << '\n';
	for (int i = 0; min(abs(x), abs(y)); i++) {
		string a;
		if (x > 0)
			x--, a += 'L';
		else 
			x++, a += 'R';
		if (y > 0)
			y--, a += 'D';
		else
			y++, a += 'U';
		cout << a << '\n';
	}
	if (x != 0) {
		for (int i = 0; abs(x); i++) {
			string a;
			if (x > 0)
				x--, a += 'L';
			else 
				x++, a += 'R';
			cout << a << '\n';
		}
	} else {
		for (int i = 0; abs(y); i++) {
			string a;
			if (y > 0)
				y--, a += 'D';
			else 
				y++, a += 'U';
			cout << a << '\n';
		}
	}
}