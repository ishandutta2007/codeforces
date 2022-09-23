#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int N;
ll A[303030];
ll S[303030];
vector<pll> T[2];
map<int, vector<int> > mp[2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		T[0].clear(); T[1].clear();
		mp[0].clear(); mp[1].clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		for(int i = 1; i <= N; i++) S[i] = A[i] - S[i - 1];
		ll ans = 0;
		T[N & 1].emplace_back(S[N], N);
		mp[N & 1][S[N]].push_back(-N);

		for(int i = N - 1; i >= 0; i--) {
			ll rgt = N;
			auto it = lower_bound(T[i & 1].begin(), T[i & 1].end(), pll(S[i], 0));
			if(it != T[i & 1].begin()) {
				it--;
				rgt = min(rgt, it -> second - 1);
			}
			it = lower_bound(T[i + 1 & 1].begin(), T[i + 1 & 1].end(), pll(-S[i], 0));
			if(it != T[i + 1 & 1].begin()) {
				it--;
				rgt = min(rgt, it -> second - 1);
			}

			vector<int>& v = mp[i & 1][S[i]];
			int t = v.size();
			t -= lower_bound(v.begin(), v.end(), -(int)rgt) - v.begin();
			ans += t;

			vector<int>& w = mp[i + 1 & 1][-S[i]];
			t = w.size();
			t -= lower_bound(w.begin(), w.end(), -(int)rgt) - w.begin();
			ans += t;

			while(T[i & 1].size() && T[i & 1].back().first >= S[i]) T[i & 1].pop_back();
			T[i & 1].emplace_back(S[i], i);
			mp[i & 1][S[i]].push_back(-i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}