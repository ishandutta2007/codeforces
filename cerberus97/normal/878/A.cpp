/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e5 + 10;

char c[N];
int a[N];

bool solve(int n, int b, bool val);

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i] >> a[i];
	}

	int and1 = 1023, or2 = 0, xor1 = 0;
	for (int bit = 0; bit < 10; ++bit) {
		bool v0 = solve(n, bit, 0);
		bool v1 = solve(n, bit, 1);
		// if (bit == 1) {
		// 	cout << v0 << ' ' << v1 << endl;
		// }
		if (!v0) {
			if (!v1) {
				// cout << bit << endl;
				and1 = and1 & (1023 - (1 << bit));
			} else {
				// or1 = or1 & (1023 - (1 << bit));
			}
		} else if (!v1) {
			xor1 |= (1 << bit);
		} else {
			or2 |= (1 << bit);
		}
	}

	cout << 3 << endl;
	cout << "& " << and1 << endl;
	// cout << "| " << or1 << endl;
	cout << "| " << or2 << endl;
	cout << "^ " << xor1 << endl;
}

bool solve(int n, int b, bool val) {
	for (int i = 1; i <= n; ++i) {
		if (c[i] == '&') {
			val = val and !!(a[i] & (1 << b));
		} else if (c[i] == '|') {
			val = val or !!(a[i] & (1 << b));
		} else {
			val = val xor !!(a[i] & (1 << b));
		}

		// if (b == 1) {
		// 	cout << i << ' ' << c[i] << ' ' << a[i] << ' ' << val << endl;
		// }
	}
	return val;
}