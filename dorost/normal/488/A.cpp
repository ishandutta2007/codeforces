/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
bool ok (string x) {
	for (auto c : x) 
		if (c == '8')
			return true;
	return false;
}

int32_t main() {
	int n;
	cin >> n;
	for (int i = 1; ; i++) {
		if (ok(to_string(n + i))) {
			cout << i;
			return 0;
		}
	}
}