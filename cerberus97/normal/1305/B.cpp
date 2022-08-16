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
#include <numeric>

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
	string s; cin >> s;
	vector<vector<int>> ans;
	while (true) {
		int n = s.length();
		string t1, t2;
		int l = 0, r = n - 1;
		vector<int> op;
		while (l <= r) {
			if (s[l] == ')') {
				t1 += ')';
				++l;
			} else if (s[r] == '(') {
				t2 += '(';
				--r;
			} else {
				op.pb(l + 1);
				op.pb(r + 1);
				++l;
				--r;
			}
		}
		if (op.empty()) {
			break;
		}
		sort(op.begin(), op.end());
		ans.pb(op);
		reverse(t2.begin(), t2.end());
		s = t1 + t2;
	}
	cout << ans.size() << '\n';
	for (auto& op : ans) {
		cout << op.size() << '\n';
		for (auto& i : op) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}