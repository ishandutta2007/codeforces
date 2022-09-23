#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { while(b) { a %= b; swap(a, b); } return a; }

int T;

vector<pair<ll, int> > V;

void add(ll i) {
	if(!V.size() || V.back().first != i) V.push_back({i, 1});
	else V.back().second++;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		ll a, m; scanf("%lld%lld", &a, &m);
		ll g = gcd(a, m);
		m /= g;

		for(ll i = 2; i * i <= m; i++) {
			if(m % i == 0) {
				add(i);
				m /= i; i--;
			}
		}
		if(m > 1) add(m);

		ll ans = 1;
		for(auto i : V) {
			ans *= (i.first - 1);
			for(int j = 0; j < i.second - 1; j++) ans *= i.first;
		}
		printf("%lld\n", ans);

		V.clear();
	}

	return 0;
}