#include <bits/stdc++.h>

using namespace std;

bool chk[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) chk[i] = false;
		puts("2");
		for(int i = 1; i <= N; i++) {
			if(chk[i]) continue;
			int x = i;
			while(x <= N) {
				printf("%d ", x);
				chk[x] = true;
				x <<= 1;
			}
		}
		puts("");
	}
	return 0;
}