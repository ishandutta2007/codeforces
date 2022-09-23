#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 1000000;

int N, Q;
int A[303030];
int X[1010101];
int cnt[1010101];
vector<int> v;

int main() {
	for(int i = 1; i <= MX; i++) {
		if(X[i]) continue;
		for(ll j = 1; i * j * j <= MX; j++) {
			X[i * j * j] = i;
		}
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		v.clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			A[i] = X[A[i]];
			if(!cnt[A[i]]) {
				v.push_back(A[i]);
			}
			cnt[A[i]]++;
		}

		int sum = cnt[1];
		int mx = cnt[1];
		for(int i : v) {
			if(i == 1) continue;
			if(~cnt[i] & 1) sum += cnt[i];
			mx = max(mx, cnt[i]);
		}

		scanf("%d", &Q);
		while(Q--) {
			ll w; scanf("%lld", &w);
			if(!w) printf("%d\n", mx);
			else printf("%d\n", max(mx, sum));
		}

		for(int i : v) cnt[i] = 0;
	}
	return 0;
}