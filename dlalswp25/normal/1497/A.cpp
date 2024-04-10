#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];
int cnt[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 0; i <= 100; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			cnt[A[i]]++;
		}
		for(int i = 0; i <= 100; i++) {
			if(!cnt[i]) break;
			cnt[i]--; printf("%d ", i);
		}
		for(int i = 0; i <= 100; i++) {
			for(int j = 0; j < cnt[i]; j++) printf("%d ", i);
		}
		puts("");
	}
	return 0;
}