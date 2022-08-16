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
		string temp[2];
		for (auto &c : s) {
			temp[c % 2] += c;
		}
		string ans;
		int s0 = temp[0].size(), s1 = temp[1].size();
		int p0 = 0, p1 = 0;
		while (p0 < s0 or p1 < s1) {
			if (p0 == s0) {
				ans += temp[1][p1++];
			} else if (p1 == s1) {
				ans += temp[0][p0++];
			} else if (temp[0][p0] < temp[1][p1]) {
				ans += temp[0][p0++];
			} else {
				ans += temp[1][p1++];
			}
		}
		cout << ans << '\n';
	}
}