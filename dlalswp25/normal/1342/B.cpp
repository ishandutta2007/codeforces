#include <bits/stdc++.h>

using namespace std;

char A[105];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", A + 1);
		int N = strlen(A + 1);
		bool ok = true;
		for(int i = 2; i <= N; i++) if(A[i] != A[i - 1]) ok = false;
		if(ok) printf("%s\n", A + 1);
		else {
			for(int i = 1; i <= N; i++) printf("10"); puts("");
		}
	}
	return 0;
}