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
	int t; cin >> t;
	while (t--) {
		int n; string s;
		cin >> n >> s;
		vector<int> t2;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '2') {
				t2.pb(i);
			}
		}
		if (t2.size() >= 1 and t2.size() <= 2) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		vector<string> ans(n, string(n, '='));
		for (int i = 0; i < n; ++i) {
			ans[i][i] = 'X';
		}
		int k = t2.size();
		for (int i = 0; i < k; ++i) {
			int p1 = t2[i];
			int p2 = t2[(i + 1) % k];
			ans[p1][p2] = '+';
			ans[p2][p1] = '-';
		}
		for (auto& row : ans) {
			cout << row << '\n';
		}
	}
}