#include <bits/stdc++.h>

using namespace std;

int N, M;
char S[101010];
char T[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		scanf("%s", T + 1);
		N = strlen(S + 1);
		M = strlen(T + 1);
		int p = N;
		bool ans = true;
		for(int i = M; i >= 1; i--) {
			while(p >= 1 && S[p] != T[i]) p -= 2;
			if(p <= 0) { ans = false; break; }
			p--;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}