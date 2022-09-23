#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 400000;

vector<int> divs[404040];

int main() {
	for(int i = 1; i <= MX; i++) {
		for(int j = i + i; j <= MX; j += i) divs[j].push_back(i);
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		int l, r; scanf("%d%d", &l, &r);

		ll ans = 0;
		for(int i = l + 2; i <= r; i++) {
			ll t = divs[i].end() - lower_bound(divs[i].begin(), divs[i].end(), l);
			ans += t * (t - 1) / 2;

			vector<int> v;
			for(int j : divs[i + i]) {
				if((i + i) / j % 2 == 0 || j >= i) continue;
				ans += divs[i].end() - lower_bound(divs[i].begin(), divs[i].end(), max(l, i - j + 1));
				ans += v.end() - lower_bound(v.begin(), v.end(), max(l, i - j + 1));
				v.push_back(j);
			}
		}
		ll d = r - l + 1;
		printf("%lld\n", d * (d - 1) * (d - 2) / 6 - ans);
	}
	return 0;
}