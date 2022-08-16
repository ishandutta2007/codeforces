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

vector<int> compute_z(string s);

int main() {
	fast_cin();
	int n; cin >> n;
	string ans = "";
	while (n--) {
		string s; cin >> s;
		int len = s.length(), p = max(0, int(ans.size()) - len);
		string test = s + "$" + ans.substr(p, len);
		vector<int> z = compute_z(test);
		int start = 0;
		for (int i = len + 1; i < test.size(); ++i) {
			if (z[i] == (int(test.size()) - i)) {
				start = z[i];
				break;	
			}
		}
		ans += s.substr(start, len);
	}
	cout << ans << '\n';
}

vector<int> compute_z(string s) {
	int n = s.length();
	vector<int> z(n, 0);
	int len = 0;
	for (int i = 1; i < n; ++i) {
		if (len >= 1) {
			len = min(z[1], len - 1);
		}
		while (i + len < n and s[i + len] == s[len]) {
			++len;
		}
		z[i] = len;
	}
	return z;
}