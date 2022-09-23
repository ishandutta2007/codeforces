#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		if(N == 1) puts("-1");
		else {
			printf("5");
			for(int i = 1; i < N; i++) printf("7");
			puts("");
		}
	}
	return 0;
}