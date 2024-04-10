#include <bits/stdc++.h>

using namespace std;

int N, C;
int cnt[2020202];
int sum[2020202];

int get(int l, int r) { return sum[r] - sum[l - 1]; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &C);
		for(int i = 1; i <= C + C; i++) cnt[i] = sum[i] = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			cnt[a]++;
		}
		for(int i = 1; i <= C + C; i++) sum[i] = sum[i - 1] + cnt[i];

		bool ok = true;
		for(int i = 1; i <= C; i++) {
			if(cnt[i]) continue;
			for(int j = 1; j <= C; j++) {
				if(i * j > C) break;
				if(!cnt[j]) continue;

				int l = j * i, r = j * (i + 1) - 1;
				int t = get(l, r);
				if(t) ok = false;
			}
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}