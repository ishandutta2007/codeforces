#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
char S[202020];
int L[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		N = strlen(S + 1);
		for(int i = 1; i <= N; i++) L[i] = 0;
		int r0[2] = {0, 0};
		int r1[2] = {0, 0};
		for(int i = 1; i <= N; i++) {
			if(S[i] == '?') continue;
			if(S[i] == '0') {
				L[i] = max(r0[i + 1 & 1], r1[i & 1]);
				r0[i & 1] = i;
			}
			else {
				L[i] = max(r1[i + 1 & 1], r0[i & 1]);
				r1[i & 1] = i;
			}
		}
		ll ans = 0;
		int mx = 0;
		for(int i = 1; i <= N; i++) {
			mx = max(mx, L[i]);
			ans += i - mx;
		}
		printf("%lld\n", ans);
	}
	return 0;
}