#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, Q;
ll A[101010];
ll S[101010];
multiset<ll> v;

void f(int l, int r) {
	if(l > r) return;
	v.insert(S[r] - S[l - 1]);
	if(A[l] == A[r]) return;
	ll x = (A[l] + A[r]) >> 1;
	int t = upper_bound(A + 1, A + N + 1, x) - A;
	f(l, t - 1);
	f(t, r);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &Q);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		sort(A + 1, A + N + 1);
		for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
		v.clear();
		f(1, N);
		while(Q--) {
			int s; scanf("%d", &s);
			puts(v.find(s) == v.end() ? "No" : "Yes");
		}
	}
	return 0;
}