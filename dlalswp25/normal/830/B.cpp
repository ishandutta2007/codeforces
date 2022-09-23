#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> v[101010];

struct FWT {
	int T[101010];

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}
	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
}fwt;

int dist(int i, int j) {
	if(j < i) return dist(i, N) + dist(1, j);
	return fwt.get(j) - fwt.get(i - 1);
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		v[a].push_back(i);
	}

	for(int i = 1; i <= N; i++) fwt.upd(i, 1);

	ll ans = 0;

	int pos = 1;
	for(int i = 1; i <= 100000; i++) {
		int j = 0;
		for(; j < v[i].size(); j++) {
			if(v[i][j] >= pos) break;
		}

		int r = j;
		for(; j < v[i].size(); j++) {
			ans += dist(pos, v[i][j]);
			pos = v[i][j];
			fwt.upd(pos, -1);
		}

		for(j = 0; j < r; j++) {
			ans += dist(pos, v[i][j]);
			pos = v[i][j];
			fwt.upd(pos, -1);
		}
		// printf("%lld\n", ans);
	}
	printf("%lld\n", ans);

	return 0;
}