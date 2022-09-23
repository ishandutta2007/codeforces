#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int r = 0;
		for(int i = N; i >= 1; i--) {
			if(A[i]) { r = i; break; }
		}
		if(!r) { puts("Yes"); continue; }
		ll s = 0;
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			s += A[i];
			if(s < 0 || (!s && i < r)) { ok = false; break; }
		}
		puts(!s && ok ? "Yes" : "No");
	}
	return 0;
}