#include <bits/stdc++.h>

using namespace std;

char A[55];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		scanf("%s", A + 1);
		int s = 0, mn = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '(') s++;
			else s--;
			mn = min(mn, s);
		}
		printf("%d\n", -mn);
	}
	return 0;
}