#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int X = 20;

int N, M;
bool chk[20202020];
bool vst[1010101];
int A[25];

int main() {
	scanf("%d%d", &N, &M);

	for(int i = 1; i <= X; i++) {
		A[i] = A[i - 1];
		for(int j = 1; j <= M; j++) {
			if(!chk[i * j]) { chk[i * j] = true; A[i]++; }
		}
	}

	ll ans = 1;
	for(int i = 2; i <= N; i++) {
		if(vst[i]) continue;
		ll t = 1;
		int x = 0;
		while(t * i <= N) {
			t *= i; x++;
			vst[t] = true;
		}
		ans += A[x];
	}
	printf("%lld\n", ans);
	return 0;
}