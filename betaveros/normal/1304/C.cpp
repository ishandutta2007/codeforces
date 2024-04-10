// very very slow dp:
// dp[t][x] = is it possible to have temperature x at time t and satisfy all customers up to t
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 108;
int n, initialTemperature;
int times[N], los[N], his[N];

bool solve() {
	int lot = initialTemperature;
	int hit = initialTemperature;
	int lastTime = 0;
	for (int i = 0; i < n; i++) {
		int elapsed = times[i] - lastTime;

		lot -= elapsed;
		hit += elapsed;

		lot = max(lot, los[i]);
		hit = min(hit, his[i]);

		if (lot > hit) {
			return false;
		}

		lastTime = times[i];
	}

	return true;
}

void testCase() {
	cin >> n >> initialTemperature;
	for (int i = 0; i < n; i++) {
		cin >> times[i]
			>> los[i]
			>> his[i];
	}

	if (solve()) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	int tcn;
	cin >> tcn;
	for (int i = 0; i < tcn; i++) {
		testCase();
	}
}