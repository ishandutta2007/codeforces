#include <bits/stdc++.h>

using namespace std;

int N, X;
int A[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		bool ok = true;
		for(int i = 1; i <= N; i++) if(A[i] != X) ok = false;
		if(ok) { puts("0"); continue; }

		int s = 0;
		bool sm = false;
		for(int i = 1; i <= N; i++) { s += A[i]; sm |= (A[i] == X); }
		if(s == X * N || sm) { puts("1"); continue; }
		puts("2");
	}
	return 0;
}