#include <bits/stdc++.h>

using namespace std;

int A[505];
int B[505];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);

		bool ok = false;
		for(int i = 1; i <= N; i++) {
			if(B[i] != B[1]) ok = true;
		}

		if(ok) puts("Yes");
		else {
			ok = true;
			for(int i = 2; i <= N; i++) if(A[i - 1] > A[i]) ok = false;
			puts(ok ? "Yes" : "No");
		}
	}
	return 0;
}