#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll H[1010101];
ll S;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%lld", &H[i]);
		S += H[i];
	}

	ll T = S - (ll)N * (N - 1) / 2;
	ll A = T / N;

	ll B = A * N + (ll)N * (N - 1) / 2;
	B = S - B;
	for(int i = 1; i <= N; i++) {
		if(i <= B) printf("%lld ", A + 1 + (i - 1));
		else printf("%lld ", A + (i - 1));
	}
	puts("");
	return 0;
}