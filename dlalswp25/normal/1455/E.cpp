#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll INF = (1LL << 60);

pii A[5];
int P[5];
bool chk[5];
ll ans;

ll calc(ll x) {
	ll ret = 0;
	vector<ll> v;
	for(int i = 0; i < 4; i++) {
		if(i & 1) v.push_back(A[P[i]].first - x);
		else v.push_back(A[P[i]].first);
	}
	sort(v.begin(), v.end());
	ret += v[3] + v[2] - v[1] - v[0];
	v.clear();

	for(int i = 0; i < 4; i++) {
		if(i >= 2) v.push_back(A[P[i]].second - x);
		else v.push_back(A[P[i]].second);
	}
	sort(v.begin(), v.end());
	ret += v[3] + v[2] - v[1] - v[0];

	return ret;
}

void solve() {
	vector<ll> v;
	for(int i = 0; i < 4; i++) v.push_back(A[i].first);
	sort(v.begin(), v.end());
	ll l1 = v[2] - v[1];
	v.clear();
	for(int i = 0; i < 4; i++) v.push_back(A[i].second);
	sort(v.begin(), v.end());
	ll l2 = v[2] - v[1];
	v.clear();

	for(int i = 0; i < 4; i++) P[i] = i;
	for(int i = 0; i < 24; i++) {
		ans = min(ans, calc(l1)); ans = min(ans, calc(l2));
		next_permutation(P, P + 4);
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ans = INF;
		for(int i = 0; i < 4; i++) chk[i] = false;
		for(int i = 0; i < 4; i++) scanf("%lld%lld", &A[i].first, &A[i].second);
		solve();
		printf("%lld\n", ans);
	}
	return 0;
}