#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int s = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			s += a;
		}
		if(s == N) puts("0");
		else if(s < N) puts("1");
		else printf("%d\n", s - N);
	}
	return 0;
}