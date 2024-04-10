#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll D[5050];
int tag[5050];
int S[5050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &tag[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &S[i]);
		for(int i = 1; i <= N; i++) D[i] = 0;

		for(int i = 1; i <= N; i++) {
			for(int j = i - 1; j > 0; j--) {
				if(tag[i] == tag[j]) continue;
				int c = abs(S[i] - S[j]);
				ll t = D[i];
				D[i] = max(D[i], D[j] + c);
				D[j] = max(D[j], t + c);
			}
		}

		ll ans = 0;
		for(int i = 1; i <= N; i++) ans = max(ans, D[i]);
		printf("%lld\n", ans);
	}
	return 0;
}