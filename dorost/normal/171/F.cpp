/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

int32_t main() {
	int n, x = 1;
	cin >> n;
	for (int i = 2; ; i++) {
		if (!is_prime(i))
			continue;
		string s = to_string(i);
		reverse(s.begin(), s.end());
		int b = stoi(s);
		if (b != i && is_prime(b)) {
			if (x == n) {
				cout << i;
				return 0;
			} else {
				x++;
			}
		}
	}
}