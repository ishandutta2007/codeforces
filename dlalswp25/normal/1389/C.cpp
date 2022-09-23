#include <bits/stdc++.h>

using namespace std;

int N;
char S[202020];


int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		N = strlen(S + 1);

		int ans = N;
		for(int i = 0; i < 10; i++) {
			int c = 0;
			for(int j = 1; j <= N; j++) if(S[j] == i + '0') c++;
			ans = min(ans, N - c);
		}

		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < 10; j++) {
				int c = 0, e = 0;
				for(int k = 1; k <= N; k++) {
					if(c & 1) {
						if(S[k] == j + '0') c++;
						else e++;
					}
					else {
						if(S[k] == i + '0') c++;
						else e++;
					}
				}
				if(c & 1) e++;
				ans = min(ans, e);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}