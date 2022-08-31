/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e3 + 10, F = 10, inf = 1e9;

struct state {
	int n, f, s[4];
	bool operator<(const state &other) const {
		if (n != other.n) {
			return n < other.n;
		} else if (f != other.f) {
			return f < other.f;
		} else {
			for (int i = 0; i < 4; ++i) {
				if (s[i] != other.s[i]) {
					return s[i] < other.s[i];
				}
			}
			return false;
		}
	}
};

int a[N], b[N];
map<state, int> dp;
priority_queue<pair<int, state>> pq;

inline void update(state &s, int val);

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
	}
	state st = {0, 1, {0, 0, 0, 0}};
	dp[st] = 0;
	pq.push({0, st});
	while (!pq.empty()) {
		int val = -pq.top().first;
		st = pq.top().second;
		pq.pop();
		if (dp[st] != val) {
			continue;
		}
		state nxt = st;
		for (int i = 0; i < 4; ++i) {
			if (nxt.s[i]) {
				nxt.f = nxt.s[i];
				update(nxt, val + abs(st.f - nxt.f));
			}
		}
		if (nxt.n < n) {
			nxt.f = a[nxt.n + 1];
			update(nxt, val + abs(st.f - nxt.f));
		}
		nxt.f = st.f;
		int cost = 0;
		for (int i = 0; i < 4; ++i) {
			if (nxt.f == nxt.s[i]) {
				nxt.s[i] = 0;
				++cost;
			}
			if (!nxt.s[i] and nxt.n < n and a[nxt.n + 1] == nxt.f) {
				nxt.s[i] = b[nxt.n + 1];
				++cost;
				++nxt.n;
			}
		}
		sort(nxt.s, nxt.s + 4);
		update(nxt, val + cost);
	}
	int best = inf;
	st = {n, 0, {0, 0, 0, 0}};
	for (st.f = 1; st.f <= 9; ++st.f) {
		if (dp.find(st) != dp.end()) {
			best = min(best, dp[st]);
		}
	}
	cout << best << endl;
	// cout << dp.size() << endl << ctr;
}

inline void update(state &s, int val) {
	if (dp.find(s) == dp.end() or dp[s] > val) {
		dp[s] = val;
		pq.push({-val, s});
	}
}