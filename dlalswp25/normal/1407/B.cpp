#include <bits/stdc++.h>

using namespace std;

int N;
int A[1010];
int B[1010];
bool chk[1010];

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		for(int i = 1; i <= N; i++) chk[i] = false;

		int g = 0;
		for(int i = 1; i <= N; i++) {
			int mx = 0, mxi;
			for(int j = 1; j <= N; j++) {
				if(chk[j]) continue;
				int t = gcd(g, A[j]);
				if(t > mx) { mx = t; mxi = j; }
			}
			B[i] = A[mxi];
			chk[mxi] = true;
			g = gcd(g, B[i]);
		}
		for(int i = 1; i <= N; i++) printf("%d ", B[i]); puts("");
	}
	return 0;
}