#include <bits/stdc++.h>

using namespace std;

int S[10];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int x; scanf("%d", &x);
		if(x > 45) { puts("-1"); continue; }
		int d = 1;
		int t = 9;
		for(int i = 1; i <= 9; i++) S[i] = S[i - 1] + (10 - i);
		while(1) {
			if(S[d] >= x) break;
			d++;
		}
		for(int i = 0; i < d; i++) {
			for(int j = 1; j <= 9; j++) {
				if(x - j <= S[d - i - 1]) {
					x -= j;
					printf("%d", j);
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}