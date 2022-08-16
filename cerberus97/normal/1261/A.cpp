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
	int tc; cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		string s; cin >> s;
		string t;
		for (int i = 0; i < k - 1; ++i) {
			t += "()";
		}
		t += string(n / 2 - k + 1, '(');
		t += string(n / 2 - k + 1, ')');
		vector<pii> ans;
		for (int i = 0; i < n - 1; ++i) {
			if (s[i] != t[i]) {
				for (int j = i + 1; j < n; ++j) {
					if (s[j] == t[i]) {
						reverse(s.begin() + i, s.begin() + j + 1);
						ans.pb({i + 1, j + 1});
						break;
					}
				}
			}
		}
		cout << ans.size() << '\n';
		for (auto &p : ans) {
			cout << p.first << ' ' << p.second << '\n';
		}
	}
}