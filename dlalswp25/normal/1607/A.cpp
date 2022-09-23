#include <bits/stdc++.h>

using namespace std;

int pos[130];
char A[30];
char S[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		for(int i = 1; i <= 26; i++) pos[A[i]] = i;
		scanf("%s", S + 1);
		int N = strlen(S + 1);
		int ans = 0;
		for(int i = 2; i <= N; i++) ans += abs(pos[S[i]] - pos[S[i - 1]]);
		printf("%d\n", ans);
	}
	return 0;
}