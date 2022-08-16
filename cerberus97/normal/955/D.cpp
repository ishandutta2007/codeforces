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

const int N = 5e5 + 10, inf = 1e9;

vector<int> compute_z(string s);
vector<int> solve(string s, string t, int k);

int main() {
	fast_cin();
	int n, m, k;
	string s, t;
	cin >> n >> m >> k >> s >> t;
	vector<int> lpos = solve(s, t, k);
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	vector<int> rpos = solve(s, t, k);
	for (auto &i : rpos) {
		i = n - i - 1;
	}
	// for (auto &i : lpos) {
	// 	cout << i << ' ';
	// }
	// cout << endl;
	// for (auto &i : rpos) {
	// 	cout << i << ' ';
	// }
	// cout << endl;
	for (int x = 1; x < m; ++x) {
		if (x <= k and m - x <= k) {
			if (lpos[x] + x - 1 < rpos[m - x] - m + x + 1) {
				cout << "Yes\n";
				cout << lpos[x] + x - k + 1 << ' ' << rpos[m - x] - m + x + 2 << '\n';
				return 0;
			}
		}
	}
	if (m <= k and lpos[m] < n) {
		cout << "Yes\n";
		int p1 = max(0, lpos[m] + m - 2 * k);
		cout << p1 + 1 << ' ' << p1 + k + 1 << endl;
	} else {
		cout << "No\n";
	}
}

vector<int> solve(string s, string t, int k) {
	int n = s.length(), m = t.length();
	vector<int> z_full = compute_z(t + '$' + s);
	vector<pii> z(n);
	for (int i = 0; i < n; ++i) {
		z[i] = {z_full[i + m + 1], i};
	}
	// for (auto &j : z) {
	// 	cout << j.first << ' ';
	// }
	// cout << endl;
	sort(z.begin(), z.end(), greater<pii>());
	int z_idx = 0;
	vector<int> pos(n + 1, inf);
	set<int> st = {inf};
	for (int x = n; x >= 0; --x) {
		while (z_idx < n and z[z_idx].first >= x) {
			st.insert(z[z_idx].second);
			++z_idx;
		}
		pos[x] = *(st.lower_bound(k - x));
	}
	if (z[0].first >= m and m <= k) {
		pos[m] = z[0].second;
	}
	return pos;
}

vector<int> compute_z(string s) {
	int n = s.length();
	vector<int> z(n, 0);
	z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (r >= i) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n and s[i + z[i]] == s[z[i]]) {
			++z[i];
		}
		if (i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
	}
	return z;
}