#include <bits/stdc++.h>

using namespace std;

int N;
int D[105];
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &D[i]);
		A[1] = D[1];
		bool ok = true;
		for(int i = 2; i <= N; i++) {
			if(D[i] && A[i - 1] - D[i] >= 0) { ok = false; break; }
			A[i] = A[i - 1] + D[i];
		}
		if(!ok) puts("-1");
		else {
			for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
		}
	}
	return 0;
}