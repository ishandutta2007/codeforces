#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int ans[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		A[N + 1] = 0;
		int l = 1;
		bool ok = true;
		for(int i = 2; i <= N + 1; i++) {
			if(A[i] != A[i - 1]) {
				if(l == i - 1) ok = false;
				for(int j = l; j < i - 1; j++) {
					ans[j] = j + 1;
				}
				ans[i - 1] = l;
				l = i;
			}
		}
		if(!ok) puts("-1");
		else {
			for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
		}
	}
	return 0;
}