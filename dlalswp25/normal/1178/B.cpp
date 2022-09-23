#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char S[1010101];
int N;
int L[1010101];
int R[1010101];

ll ans = 0;

int main() {
	scanf("%s", S);
	N = strlen(S);

	for(int i = 1; i < N; i++) {
		L[i] = L[i - 1];
		if(S[i] == 'v' && S[i - 1] == 'v') L[i]++;
	}
	for(int i = N - 2; i >= 0; i--) {
		R[i] = R[i + 1];
		if(S[i] == 'v' && S[i + 1] == 'v') R[i]++;
	}

	for(int i = 2; i < N - 2; i++) {
		if(S[i] == 'o') {
			ans += (ll)(L[i - 1]) * R[i + 1];
		}
	}
	printf("%lld\n", ans);
	return 0;
}