#include <bits/stdc++.h>

using namespace std;

char S[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		scanf("%s", S + 1);
		sort(S + 1, S + N + 1);
		printf("%s\n", S + 1);
	}
	return 0;
}