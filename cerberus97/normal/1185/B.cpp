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

bool solve(string s, string t);
vector<pair<char, int>> get_rep(string s);

int main() {
	fast_cin();
	int tc; cin >> tc;
	while (tc--) {
		string s, t;
		cin >> s >> t;
		if (solve(s, t)) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}

bool solve(string s, string t) {
	auto r1 = get_rep(s);	
	auto r2 = get_rep(t);
	if (r1.size() != r2.size()) {
		return false;
	}
	int n = r1.size();
	for (int i = 0; i < n; ++i) {
		if (r1[i].first != r2[i].first or r1[i].second > r2[i].second) {
			return false;
		}
	}
	return true;
}

vector<pair<char, int>> get_rep(string s) {
	vector<pair<char, int>> ans;
	int n = s.length();
	ans.pb({s[0], 1});
	for (int i = 1; i < n; ++i) {
		if (s[i] == ans.back().first) {
			++ans.back().second;
		} else {
			ans.pb({s[i], 1});
		}
	}
	return ans;
}