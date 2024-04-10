#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			cnt[a]++;
		}
		int mx = 0, mc = 0;
		for(int i = 1; i <= N; i++) {
			if(mx < cnt[i]) {
				mx = cnt[i]; mc = 1;
			}
			else if(mx == cnt[i]) mc++;
		}

		printf("%d\n", (N - mc) / (mx - 1) - 1);
	}
	return 0;
}