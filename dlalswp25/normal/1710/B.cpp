#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M, K;
vector<int> xs;
ll Y[606060];
int delta[606060];
int X[202020];
int P[202020];

int coord(int x) {
	return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		xs.clear();
		for(int i = 1; i <= N; i++) {
			scanf("%d%d", &X[i], &P[i]);
			xs.push_back(X[i]);
			xs.push_back(X[i] - P[i]);
			xs.push_back(X[i] + P[i]);
		}
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		K = xs.size();

		for(int i = 1; i <= K; i++) delta[i] = 0;

		for(int i = 1; i <= N; i++) {
			int t = coord(X[i]);
			delta[t] -= 2;
			t = coord(X[i] - P[i]);
			delta[t]++;
			t = coord(X[i] + P[i]);
			delta[t]++;
		}

		ll slope = 0;
		for(int i = 1; i <= K; i++) {
			if(i > 1) Y[i] = Y[i - 1] + slope * (xs[i - 1] - xs[i - 2]);
			slope += delta[i];
		}

		ll mx1 = -1LL << 60, mx2 = -1LL << 60;
		for(int i = 1; i <= K; i++) {
			if(Y[i] <= M) continue;
			mx1 = max(mx1, xs[i - 1] + (Y[i] - M));
			mx2 = max(mx2, (Y[i] - M) - xs[i - 1]);
		}

		for(int i = 1; i <= N; i++) {
			if(P[i] + X[i] >= mx1 && P[i] - X[i] >= mx2) printf("1");
			else printf("0");
		}

		puts("");
	}
	return 0;
}