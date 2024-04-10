#include <bits/stdc++.h>

using namespace std;

int N;
char A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int lst = -1;
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '0') {
				if(lst != -1) ans += max(3 - (i - lst), 0);
				lst = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}