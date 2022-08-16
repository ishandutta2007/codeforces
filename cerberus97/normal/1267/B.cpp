#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

void fail();

int main() {
	fast_cin();
	string s; cin >> s;
	int n = s.length();
	int l = 0, r = n - 1, cur = 0;
	while (l <= r) {
		if (s[l] != s[r]) {
			fail();
		}
		cur = (l == r ? 1 : 2);
		while (l + 1 < n and s[l] == s[l + 1]) {
			++l; ++cur;
		}
		while (r - 1 >= 0 and s[r] == s[r - 1]) {
			--r; ++cur;
		}
		if (l >= r) {
			if (cur >= 2) {
				cout << (l - r + 2) << '\n';
				return 0;
			} else {
				fail();
			}
		} else if (cur < 3) {
			fail();
		}
		++l; --r;
		cur = 0;
	}
}

void fail() {
	cout << 0 << '\n';
	exit(0);
}