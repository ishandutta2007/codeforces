#include <bits/stdc++.h>

using namespace std;

int N, K;
char A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		scanf("%s", A + 1);
		bool palin = true;
		for(int i = 1; i <= N; i++) if(A[i] != A[N - i + 1]) palin = false;
		if(!K || palin) puts("1");
		else puts("2");
	}
	return 0;
}