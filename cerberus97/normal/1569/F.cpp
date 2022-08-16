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

const int N = 15;
const char inf = 'z';

bool g[N][N];

vector<string> gen_cand_strings(int n);
void rec_gen(vector<string>& ans, string& cur, char c, int n);
vector<string> get_good_strings(vector<string>& cand, int n);
vector<string> gen_cand2_strings(int n);
void rec_gen2(vector<string>& ans, string& cur, char c, int n);
bool is_ok(string s, vector<string>& good, int n);
bool is_ok_rec(string& s, vector<string>& good, vector<bool>& done, int c, int n);

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u][v] = g[v][u] = 1;
	}
	vector<string> cand = gen_cand_strings(n);
	vector<string> good = get_good_strings(cand, n);
	sort(good.begin(), good.end());
	vector<string> cand2 = gen_cand2_strings(n);
	sort(cand2.begin(), cand2.end());
	cand2.erase(unique(cand2.begin(), cand2.end()), cand2.end());
	// for (auto& s : cand) {
	// 	for (auto& c : s) {
	// 		cout << int(c);
	// 	}
	// 	cout << endl;
	// }
	// cout << cand2.size() << endl;
	ll ans = 0;
	for (auto& s : cand2) {

		// for (auto& c : s) {
		// 	cout << int(c);
		// }
		// cout << ": ";

		if (is_ok(s, good, n)) {
			ll tmp = 1;
			int cnt = *max_element(s.begin(), s.end()) + 1;
			for (int i = 0; i < cnt; ++i) {
				tmp *= (k - i);
			}
			ans += tmp;
			// cout << "YES, is good\n";
		} else {
			// cout << "NO\n";
		}
	}
	cout << ans << '\n';
}

vector<string> gen_cand_strings(int n) {
	vector<string> ans;
	string base(n, inf);
	rec_gen(ans, base, 0, n);
	return ans;
}

void rec_gen(vector<string>& ans, string& cur, char c, int n) {
	for (int i = 0; i < n; ++i) {
		if (cur[i] == inf) {
			cur[i] = c;
			for (int j = i + 1; j < n; ++j) {
				if (cur[j] == inf) {
					cur[j] = c;
					rec_gen(ans, cur, c + 1, n);
					cur[j] = inf;
				}
			}
			cur[i] = inf;
			return;
		}
	}
	ans.pb(cur);
}

vector<string> get_good_strings(vector<string>& cand, int n) {
	vector<string> good;
	for (auto& s : cand) {
		vector<vector<int>> pos(n / 2);
		for (int i = 0; i < n; ++i) {
			pos[s[i]].pb(i);
		}
		int tot = (1 << (n / 2));
		vector<vector<int>> dp(tot, vector<int>(n / 2, 0));
		for (int i = 0; i < n / 2; ++i) {
			dp[(1 << i)][i] = g[pos[i][0]][pos[i][1]];
			// cout << (1 << i) << ' ' << i << ": dp true" << endl;
		}
		for (int mask = 0; mask < tot; ++mask) {
			if (__builtin_popcount(mask) < 2) {
				continue;
			}
			for (int i = 0; i < n / 2; ++i) {
				if (!((mask >> i) & 1)) {
					continue;
				}
				int u0 = pos[i][0], u1 = pos[i][1];
				int submask = mask - (1 << i);
				for (int j = 0; j < n / 2; ++j) {
					if (dp[submask][j]) {
						int v0 = pos[j][0], v1 = pos[j][1];
						if ((g[u0][v0] and g[u1][v1]) or (g[u0][v1] and g[u1][v0])) {
							dp[mask][i] = true;
							break;
						}
					}
				}
			}
		}
		for (int i = 0; i < n / 2; ++i) {
			if (dp[tot - 1][i]) {
				good.pb(s);
				break;
			}
		}
	}
	return good;
}

vector<string> gen_cand2_strings(int n) {
	vector<string> ans;
	string base(n, inf);
	rec_gen2(ans, base, 0, n);
	return ans;
}

void rec_gen2(vector<string>& ans, string& cur, char c, int n) {
	for (int i = 0; i < n; ++i) {
		if (cur[i] == inf) {
			for (int j = i + 1; j < n; ++j) {
				if (cur[j] == inf) {
					for (int nc = 0; nc <= c; ++nc) {
						cur[i] = cur[j] = nc;
						rec_gen2(ans, cur, max(int(c), nc + 1), n);
						cur[i] = cur[j] = inf;
					}
				}
			}
			return;
		}
	}
	ans.pb(cur);
}

bool is_ok(string s, vector<string>& good, int n) {
	vector<bool> done(n, 0);
	return is_ok_rec(s, good, done, 0, n);
}

bool is_ok_rec(string& s, vector<string>& good, vector<bool>& done, int c, int n) {
	if (c == n / 2) {
		auto it = lower_bound(good.begin(), good.end(), s);
		if (it != good.end() and *it == s) {
			return true;
		}
	} else {
		for (int i = 0; i < n; ++i) {
			if (!done[i]) {
				for (int j = i + 1; j < n; ++j) {
					if (!done[j] and s[i] == s[j]) {
						char tmp = s[i];
						s[i] = s[j] = c;
						done[i] = done[j] = true;
						if (is_ok_rec(s, good, done, c + 1, n)) {
							return true;
						}
						s[i] = s[j] = tmp;
						done[i] = done[j] = false;
					}
				}
				break;
			}
		}
	}
	return false;
}