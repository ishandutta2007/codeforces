#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A[202020];
bool chk[202020];
ll N;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%lld", &N);
		for(int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
			chk[(i + A[i] + N * 1000000000) % N] = true;
		}

		bool ok = true;
		for(int i = 0; i < N; i++) {
			if(!chk[i]) ok = false;
		}
		puts(ok ? "YES" : "NO");
		for(int i = 0; i < N; i++) chk[i] = false;
	}
	return 0;
}