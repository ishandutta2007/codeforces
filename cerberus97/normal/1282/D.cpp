/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

int query(string s);

int main() {
	fast_cin();
	int n = query("a") + 1;
	if (n > 300) {
		cout << string(n - 1, 'b');
		return 0;
	}
	string s = string(n, 'a');
	int num_b = query(s), found = 0;
	if (num_b == n) {
		query(string(n - 1, 'b'));
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		s[i] = 'b';
		if (query(s) == num_b - 1 - found) {
			++found;
		} else {
			s[i] = 'a';
		}
	}
}

int query(string s) {
	cout << s << endl;
	int ans; cin >> ans;
	if (ans == -1) {
		exit(1);
	} else if (ans == 0) {
		exit(0);
	}
	return ans;
}