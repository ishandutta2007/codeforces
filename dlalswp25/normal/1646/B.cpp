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
		sort(A + 1, A + N + 1);
		bool ok = false;
		ll x = A[1] + A[2], y = A[N];
		if(x < y) ok = true;
		int l = 3, r = N - 1;
		while(l < r) {
			x += A[l++]; y += A[r--];
			if(x < y) ok = true;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}