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
	int n, k; string s;
	cin >> n >> k >> s;
	vector<bool> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		a[i] = (s[i - 1] == 'R');
	}
	vector<vector<int>> moves;
	int tot_moves = 0;
	vector<int> cur;
	for (int i = 1; i < n; ++i) {
		if (a[i] and !a[i + 1]) {
			cur.pb(i);
		}
	}
	while (!cur.empty()) {
		tot_moves += cur.size();
		moves.pb(cur);
		cur.clear();
		for (auto& i : moves.back()) {
			swap(a[i], a[i + 1]);
			if (i > 1 and a[i - 1]) {
				cur.pb(i - 1);
			}
			if (i + 2 <= n and !a[i + 2]) {
				cur.pb(i + 1);
			}
		}
	}
	if (k < moves.size() or k > tot_moves) {
		cout << -1 << '\n';
	} else {
		reverse(moves.begin(), moves.end());
		while (k) {
			if (moves.back().size() > 1 and moves.size() < k) {
				cout << 1 << ' ' << moves.back().back() << '\n';
				moves.back().pop_back();
			} else {
				cout << moves.back().size() << ' ';
				for (auto& i : moves.back()) {
					cout << i << ' ';
				}
				cout << '\n';
				moves.pop_back();
			}
			--k;
		}
	}
}