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
#include <bitset>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10;

int a[N], b[N];

bool solve(int k, int n, int mask);

int main() {
	// cout << (sizeof(dp) + sizeof(mask)) / (1024.0 * 1024);
	fast_cin();
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		// cout << s << ": ";
		int n = s.length(), mask = 0;
		for (int i = 1; i <= n; ++i) {
			a[i] = s[i - 1] - '0';
			b[i] = a[i];
			mask ^= (1 << a[i]);
		}
		bool done = false;
		for (int i = n - 1; i >= 1; --i) {
			mask ^= (1 << a[i + 1]);
			if (solve(i, n, mask)) {
				done = true;
				break;
			}
		}
		if (!done) {
			if (n & 1) {
				for (int i = 0; i < n - 1; ++i) {
					cout << 9;
				}
				cout << '\n';
			} else if (a[1] > 1) {
				int d = a[1] - 1;
				cout << d;
				for (int i = 0; i < n - 2; ++i) {
					cout << 9;
				}
				cout << d << '\n';
			} else {
				for (int i = 0; i < n - 2; ++i) {
					cout << 9;
				}
				cout << '\n';
			}
		}
	}
}

bool solve(int k, int n, int mask) {
	for (int d = a[k + 1] - 1; d >= 0; --d) {
		b[k + 1] = d;
		int temp = mask ^ (1 << d), x = 9;
		bool ans = true;
		for (int j = k + 2; j <= n; ++j) {
			while (x >= 0 and __builtin_popcount(temp ^ (1 << x)) > n - j) {
				--x;
			}
			if (x < 0) {
				ans = false;
				break;
			}
			b[j] = x;
			temp ^= (1 << x);
		}
		if (ans and !temp) {
			for (int i = 1; i <= n; ++i) {
				cout << b[i];
			}
			cout << '\n';
			return true;
		}
	}
	return false;
}