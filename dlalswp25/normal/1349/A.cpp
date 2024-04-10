#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> cnt[202020];

int main() {
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int x; scanf("%d", &x);
		for(int j = 2; j * j <= x; j++) {
			int c = 0;
			while(x % j == 0) {
				c++; x /= j;
			}
			cnt[j].push_back(c);
		}
		if(x > 1) {
			cnt[x].push_back(1);
		}
	}

	ll ans = 1;
	for(int i = 2; i <= 200000; i++) {
		if(cnt[i].size() < N - 1) continue;
		if(cnt[i].size() < N) cnt[i].push_back(0);
		sort(cnt[i].begin(), cnt[i].end());
		for(int j = 0; j < cnt[i][1]; j++) ans *= i;
	}
	printf("%lld\n", ans);
	return 0;
}