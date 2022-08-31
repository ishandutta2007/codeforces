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

const int N = 1e3 + 10;

bool uses[N][N];
int a[N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	vector<pii> cur = {{1, n + 1}};
	for (int i = 1; i <= n; ++i) {
		sort(cur.begin(), cur.end(), [&] (pii p1, pii p2) {
			return p1.second - p1.first < p2.second - p2.first;
		});
		int left = a[i];
		auto x = cur.back();
		cur.pop_back();
		int y = min(a[i], x.second - x.first);
		left -= y;
		for (int j = 0; j < y; ++j) {
			uses[i][x.first + j] = true;
		}
		vector<pii> nxt;
		nxt.pb({x.first, x.first + y - 1});
		nxt.pb({x.first + y, x.second});
		for (auto &temp : cur) {
			int have = temp.second - temp.first + 1;
			int take = min(have, left);
			left -= take;
			for (int j = 0; j < take; ++j) {
				uses[i][temp.first + j] = true;
			}
			if (take == have or take == 0) {
				nxt.pb(temp);
			} else {
				nxt.pb({temp.first, temp.first + take - 1});
				nxt.pb({temp.first + take, temp.second});
			}
		}
		cur = nxt;
	}
	cout << n + 1 << endl;
	for (int op = 1; op <= n + 1; ++op) {
		for (int i = 1; i <= n; ++i) {
			cout << uses[i][op];
		}
		cout << '\n';
	}
}