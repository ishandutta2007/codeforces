#include <bits/stdc++.h>

using namespace std;

int N;
char S[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", S + 1);
		for(int i = 1; i <= N; i++) {
			if(S[i] == 'U' || S[i] == 'D') printf("%c", 'U' + 'D' - S[i]);
			else printf("%c", S[i]);
		}
		puts("");
	}
	return 0;
}