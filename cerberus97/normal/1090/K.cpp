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

struct S {
	int i;
	string s;
	bool operator<(const S &o) const {
		if (i != o.i) {
			return i < o.i;
		}
		return s < o.s;
	}
};

map<S, int> mp;
vector<int> ans[N];

int main() {
	fast_cin();
	int n; cin >> n;
	int id = 0;
	for (int i = 1; i <= n; ++i) {
		string s, t;
		cin >> s >> t;
		int mask = 0;
		for (auto &c : t) {
			mask |= (1 << (c - 'a'));
		}
		int p = -1;
		int len = s.length();
		for (int j = len - 1; j >= 0; --j) {
			int c = (s[j] - 'a');
			if (!(mask & (1 << c))) {
				p = j;
				break;
			}
		}
		s = s.substr(0, p + 1);
		if (!mp[{mask, s}]) {
			mp[{mask, s}] = ++id;
		}
		ans[mp[{mask, s}]].pb(i);
	}
	cout << id << '\n';
	for (int i = 1; i <= id; ++i) {
		cout << ans[i].size() << ' ';
		for (auto &j : ans[i]) {
			cout << j << ' ';
		}
		cout << '\n';
	}
}