#include <bits/stdc++.h>

using namespace std;

int N;
char S[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", S + 1);
		bool sm = true;
		for(int i = 2; i <= N; i++) if(S[1] != S[i]) sm = false;
		if(sm) {
			printf("%d\n", 1 + (N - 1) / 3);
		}
		else {
			int ans = 0;
			int p = 1;
			for(; S[1] == S[p]; p++);
			int l = p - 1;

			while(1) {
				int c = 0;

				int i = p;
				for(; i <= N && S[i] == S[p]; i++) {
					c++;
				}
				if(i > N) {
					if(S[1] == S[N]) {
						ans += (c + l) / 3;
					}
					else {
						ans += c / 3;
						ans += l / 3;
					}
					break;
				}

				ans += c / 3;
				p = i;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}