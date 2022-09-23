#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		int s = 0;
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(A[i] == 'A') s++;
			else s--;
			if(s < 0) ok = false;
		}
		if(A[N] != 'B') ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}