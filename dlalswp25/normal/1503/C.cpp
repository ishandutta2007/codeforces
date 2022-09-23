#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<pii> v;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a, c; scanf("%d%d", &a, &c);
		v.emplace_back(a, c);
	}

	sort(v.begin(), v.end());

	int x = v[0].first;
	int r = v[0].first + v[0].second;
	int p = 1;

	ll ans = 0;
	for(pii i : v) ans += i.second;
	while(1) {
		while(p < N && v[p].first <= r) {
			r = max(r, v[p].first + v[p].second);
			p++;
		}
		if(p == N) break;
		ans += v[p].first - r;
		r = v[p].first + v[p].second;
		p++;
	}
	printf("%lld\n", ans);

	return 0;
}