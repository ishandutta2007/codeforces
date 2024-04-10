#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

int N;
pll A[808080];
priority_queue<ll> L;
priority_queue<ll, vector<ll>, greater<ll> > U, Q;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%lld%lld", &A[i].first, &A[i].second);
	sort(A + 1, A + N + 1, [&](const pll a, const pll b) {
		return a.first + a.second < b.first + b.second;
	});

	ll x0 = A[1].first;
	ll y0 = A[1].first;
	ll z0 = 1;
	L.push(x0); U.push(0);

	for(int i = 2; i <= N; i++) {
		ll t = A[i].first + A[i].second - A[i - 1].first - A[i - 1].second;
		while(z0 > L.size()) {
			ll u = U.top(); U.pop();
			L.push(u + x0);
		}
		while(z0 < L.size()) {
			ll l = L.top(); L.pop();
			U.push(l - x0);
		}

		x0 += t;

		z0++;
		y0 += A[i].first;

		if(A[i].first >= x0 + U.top()) {
			U.push(A[i].first - x0);
			U.push(A[i].first - x0);
		}
		else {
			L.push(A[i].first);
			L.push(A[i].first);
		}
	}

	Q = U;

	while(L.size()) {
		Q.push(L.top() - x0); L.pop();
	}

	ll y = y0, z = z0;
	ll bx = 0;
	ll ans = y;

	while(Q.size()) {
		ll x = Q.top() + x0; Q.pop();
		y -= z * (x - bx);
		z--;
		bx = x;
		ans = min(ans, y);
	}
	printf("%lld\n", ans);

	return 0;
}