#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int N;
pll A[5050];
bool chk[5050];
vector<int> ans;

ll dst(pll a, pll b) {
	ll dx = a.first - b.first;
	ll dy = a.second - b.second;
	return dx * dx + dy * dy;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld%lld", &A[i].first, &A[i].second);
	ans.push_back(1);
	int now = 1; chk[1] = true;
	for(int i = 1; i < N; i++) {
		int cand = 0;
		ll mx = 0;
		for(int j = 1; j <= N; j++) {
			if(chk[j]) continue;
			ll d = dst(A[now], A[j]);
			if(mx < d) {
				mx = d; cand = j;
			}
		}
		chk[cand] = true;
		ans.push_back(cand);
		now = cand;
	}
	for(int i : ans) printf("%d ", i); puts("");
	return 0;
}