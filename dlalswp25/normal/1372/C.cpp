#include <bits/stdc++.h>

using namespace std;

int A[202020];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int c = 0;
		for(int i = 1; i <= N; i++) if(i == A[i]) c++;

		if(c == N) puts("0");
		else if(c == 0) puts("1");
		else {
			int l = 1;
			while(l == A[l]) l++;
			int r = N;
			while(r == A[r]) r--;
			if((l - 1) + (N - r) == c) puts("1");
			else puts("2");
		}
	}
	return 0;
}