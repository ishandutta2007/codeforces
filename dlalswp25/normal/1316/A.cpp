#include <bits/stdc++.h>

using namespace std;

int N, M;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		int s = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			s += a;
		}
		if(s >= M) printf("%d\n", M);
		else printf("%d\n", s);
	}
	return 0;
}