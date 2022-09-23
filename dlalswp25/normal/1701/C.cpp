#include <bits/stdc++.h>

using namespace std;

int N, M;
int cnt[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) cnt[i] = 0;
		for(int i = 1; i <= M; i++) {
			int a; scanf("%d", &a);
			cnt[a]++;
		}
		int l = 1, r = M + M;
		while(l <= r) {
			int m = l + r >> 1;
			long long tot = 0;
			for(int i = 1; i <= N; i++) {
				if(m <= cnt[i]) tot += m;
				else tot += cnt[i] + (m - cnt[i]) / 2;
			}
			if(tot < M) l = m + 1;
			else r = m - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}