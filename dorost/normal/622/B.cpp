/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	string s;
	cin >> s;
	string aa, bb;
	aa += s[0];
	aa += s[1];
	bb += s[3];
	bb += s[4];
	int a = stoi(aa), b = stoi(bb);
	int x = a * 60 + b;
	int y;
	cin >> y;
	x += y;
	x %= 1440;
	int h = x / 60, m = x % 60;
	if (h < 10)
		cout << 0;
	cout << h << ':';
	if (m < 10)
		cout << 0;
	cout << m;
}