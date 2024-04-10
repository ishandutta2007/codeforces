#include <bits/stdc++.h>

using namespace std;

int N, D;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &D);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		bool ok = true;
		for(int i = 1; i <= N; i++) if(A[i] > D) ok = false;
		if(!ok && A[1] + A[2] > D) puts("NO");
		else puts("YES");
	}
	return 0;
}