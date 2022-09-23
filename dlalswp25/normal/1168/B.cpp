#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
char A[303030];

bool chk(int x, int l) {
	for(int i = l - 1; l - (l - i) * 2 >= 0; i--) {
		int a = l - (l - i) * 2;
		int b = l - (l - i);
		int c = l;
		if(A[x + a] == A[x + b] && A[x + b] == A[x + c]) return true;
	}
	return false;
}

int main() {
	scanf("%s", A + 1);
	N = strlen(A + 1);

	ll ans = 0;
	for(int i = 1; i <= N - 2; i++) {
		int j = 2;
		for(; j < 8 && i + j <= N; j++) {
			if(chk(i, j)) break;
		}
		ans += (N - i - j + 1);
	}
	printf("%lld\n", ans);
	return 0;
}