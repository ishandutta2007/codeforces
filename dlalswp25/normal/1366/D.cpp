#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 10000000;

int A[505050];
int B[505050];
int C[505050];
int X[10101010];

int main() {

	for(int i = 2; i <= MX; i++) {
		if(X[i]) continue;
		X[i] = i;
		for(ll j = (ll)i * i; j <= MX; j += i) {
			X[j] = i;
		}
	}

	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) {
		int x = A[i];
		int t = X[A[i]];
		int y = 1;
		while(x % t == 0) { x /= t; y *= t; }
		if(x == 1) B[i] = C[i] = -1;
		else {
			B[i] = y; C[i] = A[i] / y;
		}
	}

	for(int i = 1; i <= N; i++) printf("%d ", B[i]); puts("");
	for(int i = 1; i <= N; i++) printf("%d ", C[i]); puts("");

	return 0;
}