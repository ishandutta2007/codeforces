#include <bits/stdc++.h>

using namespace std;

int N;
int A[3030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int s = 0;
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			s += A[i];
			int c = 1;
			int t = 0;
			for(int j = i + 1; j <= N; j++) {
				t += A[j];
				if(t > s) { c = -1; break; }
				else if(t == s) { t = 0; c++; }
			}
			if(t) c = -1;
			ans = max(ans, c);
		}
		printf("%d\n", N - ans);
	}
	return 0;
}