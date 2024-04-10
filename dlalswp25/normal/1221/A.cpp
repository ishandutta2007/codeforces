#include <bits/stdc++.h>

using namespace std;

int cnt[30];
int N;

int main() {
	int Q; scanf("%d", &Q);
	while(Q--) {
		for(int i = 0; i < 30; i++) cnt[i] = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);

			int c = 0;
			while(x > 1) {
				c++; x >>= 1;
			}
			cnt[c]++;
		}

		for(int i = 0; i < 11; i++) {
			cnt[i + 1] += cnt[i] / 2;
		}
		puts(cnt[11] ? "YES" : "NO");
	}
	return 0;
}