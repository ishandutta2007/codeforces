#include <bits/stdc++.h>

using namespace std;

int N, M, P;

int main() {
	scanf("%d%d%d", &N, &M, &P);
	int s = -1, t = -1;
	for(int i = 0; i < N; i++) {
		int x; scanf("%d", &x);
		if(s != -1) continue;
		if(x % P != 0) s = i;
	}
	for(int i = 0; i < M; i++) {
		int x; scanf("%d", &x);
		if(t != -1) continue;
		if(x % P != 0) t = i;
	}
	printf("%d\n", s + t);
	return 0;
}