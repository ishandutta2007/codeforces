#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 200000;

vector<int> divs[404040];
vector<pair<int, int>> qs[202020];
ll ans[101010];

struct BIT {
	ll T[202020];

	void upd(int x, int v) {
		for(int i = x; i <= MX; i += i&-i) T[i] += v;
	}

	void upd(int l, int r, int v) {
		upd(l, v); upd(r + 1, -v);
	}

	ll query(int x) {
		ll ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
}fwt;

int main() {
	for(int i = 1; i <= MX + MX; i++) {
		for(int j = i + i; j <= MX + MX; j += i) divs[j].push_back(i);
	}

	int Q; scanf("%d", &Q);
	for(int i = 1; i <= Q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		qs[r].emplace_back(l, i);
	}

	for(int i = 1; i <= MX; i++) {
		for(int j = 1; j < divs[i].size(); j++) {
			int x = divs[i][(int)divs[i].size() - j - 1];
			fwt.upd(1, x, j);
		}

		int p = (int)divs[i + i].size() - 1;
		for(int j = 0; j < divs[i + i].size(); j++) {
			while(p > 0 && divs[i + i][j] + divs[i + i][p - 1] > i) p--;
			if(p <= j) break;
			fwt.upd(1, divs[i + i][j], (int)divs[i + i].size() - 1 - p);
		}

		p = (int)divs[i].size();
		for(int j = 0; j < divs[i].size(); j++) {
			while(p > 0 && divs[i][j] + divs[i][p - 1] > i) p--;
			if(p <= j) break;
			fwt.upd(1, divs[i + i][j], -((int)divs[i].size() - p));
		}

		for(auto& j : qs[i]) {
			ll d = i - j.first + 1;
			ans[j.second] = d * (d - 1) * (d - 2) / 6 - fwt.query(j.first);
		}
	}

	for(int i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
	return 0;
}