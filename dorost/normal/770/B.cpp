/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main() {
	int n;
	cin >> n;
	ll mx = 0, an;
	if (n < 10) {
		mx = n;
		an = n;
	}
	for (int i = 0; i <= 9; i++) {
		string a;
		a += (i + '0');
		int sum = i;
		for (int i = 0; i < 17; i++) {
			a += '9';
			sum += 9;
			if (stoll(a) <= n) {
				if (sum > mx) {
					mx = sum;
					an = stoll(a);
				}
			}
		}
	}
	string s2 = to_string(an);
	for (int i = 0; i < s2.size(); i++) {
		string s = s2;
		if (s[0] == '9') {
			s = "1" + s;
			s[i + 1]--;
		} else {
			s[0]++;
			s[i]--;
		}
		int x = stoll(s);
		if (x <= n)
			an = x;
	}
	cout << an;
}