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
typedef vector<ll> row;
typedef vector<row> matrix;

const int N = 1e3 + 10, C = 10, A = 1e9 + 10, LOG = log2(A) + 5;
const int mod = 998244353;

int a[N], f[C][C];
vector<pii> colored[N];
ll ways[N][C], dp[N][C];

vector<int> get_state(int s_id);
int get_id(vector<int> state);
matrix mul(const matrix &a, const matrix &b);
void fast_mul(matrix &a, vector<matrix> &t_pow, ll e);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int q; cin >> q;
	for (int i = 0; i < q; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		colored[x].pb({y, c});
	}
	for (int i = 1; i <= 3; ++i) {
		for (int j = 1; j <= 3; ++j) {
			cin >> f[i][j];
		}
	}
	int states = 64;
	matrix transition(states, row(states, 0));
	vector<matrix> fixed_transition(4, transition);
	for (int i = 0; i < states; ++i) {
		assert(get_id(get_state(i)) == i);
		vector<int> state = get_state(i);
		for (int c = 1; c <= 3; ++c) {
			vector<int> n_state(3);
			n_state[0] = state[1];
			n_state[1] = state[2];
			set<int> seen;
			for (int j = 1; j <= 3; ++j) {
				if (f[c][j] == 1) {
					seen.insert(state[3 - j]);
				}
			}
			n_state[2] = 0;
			while (seen.count(n_state[2])) {
				++n_state[2];
			}
			++transition[i][get_id(n_state)];
			++fixed_transition[c][i][get_id(n_state)];
		}
	}
	vector<matrix> t_pow(LOG);
	t_pow[0] = transition;
	for (int i = 1; i < LOG; ++i) {
		t_pow[i] = mul(t_pow[i - 1], t_pow[i - 1]);
	}
	matrix start(1, row(states, 0));
	start[0][get_id({1, 2, 3})] = 1;
	for (int i = 1; i <= n; ++i) {
		sort(colored[i].begin(), colored[i].end());
		int cur = 0;
		matrix m = start;
		for (auto &p : colored[i]) {
			int y = p.first, c = p.second;
			fast_mul(m, t_pow, y - cur - 1);
			m = mul(m, fixed_transition[c]);
			cur = y;
		}
		fast_mul(m, t_pow, a[i] - cur);
		for (int id = 0; id < states; ++id) {
			int grundy = get_state(id)[2];
			ways[i][grundy] += m[0][id];
			ways[i][grundy] %= mod;
		}
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 3; ++j) {
			for (int k = 0; k <= 3; ++k) {
				dp[i][k] += dp[i - 1][j] * ways[i][j ^ k];
				dp[i][k] %= mod;
			}
		}
	}
	cout << dp[n][0] << '\n';
}

vector<int> get_state(int id) {
	vector<int> state(3);
	for (auto &i : state) {
		i = id & 0b11;
		id >>= 2;
	}
	reverse(state.begin(), state.end());
	return state;
}

int get_id(vector<int> state) {
	int id = 0;
	for (auto &i : state) {
		id = (id << 2) | i;	
	}
	return id;
}

matrix mul(const matrix &a, const matrix &b) {
	int n = a.size(), m = a[0].size(), p = b[0].size();
	assert(m == b.size());
	matrix ans(n, row(p, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < p; ++j) {
			for (int k = 0; k < m; ++k) {
				ans[i][j] += a[i][k] * b[k][j];
				ans[i][j] %= mod;
			}
		}
	}
	return ans;
}

void fast_mul(matrix &a, vector<matrix> &t_pow, ll e) {
	for (int j = 0; j < LOG; ++j) {
		if ((e >> j) & 1) {
			a = mul(a, t_pow[j]);
		}
	}
}