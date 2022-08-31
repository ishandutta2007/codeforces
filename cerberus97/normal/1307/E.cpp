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

const int N = 1e5 + 10, mod = 1e9 + 7;

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	vector<int> s(n);
	vector<int> cnt_lt(n + 1, 0), cnt_rt(n + 1, 0);
	for (auto& i : s) {
		cin >> i;
		++cnt_rt[i];
	}
	vector<vector<int>> at(n + 1);
	for (int i = 0; i < m; ++i) {
		int f, h;
		cin >> f >> h;
		at[f].pb(h);
	}
	for (int i = 1; i <= n; ++i) {
		sort(at[i].begin(), at[i].end());
	}
	int ans = -1; ll ways = 1;
	for (int i = 0; i <= n; ++i) {
		int cand = 0; ll ways_here = 1;
		int h_need = 0;
		for (int j = 0; j <= i - 1; ++j) {
			h_need += (s[j] == s[i - 1]);
		}
		for (int f = 1; f <= n; ++f) {
			int c1 = cnt_lt[f], c2 = cnt_rt[f];
			if (i >= 1 and f == s[i - 1]) {
				auto it = lower_bound(at[f].begin(), at[f].end(), h_need);
				if (it == at[f].end() or *it != h_need) {
					cand = -1;
					break;
				}
				int cnt = 0;
				for (auto& h : at[f]) {
					cnt += (h != h_need and h <= c2);
				}
				cand += 1 + (cnt > 0);
				ways_here *= max(1, cnt);
				ways_here %= mod;
				continue;
			}
			if (c1 > c2) {
				swap(c1, c2);
			}
			if (at[f].empty()) {
				continue;
			} else {
				int cnt1 = 0, cnt2 = 0;
				for (auto& h : at[f]) {
					cnt1 += (h <= c1);
					cnt2 += (h <= c2);
				}
				ll w1 = cnt2 + cnt1, w2 = ll(cnt1) * cnt2 - cnt1;
				if (w2) {
					cand += 2;
					ways_here *= w2;
				} else if (w1) {
					cand += 1;
					ways_here *= w1;
				}
				ways_here %= mod;
			}
		}
		if (cand > ans) {
			ans = cand;
			ways = ways_here;
			// if (cand == 0) {
			// 	cout << i << ' ' << ways_here << endl;
			// }
		} else if (cand == ans) {
			ways += ways_here;
			ways %= mod;
			// if (cand == 0) {
			// 	cout << i << ' ' << ways_here << endl;
			// }
		}
		if (i < n) {
			--cnt_rt[s[i]];
			++cnt_lt[s[i]];
		}
	}
	cout << ans << ' ' << ways << '\n';
}