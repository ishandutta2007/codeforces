#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef tuple<int, int, ll> piil;

int N, T;
int G[202020];
int C[202020];
int D[202020];
int X[202020];

set<piil> S;

void add(int l, int r, ll x) {
	// printf("add %d %d %lld\n", l, r, x);
	piil t = make_tuple(l, T, 0LL);
	piil p = make_tuple(l, r, x);
	S.insert(t);
	auto it = S.lower_bound(t);
	if(it != S.begin()) {
		auto tmp = prev(it);
		int l0, r0; ll x0;
		tie(l0, r0, x0) = *tmp;
		if(l <= r0) {
			if(r0 >= r) {
				if(l != l0) {
					S.insert(make_tuple(l0, l - 1, x0));
				}
				if(r != r0) {
					S.insert(make_tuple(r + 1, r0, x0));
				}
			}
			else {
				if(l != l0) {
					S.insert(make_tuple(l0, l - 1, x0));
				}
			}
			S.erase(tmp);
		}
	}
	while(1) {
		auto tmp = next(it);
		if(tmp == S.end()) break;
		int l0, r0; ll x0;
		tie(l0, r0, x0) = *tmp;
		if(l0 > r) break;
		if(r0 > r) {
			S.insert(make_tuple(r + 1, r0, x0));
		}
		S.erase(tmp);
	}
	S.erase(it);
	S.insert(p);
}

ll f(int x) {
	auto it = S.lower_bound(make_tuple(x + 1, 0, 0LL));
	if(it == S.begin()) return x;
	it--;
	int l, r; ll a;
	tie(l, r, a) = *it;
	if(r < x) return x;
	return a;
}

ll g(int x) { return f(x) - x; }

void print() {
	for(auto& i : S) {
		int l, r; ll x;
		tie(l, r, x) = i;
		printf("(%d %d %lld)\n", l, r, x);
	}
}

int main() {
	scanf("%d%d", &N, &T);
	for(int i = 1; i <= N; i++) scanf("%d%d", &G[i], &C[i]);
	for(int i = 1; i < N; i++) scanf("%d", &D[i]);
	X[N] = 0;
	add(G[N], T - 1, T);
	for(int i = N - 1; i >= 1; i--) {
		// printf("i=%d\n", i);
		X[i] = ((ll)T + C[i + 1] - C[i] + D[i] + X[i + 1]) % T;
		ll t = f(X[i]) - X[i];
		// printf("xi %d t %lld\n", X[i], t);

		int l = (X[i] + G[i]) % T;
		int r = (X[i] + T - 1) % T;
		if(l <= r) {
			if(X[i]) add(l, r, t + X[i]);
			else add(l, r, t + T);
		}
		else {
			add(l, T - 1, t + X[i] + T);
			add(0, r, t + X[i]);
		}
	}
	ll ans = 1LL << 60;
	int bef = -1;
	for(auto& i : S) {
		int l, r; ll x;
		tie(l, r, x) = i;
		if(l != bef + 1) ans = 0;
		ans = min(ans, x - r);
		bef = r;
	}
	for(int i = 1; i < N; i++) ans += D[i];
	printf("%lld\n", ans);
	return 0;
}