#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> v;

ll f(ll x) { return x * (x + 1) >> 1; }

ll g(ll x) {
	ll ret = 0;
	ll t = 1;
	for(int i = 1; i < 10; i++) {
		if(t * 10 > x) {
			ret += i * f(x - t + 1);
			return ret;
		}
		ret += i * (f(9 * t) + 9 * t * (x - 10 * t + 1));
		t *= 10;
	}
	return ret;
}

ll h(ll x) {
	ll ret = 0;
	ll t = 1;
	for(int i = 1; i < 10; i++) {
		if(t * 10 > x) {
			ret += i * (x - t + 1);
			return ret;
		}
		ret += i * (9 * t);
		t *= 10;
	}
	return ret;
}

void dig(int x) {
	while(x) {
		v.push_back(x % 10);
		x /= 10;
	}
	reverse(v.begin(), v.end());
}

int main() {
	int Q; scanf("%d", &Q);
	while(Q--) {
		v.clear();
		ll K; scanf("%lld", &K);
		K--;

		int l = 1, r = 1000000000;
		while(l <= r) {
			int m = l + r >> 1;
			if(g(m) > K) r = m - 1;
			else l = m + 1;
		}

		int t = l;
		K -= g(t - 1);

		l = 1, r = t;
		while(l <= r) {
			int m = l + r >> 1;
			if(h(m) > K) r = m - 1;
			else l = m + 1;
		}
		K -= h(r);
		dig(l);
		printf("%d\n", v[K]);
	}

	return 0;
}