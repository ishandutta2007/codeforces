#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
pii A[202020];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i].first);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i].second);

	ll ans = 0;
	for(int i = 1; i <= N; i++) {
		ans += abs(A[i].first - A[i].second);
	}

	int add = 0;
	for(int z = 0; z < 2; z++) {
		sort(A + 1, A + N + 1);
		vector<pii> v;
		for(int i = 1; i <= N; i++) {
			v.emplace_back(A[i].second, A[i].first);
		}
		sort(v.begin(), v.end());

		int l = 1, r = 1000000000;
		while(l <= r) {
			ll m = (ll)(l + r >> 1);

			int mx = 0;
			bool ok = false;
			int p = 0;
			for(int i = 1; i <= N; i++) {
				while(p < v.size() && v[p].first <= A[i].first) {
					mx = max(mx, v[p].second);
					p++;
				}

				if(A[i].second < A[i].first + m) continue;
				if(mx >= A[i].first + m) ok = true;
			}
			if(ok) l = m + 1;
			else r = m - 1;
		}
		add = max(add, r);

		for(int i = 1; i <= N; i++) swap(A[i].first, A[i].second);
	}

	printf("%lld\n", ans - 2 * add);

	return 0;
}