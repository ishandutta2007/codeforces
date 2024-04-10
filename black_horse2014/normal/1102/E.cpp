#include <bits/stdc++.h>
using namespace std;

map<int, int> F, S;

int modExp(int a, int n, int mo) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % mo) if (n & 1) ret = 1LL * ret * a %mo;
	return ret;
}

int a[220000];
vector<pair<int, int> > vec, cand;
const int MOD = 998244353;
int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], S[a[i]] = i;
	for (int i = 1; i <= n; i++) {
		if (!F.count(a[i])) {
			F[a[i]] = i;
			vec.push_back({i, S[a[i]]});
		}
	}
	sort(vec.begin(), vec.end());
	int l = 0, r = 0;
	for (int i = 0; i < vec.size(); i++) {
		int x = vec[i].first, y = vec[i].second;
		if (r < x) {
			cand.push_back({l, r});
			l = x, r = y;
		} else {
			r = max(r, y);		
		}
	}
	cand.push_back({l, r});
	for (auto e : cand) n -= (e.second - e.first);
	printf("%d\n", modExp(2, n - 1, MOD));
	return 0;
}