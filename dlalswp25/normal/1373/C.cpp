#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char S[1010101];
int N;

int A[1010101];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", S + 1);
		N = strlen(S + 1);

		int mx = 0;
		int x = 0;
		for(int i = 1; i <= N; i++) {
			if(S[i] == '-') {
				x++;
				if(x > mx) {
					A[x] = i;
					mx = x;
				}
			}
			else x--;
		}

		ll ans = 0;
		for(int i = 1; i <= mx; i++) ans += A[i];
		printf("%lld\n", ans + N);
	}
	return 0;
}