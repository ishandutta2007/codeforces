#include <bits/stdc++.h>

using namespace std;

vector<int> v[202020];
int N, K;
int ans = 1010101010;

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		int cnt = 0;
		while(a) {
			v[a].push_back(cnt);
			a >>= 1; cnt++;
		}
		v[0].push_back(cnt);
	}
	for(int i = 0; i <= 200000; i++) {
		if(v[i].size() < K) continue;
		sort(v[i].begin(), v[i].end());

		int s = 0;
		for(int j = 0; j < K; j++) {
			s += v[i][j];
		}
		ans = min(ans, s);
	}
	printf("%d\n", ans);

	return 0;
}