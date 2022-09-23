#include <bits/stdc++.h>

using namespace std;

int N;
int A[505];
int X;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int lst = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] < X && lst == i - 1) lst = i;
			else if(A[i] < X) lst = -1;
		}
		if(lst == -1) { puts("-1"); continue; }

		int ans = 0;

		bool ok = true;
		int p = lst + 1;
		while(1) {
			while(p <= N && A[p] <= X) p++;
			if(p > N) break;
			bool ok = true;
			for(int j = p + 1; j <= N; j++) if(A[j] < A[j - 1]) ok = false;
			if(ok) break;
			ans++; swap(A[p], X); p++;
		}
		for(int i = 2; i <= N; i++) if(A[i] < A[i - 1]) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}