#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

set<ll> ans;
set<int> G;

ll f(ll n) {
	return n * (n + 1) / 2;
}

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i * i <= N; i++) {
		if(N % i) continue;
		G.insert(i);
		G.insert(N / i);
	}

	for(int d : G) {
		ll S = f(N - 1);
		S -= d * f(N / d - 1);
		S /= (N / d);
		ans.insert(S + d);
	}
	for(ll i : ans) printf("%lld ", i); puts("");
	return 0;
}