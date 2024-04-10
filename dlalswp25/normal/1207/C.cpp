#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = (1LL) << 60;

int T;
int N;
ll D[202020][2];
ll A, B;
char S[202020];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%lld%lld", &N, &A, &B);

		for(int i = 0; i <= N; i++) {
			D[i][0] = D[i][1] = INF;
		}
		scanf("%s", S + 1);
		
		D[0][0] = B;

		for(int i = 1; i <= N; i++) {
			if(S[i] != '1' && S[i + 1] != '1') {
				D[i][0] = min(D[i - 1][0] + B + A, D[i - 1][1] + 2 * A + B);
			}
			D[i][1] = min(D[i - 1][0] + 2 * B + 2 * A, D[i - 1][1] + A + 2 * B);

			//printf("%lld %lld\n", D[i][0], D[i][1]);
		}
		printf("%lld\n", D[N][0]);
	}

	return 0;
}