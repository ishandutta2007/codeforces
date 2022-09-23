#include <bits/stdc++.h>

using namespace std;

int X[4][4] = {
	{1, 0, 0, 1},
	{1, 1, 0, 0},
	{0, 1, 1, 0},
	{0, 0, 1, 1}
};

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N;
		int A[4];
		int B[4];
		scanf("%d", &N);
		for(int i = 0; i < 4; i++) scanf("%d", &A[i]);
		bool ans = false;
		for(int i = 0; i < 16; i++) {
			for(int j = 0; j < 4; j++) B[j] = A[j];
			for(int j = 0; j < 4; j++) {
				if(~i & 1 << j) continue;
				for(int k = 0; k < 4; k++) {
					if(X[j][k]) B[k]--;
				}
			}
			bool ok = true;
			for(int j = 0; j < 4; j++) if(B[j] < 0 || B[j] > N - 2) ok = false;
			ans = ans || ok;
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}