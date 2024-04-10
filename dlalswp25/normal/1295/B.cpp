#include <bits/stdc++.h>

using namespace std;

int T, N;
int x;
char A[101010];
int B[101010];

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &x);
		scanf("%s", A + 1);

		int s = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '0') s++;
			else s--;
			B[i] = s;
		}

		if(s == 0) {
			bool f = false;
			for(int i = 1; i <= N; i++) {
				if(B[i] == x) f = true;
			}
			if(f) puts("-1");
			else {
				if(x == 0) puts("1");
				else puts("0");
			}
			continue;
		}

		int ans = 0;
		for(int i = 1; i <= N; i++) {
			if(abs(x - B[i]) % abs(s) == 0) {
				int k = (x - B[i]) / s;
				if(k >= 0) ans++;
			}
		}
		if(x == 0) ans++;
		printf("%d\n", ans);
	}

	return 0;
}