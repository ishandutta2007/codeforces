#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int C[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) C[i] = 0;
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			if(C[x] > 0) C[x] = -1;
			else if(C[x] == 0) C[x] = i;
		}
		int ans = -1;
		for(int i = 1; i <= N; i++) {
			if(C[i] > 0) {
				ans = C[i]; break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}