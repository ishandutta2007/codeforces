#include <bits/stdc++.h>

using namespace std;

int N;
char A[55];
int B[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		bool ans = false;
		for(int i = 0; i < 8; i++) {
			for(int j = 1; j <= N; j++) {
				if(1 << (A[j] - 'A') & i) B[j] = 1;
				else B[j] = -1;
			}

			bool ok = true;
			int s = 0;
			for(int j = 1; j <= N; j++) {
				s += B[j];
				if(s < 0) ok = false;
			}
			if(s) ok = false;
			ans = ans || ok;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}