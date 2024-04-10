#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
ll A[10101];

vector<pair<pii, int> > ans;

void query(int i, int j, ll x) {
	ans.emplace_back(pii(i, j), x);
	ll t = x * i;
	A[i] -= t;
	A[j] += t;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		ans.clear();
		ll s = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%lld", &A[i]);
			s += A[i];
		}
		if(s % N) { puts("-1"); continue; }
		ll m = s / N;
		bool ok = false;
		for(int i = 1; i <= N; i++) if(A[i] >= i) ok = true;
		if(!ok) { puts("-1"); continue; }

		if(A[1] == 0) {
			for(int i = 2; i <= N; i++) {
				if(A[i] >= i) {
					query(i, 1, 1);
					break;
				}
			}
		}
		for(int i = 2; i <= N; i++) {
			ll t = (i - A[i] % i) % i;
			if(t > 0) {
				query(1, i, t);
			}

			query(i, 1, A[i] / i);
		}

		for(int i = 2; i <= N; i++) {
			query(1, i, m);
		}
		printf("%d\n", ans.size());
		for(auto i : ans) printf("%d %d %d\n", i.first.first, i.first.second, i.second);
	}
	return 0;
}