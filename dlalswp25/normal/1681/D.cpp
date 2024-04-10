#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<bool> get_digits(ll x) {
	vector<bool> v(10);
	while(x) {
		v[x % 10] = true;
		x /= 10;
	}
	return v;
}

int main() {
	int N; ll X;
	scanf("%d%lld", &N, &X);
	ll goal = 1;
	for(int i = 0; i < N - 1; i++) goal *= 10;
	map<ll, int> mp;
	mp[X] = 0;
	queue<ll> q;
	q.push(X);

	int ans = -1;
	while(q.size()) {
		ll x = q.front(); q.pop();
		if(x > goal) { ans = mp[x]; break; }
		auto v = get_digits(x);
		for(int i = 2; i < 10; i++) {
			if(!v[i]) continue;
			if(mp.find(x * i) != mp.end()) continue;
			mp[x * i] = mp[x] + 1;
			q.push(x * i);
		}
	}
	printf("%d\n", ans);
	return 0;
}