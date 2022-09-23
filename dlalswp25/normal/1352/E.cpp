#include <bits/stdc++.h>

using namespace std;

bool ok[8080];
int A[8080];
int N;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) ok[i] = 0;

		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
		}

		for(int i = 1; i <= N; i++) {
			int s = A[i];
			for(int j = i + 1; j <= N; j++) {
				s += A[j];
				if(s > N) break;
				ok[s] = true;
			}
		}

		int ans = 0;
		for(int i = 1; i <= N; i++) if(ok[A[i]]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}