#include <bits/stdc++.h>

using namespace std;

int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int s = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			s += A[i];
		}
		bool ok = false;
		for(int i = 2; i * i <= s; i++) {
			if(s % i == 0) ok = true;
		}
		if(ok) {
			printf("%d\n", N);
			for(int i = 1; i <= N; i++) printf("%d ", i); puts("");
		}
		else {
			printf("%d\n", N - 1);
			bool fg = false;
			for(int i = 1; i <= N; i++) {
				if(!fg && (A[i] & 1)) fg = true;
				else printf("%d ", i);
			}
			puts("");
		}
	}
	return 0;
}