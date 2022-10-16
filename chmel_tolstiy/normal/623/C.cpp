#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

long long SQR(long long x) {
	return x * x;
}

void solve() {
	int n;
	cin >> n;
	vector<pii> p(n);

	for (int i = 0; i < n; ++i) 
		cin >> p[i].first >> p[i].second;

	long long ans = 4 * 1000000000LL * 1000000000LL + 100;

	for (int it = 0; it < 4; ++it) {
		if (it & 1)
			for (int i = 0; i < n; ++i) 
				p[i].first *= -1;

		if (it & 2)
			for (int i = 0; i < n; ++i) 
				swap(p[i].first, p[i].second);

		sort(p.begin(), p.end());

		ans = min(ans, SQR(p[0].first - p[n - 1].first));

		vector<int> MYL(n + 1);
		vector<int> mYL(n + 1);
		for (int i = 0; i < n; i++) {
			MYL[i + 1] = max(MYL[i], +p[i].second);
			mYL[i + 1] = max(mYL[i], -p[i].second);
		}
		
		vector<int> mYR(n + 1);
		vector<int> MYR(n + 1);
		for (int i = n - 1; i >= 0; --i) {
			mYR[i] = max(mYR[i + 1], -p[i].second);
			MYR[i] = max(MYR[i + 1], +p[i].second);
		}

		long long L = 0;
		long long R = ans;

		while (L <= R) {
			long long M = (L + R) / 2;

			bool ok = false;

			int r = 0;
			while (r < n && p[r].first <= 0) 
				++r;

			for (int i = 0; i < n; ++i) {
				if (p[i].first > 0) 
					continue;

				while (-p[i].first < p[r].first) --r;

				while (r < n && -p[i].first >= p[r].first && SQR(p[r].first - p[i].first) <= M) 
					++r;

				long long mY = max(mYL[i], mYR[r]);
				long long MY = max(MYL[i], MYR[r]);

				if (SQR(max(mY, MY)) + SQR(p[i].first) <= M && SQR(mY + MY) <= M) {
					ok = true;
					break;
				}
			}

			if (ok) {
				ans = M;
				R = M - 1;
			} else {
				L = M + 1;
			}
		}	
	}

	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}