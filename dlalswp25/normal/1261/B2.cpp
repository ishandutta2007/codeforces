#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int T[202020];
int A[202020];
int N, Q;

vector<pii> v;
vector<pii> qs[202020];
int ans[202020];

void upd(int x, int v) {
	for(int i = x; i <= N; i += i&-i) T[i] += v;
}

int query(int x) {
	int ret = 0;
	for(int i = x; i; i -= i&-i) ret += T[i];
	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		v.push_back({-A[i], i});
	}

	sort(v.begin(), v.end());

	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++) {
		int k, p; scanf("%d%d", &k, &p);
		qs[k].push_back({p, i});
	}

	for(int i = 0; i < N; i++) {
		upd(v[i].second, 1);

		for(pii j : qs[i + 1]) {
			// printf("%d %d query\n", i + 1, j.first);
			int p = j.first;

			int l = 1, r = N;
			while(l <= r) {
				int m = l + r >> 1;
				if(query(m) < p) l = m + 1;
				else r = m - 1;
			}

			ans[j.second] = A[l];
		}
	}

	for(int i = 1; i <= Q; i++) printf("%d\n", ans[i]);

	return 0;
}