#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#pragma warning(disable:4996)

#define all(x) (x).begin(), (x).end()
vector <pll> Vl[49];
int main() {
	ll N, i, j, k;
	scanf("%lld", &N);

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 49; j++) {
			if (i + j > N) continue;

			ll v = 4 * i + 9 * j;

			ll st = v / 49, en = v / 49 + (N - i - j);
			Vl[v % 49].emplace_back(st, en);
		}
	}

	ll ans = 0;
	for (i = 0; i < 49; i++) {
		if (Vl[i].empty()) continue;
		sort(all(Vl[i]));

		pll u = Vl[i][0];
		for (j = 1; j < Vl[i].size(); j++) {
			pll it = Vl[i][j];
			if (u.second + 1 <= it.first) {
				ans += u.second - u.first + 1;
				u = it;
			}
			else u.second = max(u.second, Vl[i][j].second);
		}
		ans += u.second - u.first + 1;
	}
	return !printf("%lld\n", ans);
}