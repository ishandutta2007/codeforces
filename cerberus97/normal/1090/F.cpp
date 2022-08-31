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
const int inf = 1e9 + 42;

void solve(int l, int r);
ll query(vector<int> indices);

map<vector<int>, int> mp;
int ans[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; i += 5) {
		if (i + 4 > n) {
			i = n - 4;
		}
		solve(i, i + 4);
	}
	cout << "! ";
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}

void solve(int l, int r) {
	vector<int> v;
	for (int i = l; i <= r; ++i) {
		v.pb(i);
	}
	do {
		vector<ll> cand(5);
		ll a_02 = query({v[0], v[1], v[2]});
		ll a_04 = query({v[0], v[2], v[4]});
		ll a_24 = query({v[2], v[3], v[4]});
		cand[0] = (a_02 + a_04 - a_24) / 2;
		cand[2] = a_02 - cand[0];
		cand[4] = a_04 - cand[0];
		cand[1] = query({v[1], v[2], v[4]}) - cand[4];
		cand[3] = query({v[0], v[1], v[3]}) - cand[0];
		if (!is_sorted(cand.begin(), cand.end())) {
			continue;
		}
		bool ok = true;
		for (int i = 0; i < 5; ++i) {
			for (int j = i + 1; j < 5; ++j) {
				for (int k = j + 1; k < 5; ++k) {
					if (query({v[i], v[j], v[k]}) != cand[i] + cand[k]) {
						ok = false;
					}
				}
			}
		}
		if (ok) {
			for (int i = 0; i < 5; ++i) {
				ans[v[i]] = cand[i];
			}
			return;
		}
	} while (next_permutation(v.begin(), v.end()));
}

ll query(vector<int> indices) {
	sort(indices.begin(), indices.end());
	if (mp.find(indices) != mp.end()) {
		return mp[indices];
	}
	cout << "? ";
	for (auto &i : indices) {
		cout << i << ' ';
	}
	cout << endl;
	cin >> mp[indices];
	return mp[indices];
}