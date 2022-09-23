#include <bits/stdc++.h>

using namespace std;

int A[55];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);

		int e = 0, o = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] & 1) o++;
			else e++;
		}

		if(~e & 1) puts("YES");
		else {
			bool ok = false;
			for(int i = 1; i < N; i++) {
				if(A[i] == A[i + 1] - 1) ok = true;
			}
			puts(ok ? "YES" : "NO");
		}
	}
	return 0;
}