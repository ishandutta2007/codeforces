#include <bits/stdc++.h>

using namespace std;

int N, M;
bool chk[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) chk[i] = false;
		for(int i = 1; i <= M; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c);
			chk[b] = true;
		}

		int r = 0;
		for(int i = 1; i <= N; i++) if(!chk[i]) r = i;
		for(int i = 1; i <= N; i++) {
			if(i == r) continue;
			printf("%d %d\n", i, r);
		}
	}
	return 0;
}