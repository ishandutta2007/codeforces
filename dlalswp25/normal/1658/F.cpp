#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
char A[404040];
int num[2];
int cnt[2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		scanf("%s", A + 1);
		for(int i = N + 1; i <= N + N; i++) A[i] = A[i - N];
		num[0] = num[1] = 0;
		for(int i = 1; i <= N; i++) num[A[i] - '0']++;
		if((ll)num[0] * M % N || (ll)num[1] * M % N) { puts("-1"); continue; }
		num[0] = (ll)num[0] * M / N;
		num[1] = (ll)num[1] * M / N;

		cnt[0] = cnt[1] = 0;
		for(int i = 1; i <= M; i++) cnt[A[i] - '0']++;

		int K = -1;
		int L, R;
		for(int i = 1; i <= N; i++) {
			if(cnt[0] == num[0]) {
				if(i <= N - M + 1) K = 1;
				else K = 2;
				L = i; R = i + M - 1; break;
			}
			cnt[A[i] - '0']--;
			cnt[A[i + M] - '0']++;
		}
		if(K == -1) { puts("-1"); continue; }
		printf("%d\n", K);
		if(K == 1) printf("%d %d\n", L, R);
		else printf("%d %d\n%d %d\n", 1, R - N, L, N);
	}
	return 0;
}