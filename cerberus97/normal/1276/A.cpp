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

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		vector<int> pos;
		int n = s.length();
		string one = "one", two = "two";
		for (int i = 0; i + 2 < n; ++i) {
			if (s.substr(i, 3) == one) {
				pos.pb(i + 1);
			} else if (s.substr(i, 3) == two) {
				if (i + 3 < n and s[i + 3] == 'o') {
					pos.pb(i + 1);
				} else {
					pos.pb(i + 2);
					i = i + 2;
				}
			}
		}
		cout << pos.size() << '\n';
		for (auto& p : pos) {
			cout << p + 1 << ' ';
		}
		cout << '\n';
	}
}