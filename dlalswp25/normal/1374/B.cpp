#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		int a = 0, b = 0;
		while(N % 2 == 0) { a++; N /= 2; }
		while(N % 3 == 0) { b++; N /= 3; }
		if(N != 1 || a > b) { puts("-1"); continue; }
		printf("%d\n", b + (b - a));
	}
	return 0;
}