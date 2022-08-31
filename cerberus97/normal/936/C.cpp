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

const int N = 1e5 + 10;

int ctr[26];
inline void apply(string &s, int x);

int main() {
	int n; string s, t;
	cin >> n >> s >> t;
	string temp = s;
	for (auto &i : s) {
		ctr[i - 'a']++;
	}
	for (auto &i : t) {
		ctr[i - 'a']--;
	}
	for (int i = 0; i < 26; ++i) {
		if (ctr[i] != 0) {
			cout << -1;
			return 0;
		}
	}
	int d = 0;
	cout << 3 * n << endl;
	while (d < n) {
		char c = t[n - d - 1];
		int p = d;
		while (s[p] != c) {
			++p;
		}
		// cout << d << ' ' << p << endl;
		cout << n << ' ' << p << ' ' << 1 << ' ';
		apply(s, n);
		// cout << s << ' ' << temp << endl;
		apply(s, p);
		apply(s, 1);
		// cout << s << endl;
		// cout << s << ' ' << s << endl;
		// for (int i = 1; i <= p; ++i) {
		// 	s[i] = s[i - 1];
		// }
		// s[0] = c;
		// for (int i = p + 1, j = n - 1; i < j; ++i, --j) {
		// 	swap(s[i], s[j]);
		// }
		++d;
	}
	// cout << s << endl;
}

inline void apply(string &s, int x) {
	string t = s;
	int j = 0, n = s.length();
	for (int i = n - 1; i >= n - x; --i) {
		t[j++] = s[i];
	}
	for (int i = 0; i < n - x; ++i) {
		t[j++] = s[i];
	}
	s = t;
}