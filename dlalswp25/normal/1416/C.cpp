#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll D[33][2];
int N;
vector<int> A;

void f(int b, vector<int>& v) {
	if(b < 0 || !v.size()) return;
	ll c0 = 0, c1 = 0;
	ll d0 = 0, d1 = 0;
	vector<int> l, r;
	for(int i : v) {
		if(1 << b & i) {
			d1 += c0;
			c1++;
			r.push_back(i);
		}
		else {
			d0 += c1;
			c0++;
			l.push_back(i);
		}
	}

	D[b][0] += d0;
	D[b][1] += d1;
	f(b - 1, l);
	f(b - 1, r);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		A.push_back(a);
	}
	f(29, A);
	ll ans = 0;
	ll z = 0;
	for(int i = 29; i >= 0; i--) {
		if(D[i][0] > D[i][1]) z |= (1 << i);
		ans += min(D[i][0], D[i][1]);
	}
	printf("%lld %lld\n", ans, z);
	return 0;
}