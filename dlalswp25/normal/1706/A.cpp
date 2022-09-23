#include <bits/stdc++.h>

using namespace std;

int N, M;
char ans[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= M; i++) ans[i] = 'B';
		ans[M + 1] = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			if(a > M + 1 - a) a = M + 1 - a;
			if(ans[a] == 'A') ans[M + 1 - a] = 'A';
			else ans[a] = 'A';
		}
		printf("%s\n", ans + 1);
	}
	return 0;
}