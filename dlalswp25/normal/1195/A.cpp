#include <bits/stdc++.h>

using namespace std;

int cnt[1010];
int N, K;

int main() {
	scanf("%d%d", &N, &K);

	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		cnt[a]++;
	}

	int o = 0;

	for(int i = 1; i <= K; i++) if(cnt[i] & 1) o++;
	printf("%d\n", N - o / 2);

	return 0;
}