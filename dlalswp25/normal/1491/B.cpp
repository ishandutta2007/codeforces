#include <bits/stdc++.h>

using namespace std;

int N, U, V;
int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &U, &V);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		bool ok = false;
		for(int i = 2; i <= N; i++) if(abs(A[i] - A[i - 1]) > 1) ok = true;
		if(ok) { puts("0"); continue; }

		ok = true;
		for(int i = 2; i <= N; i++) if(A[i] != A[i - 1]) ok = false;
		if(ok) printf("%d\n", V + min(U, V));
		else printf("%d\n", min(U, V));
	}
	return 0;
}