#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

struct Rect {
	int x;
	int y;
	ll a;
};

bool operator < (Rect a, Rect b) {
	return a.x < b.x;
}

const int N = (int)1e6 + 7;
int n;
Rect rects[N];
ll dp[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> rects[i].x >> rects[i].y >> rects[i].a;
	}
	sort(rects + 1, rects + n + 1);

	vector<pair<ll, ll>> possible;
	possible.reserve(n);

	ll sol = 0;

	int P = 0;

	for (int i = 1; i <= n; i++) {
		ll x = rects[i].x, y = rects[i].y, a = rects[i].a;

		while (P + 1 < (int)possible.size() && possible[P + 1].first - possible[P + 1].second * y >= possible[P].first - possible[P].second * y) {
			P++;
		}

		if (!possible.empty()) {
			dp[i] = max(dp[i], possible[P].first - possible[P].second * y);
		}


		dp[i] = max(dp[i], 0LL);
		dp[i] += x * y - a;

		while ((int)possible.size() >= 2) {
			ll x1 = possible[(int)possible.size() - 2].first, y1 = possible[(int)possible.size() - 2].second;
			ll x2 = possible[(int)possible.size() - 1].first, y2 = possible[(int)possible.size() - 1].second;
			ll x3 = dp[i], y3 = x;
			x1 = x1 - x3, y1 = y1 - y3;
			x2 = x2 - x3, y2 = y2 - y3;
			if (y1 && y2) {
				if (x1 / y1 != x2 / y2) {
					if (x1 / y1 < x2 / y2) {
						possible.pop_back();
						continue;
					}
					else {
						break;
					}
				}
			}


		
			if (x1 && x2) {
				y1 %= x1;
				y2 %= x2;
			}


			if (x1 * y2 < x2 * y1) {
				possible.pop_back();
			}
			else {
				break;
			}
		}

		possible.push_back({ dp[i], x });
		sol = max(sol, dp[i]);
	}
	cout << sol << "\n";
}