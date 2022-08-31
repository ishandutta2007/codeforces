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

struct state {
	vector<vector<int>> g;
	state() : g(5, vector<int>(3, 0)) {}
	bool operator<(const state& o) const {
		return g < o.g;
	}
};

int get_grundy(vector<state>& states, ll i, int j, int p1, int p2);
state transition(state& s, vector<int>& m);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; vector<int> m(3);
		cin >> n >> m[0] >> m[1] >> m[2];
		vector<ll> a(n);
		for (auto& i : a) {
			cin >> i;
		}
		state start;
		vector<state> states = {start};
		map<state, int> mp = {{start, 0}};
		int p1 = -1, p2 = -1;
		for (int p = 1; ; ++p) {
			states.pb(transition(states.back(), m));
			if (mp.count(states[p])) {
				p1 = mp[states[p]];
				p2 = p;
				break;
			}
			mp[states[p]] = p;
		}
		ll g = 0;
		for (auto i : a) {
			g ^= get_grundy(states, i, 0, p1, p2);
		}
		int cnt = 0;
		for (auto i : a) {
			int cur = get_grundy(states, i, 0, p1, p2);
			for (int j = 0; j < 3; ++j) {
				int ncur = get_grundy(states, max(0ll, i - m[j]), j, p1, p2);
				if ((g ^ cur ^ ncur) == 0) {
					++cnt;
				}
			}
		}
		cout << cnt << '\n';
	}
}

int get_grundy(vector<state>& states, ll i, int j, int p1, int p2) {
	if (i > p2) {
		i = ((i - p1) % (p2 - p1)) + p1;
	}
	return states[i].g[0][j];
}

state transition(state& s, vector<int>& m) {
	state nxt;
	for (int i = 1; i < 5; ++i) {
		nxt.g[i] = s.g[i - 1];
	}
	for (int j = 0; j < 3; ++j) {
		set<int> seen;
		for (int mv = 0; mv < 3; ++mv) {
			if (j == mv and j != 0) {
				continue;
			}
			seen.insert(s.g[m[mv] - 1][mv]);
		}
		while (seen.count(nxt.g[0][j])) {
			++nxt.g[0][j];
		}
	}
	return nxt;
}