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

bool isPal(string s);

int main() {
	string s; cin >> s;
	int n = s.length();
	string ans = "";
	for (int len = n; len >= 0; --len) {
		for (int i = 0; i + len - 1 < n; ++i) {
			string t = s.substr(i, len);
			if (!isPal(t)) {
				cout << len;
				return 0;
			}
		}
	}
	cout << 0;
}

bool isPal(string s) {
	int n = s.length();
	if (!n) {
		return false;
	}
	for (int i = 0, j = n - 1; i < j; ++i, --j) {
		if (s[i] != s[j]) {
			return false;
		}
	}
	return true;
}