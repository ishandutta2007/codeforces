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

	int mex(vector<int>& cnt);

	int main() {
		fast_cin();
		int t; cin >> t;
		while (t--) {
			int n; cin >> n;
			vector<int> a(n), cnt(n + 1, 0);
			for (auto& i : a) {
				cin >> i;
				++cnt[i];
			}
			vector<int> ops;
			while (!is_sorted(a.begin(), a.end())) {
				int m = mex(cnt);
				if (m < n) {
					ops.pb(m);
					--cnt[a[m]];
					a[m] = m;
					++cnt[a[m]];
				} else {
					for (int i = 0; i < n; ++i) {
						if (a[i] != i) {
							ops.pb(i);
							--cnt[a[i]];
							a[i] = n;
							++cnt[a[i]];
							break;
						}
					}
				}
			}
			cout << ops.size() << '\n';
			for (auto& op : ops) {
				cout << op + 1 << ' ';
			}
			cout << '\n';
		}
	}

	int mex(vector<int>& cnt) {
		int n = cnt.size() - 1;
		for (int i = 0; i <= n; ++i) {
			if (!cnt[i]) {
				return i;
			}
		}
		return -1;
	}