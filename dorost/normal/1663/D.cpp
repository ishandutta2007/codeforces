/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	string s;
	int x;
	cin >> s >> x;
	if (s == "ABC") {
		cout << (x < 2000 ? "YES\n" : "NO\n");
	} else if (s == "ARC") {
		cout << (x < 2800 ? "YES\n" : "NO\n");
	} else if (s == "AGC") {
		cout << (x >= 1200 ? "YES\n" : "NO\n");
	} else {
		cout << "NO\n";
	}
}