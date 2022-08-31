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

multiset<string> query(int l, int r);

int main() {
	fast_cin();
	int n; cin >> n;
	multiset<string> q_all = query(1, n);
	multiset<string> q_without_first = query(2, n);
	for (auto& s : q_without_first) {
		q_all.erase(q_all.find(s));
	}
	vector<string> first;
	for (auto& s : q_all) {
		first.pb(s);
	}
	sort(first.begin(), first.end(), [&](const string& s1, const string& s2) {
		return s1.length() < s2.length();
	});
	string ans = "";
	multiset<char> used;
	for (auto& s : first) {
		for (auto& c : s) {
			if (used.find(c) == used.end()) {
				ans += c;
			} else {
				used.erase(used.find(c));
			}
		}
		for (auto& c : ans) {
			used.insert(c);
		}
	}
	cout << "! " << ans << endl;
}

multiset<string> query(int l, int r) {
	multiset<string> ans;
	int sz = (r - l + 1), cnt = (sz * (sz + 1)) / 2;
	if (cnt == 0) {
		return ans;
	}
	cout << "? " << l << ' ' << r << endl;
	for (int i = 0; i < cnt; ++i) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		ans.insert(s);
	}
	return ans;
}