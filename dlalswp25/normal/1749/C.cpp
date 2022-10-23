#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			cnt[a]++;
		}
		int k;
		for(k = N; k >= 1; k--) {
			int s = 0;
			bool ok = true;
			for(int i = 1; i <= k; i++) {
				s += cnt[i];
				if(s < (k - i) + 2 * i - 1) ok = false;
			}
			if(ok) break;
		}
		printf("%d\n", k);
	}
	return 0;
}