#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int C = 100000;

int N, M;
vector<int> xs[101010];
vector<int> ys[101010];

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			int c; scanf("%d", &c);
			xs[c].push_back(i);
			ys[c].push_back(j);
		}
	}

	ll ans = 0;

	for(int i = 1; i <= C; i++) {
		sort(xs[i].begin(), xs[i].end());
		ll sum = 0;
		for(int j = 0; j < xs[i].size(); j++) {
			ans += (ll)j * xs[i][j] - sum;
			sum += xs[i][j];
		}
		sort(ys[i].begin(), ys[i].end());
		sum = 0;
		for(int j = 0; j < ys[i].size(); j++) {
			ans += (ll)j * ys[i][j] - sum;
			sum += ys[i][j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}