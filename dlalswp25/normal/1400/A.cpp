#include <bits/stdc++.h>

using namespace std;

int N;
char S[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", S + 1);
		for(int i = 1; i <= 2 * N - 1; i += 2) printf("%c", S[i]); puts("");
	}
	return 0;
}