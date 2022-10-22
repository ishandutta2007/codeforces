/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
string s;

int32_t main() {
	string a;
	cin >> a;
	int n;
	cin >> n;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[0] == a[0] && s[1] == a[1]) {
			cout << "YES";
			return 0;
		} 
		if (s[0] == a[1]) {
			y++;
		}
		if (s[1] == a[0]) {
			x++;
		}
	}
	if (!x || !y) {
		cout << "NO";
		return 0;
	}
	cout << "YES";
}