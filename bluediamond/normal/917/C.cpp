// 387
#include <iostream>
#include <vector> 
#include <cassert> 
#include <functional> 
#include <algorithm> 
#include <map> 

bool home = true;
using namespace std;

typedef long long ll;

const ll inf = (ll)1e18 + 7;

class Matrix {
public:
	int n;
	int m;
	vector<vector<ll>> a;
	Matrix(int n, int m, ll init) :
		n(n),
		m(m),
		a(n, vector<ll>(m, init)) {
	}

};

Matrix operator * (Matrix a, Matrix b) {
	assert(a.m == b.n);
	Matrix c(a.n, b.m, inf);
	for (int i = 0; i < a.n; i++) {
		for (int j = 0; j < b.m; j++) {
			for (int k = 0; k < a.m; k++) {
				c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
			}
		}
	}
	return c;
}

Matrix operator ^ (Matrix a, int b) {
	assert(a.n == a.m);
	Matrix r(a.n, a.m, 0);
	for (int i = 0; i < a.n; i++) {
		r.a[i][i] = 1;
	}
	while (b) {
		if (b & 1) {
			r = r * a;
		}
		a = a * a;
		b /= 2;
	}
	return r;
}

int main() {

#ifdef ONLINE_JUDGE
	home = 0;
#endif
	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	int x, n, k, q;
	cin >> x >> k >> n >> q;
	vector<int> cost_jump(k + 1, 0);
	for (int i = 1; i <= k; i++) {
		cin >> cost_jump[i];
	}
	vector<int> positions;
	map<int, int> energyAt;
	for (int i = 1; i <= q; i++) {
		int p, e;
		cin >> p >> e;
		energyAt[p] = e;
		positions.push_back(p);
	}



	function<Matrix(int)> getMult = [&](int nxt) {
		Matrix mult((1 << k), (1 << k), inf);
		for (int mask = 0; mask < (1 << k); mask++) {
			int nmask = mask / 2;
			if (mask & (1 << 0)) {
				for (int pos = 0; pos < k; pos++) {
					if (!(nmask & (1 << pos))) {
						mult.a[mask][nmask + (1 << pos)] = cost_jump[pos + 1] + (energyAt.count(nxt + pos) ? energyAt[nxt + pos] : 0);
					}
				}
			}
			else {
				mult.a[mask][nmask] = 0;
			}
		}
		return mult;
	};

	n = n - x + 1;

	vector<Matrix> boring;
	boring.push_back(getMult((int)2e8));
	for (int i = 1; (1 << i) <= n; i++) {
		boring.push_back(boring[i - 1] * boring[i - 1]);
	}

	sort(positions.begin(), positions.end());

	Matrix state(1, (1 << k), inf);
	state.a[0][(1 << x) - 1] = 0;

	int p = 0;

	int manual = 0;
	int current = 2;
	while (current <= n) {

		while (p < (int)positions.size() && current > positions[p]) {
			p++;
		}

		if (p < (int)positions.size() && current < positions[p] - k) {
			int delta = positions[p] - k - current;
			assert(delta > 0);
			for (int bit = 0; (1 << bit) <= delta; bit++) {
				if (delta & (1 << bit)) {
					state = state * boring[bit];
				}
			}
			current += delta;

			continue;
		}

		if (p >= (int)positions.size()) {
			int delta = n - current + 1;
			assert(delta > 0);
			for (int bit = 0; (1 << bit) <= delta; bit++) {
				if (delta & (1 << bit)) {
					state = state * boring[bit];
				}
			}
			current += delta;

			continue;
		}

		state = state * getMult(current);

		current++;
	}

	cout << state.a[0][(1 << x) - 1] << "\n";
}