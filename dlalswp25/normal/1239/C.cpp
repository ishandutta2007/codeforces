#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = (1LL) << 60;

int N;
ll P;

deque<pll> q;
set<pll> s1;
set<pll> s2;
ll ans[101010];

int main() {
	scanf("%d%lld", &N, &P);
	for(int i = 1; i <= N; i++) {
		int t; scanf("%d", &t);
		s2.insert({t, i});
	}

	int ok = 0;
	ll t = 0;
	while(1) {
		if(ok >= N) break;
		ll nt1 = INF, nt2 = INF;
		if(q.size()) nt1 = q.front().second;
		if(s2.size()) nt2 = s2.begin() -> first;
		// printf("%lld\n", t);
		// printf("%lld %lld\n", nt1, nt2);

		if(nt1 < nt2) {
			ok++;
			ans[q.front().first] = q.front().second;
			q.pop_front();
			t = nt1;
		}
		else {
			auto it = s2.begin();
			s1.insert({it -> second, it -> first});
			s2.erase(it);
			t = nt2;
		}

		if(s1.size()) {
			auto it = s1.begin();
			if(!q.size()) {
				q.push_back({it -> first, t + P});
				s1.erase(it);
			}
			else if(q.back().first > it -> first) {
				q.push_back({it -> first, q.back().second + P});
				s1.erase(it);
			}
		}

		t = min(nt1, nt2);
	}
	for(int i = 1; i <= N; i++) printf("%lld ", ans[i]); puts("");

	return 0;
}