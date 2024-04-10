#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int inf = 1010101010;
vector<pii> V[666];
int P[666], D[666], C[666];
int n, m;

void tc() {
	int i, a, b, c, j, k, l;
	cin >> n >> m;
	for (i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		V[a].emplace_back(b, c);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			D[j] = inf; C[j] = 0;
		}
		D[i] = 0;

		for (j = 1; j <= n; j++) {
			k = min_element(D, D + n) - D;

			assert(D[k] < inf && !C[k]);

			if (k != i) {
				l = (k + 1) % n;
				if (!C[l]) {
					D[l] = min(D[l], D[k] + 1);
				}

				if (l == i) {
					l = (l + 1) % n;
					if (!C[l]) {
						D[l] = min(D[l], D[k] + 2);
					}
				}
			}
			for (auto &[b, c]: V[k]) {
				l = (b + D[k]) % n;
				if (!C[l]) {
					D[l] = min(D[l], D[k] + c);
				}

				if (l == i) {
					l = (l + 1) % n;
					if (!C[l]) {
						D[l] = min(D[l], D[k] + c + 1);
					}
				}
			}

			P[k] = D[k]; C[k] = 1; D[k] = inf;
		}
		for (j = 0; j < n; j++) {
			cout << P[j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; ) tc();

	return 0;
}