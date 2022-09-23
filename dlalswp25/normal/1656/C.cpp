#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		bool one = false;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			if(A[i] == 1) one = true;
		}
		if(!one) { puts("YES"); continue; }
		sort(A + 1, A + N + 1);
		bool ok = true;
		for(int i = 1; i < N; i++) if(A[i + 1] - A[i] == 1) ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}