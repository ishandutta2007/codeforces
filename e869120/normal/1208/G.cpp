#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

const int MAX_N = (1 << 20);
long long n, k, c[MAX_N], d[MAX_N];
vector<long long> G[MAX_N];

void init() {
	for (int i = 2; i <= n; i++) d[i] = i;
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (d[j] % i == 0) {
				G[j].push_back(i);
				while (d[j] % i == 0) d[j] /= i;
			}
		}
	}
	for (int i = 3; i <= n; i++) {
		c[i] = i;
		for (int j = 0; j < G[i].size(); j++) {
			c[i] *= (G[i][j] - 1);
			c[i] /= G[i][j];
		}
	}
}

int main() {
	cin >> n >> k;
	if (k == 1) {
		cout << "3" << endl;
		return 0;
	}

	init();
	sort(c + 3, c + n + 1);
	long long rem = 0;
	for (int i = 0; i < k; i++) rem += c[3 + i];
	cout << rem + 2LL << endl;
	return 0;
}