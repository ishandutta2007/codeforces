#include <bits/stdc++.h>

using namespace std;

int N;
char S[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		N = strlen(S + 1);
		S[0] = S[N + 1] = 'c';
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(S[i] != S[i - 1] && S[i] != S[i + 1]) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}