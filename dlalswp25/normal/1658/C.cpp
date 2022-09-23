#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int one = 0;
		for(int i = 1; i <= N; i++) one += (A[i] == 1);
		if(one != 1) { puts("NO"); continue; }
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			int t = (i + N - 2) % N + 1;
			if(A[i] - A[t] >= 2) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}