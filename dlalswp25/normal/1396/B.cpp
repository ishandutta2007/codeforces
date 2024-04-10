#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d", &N);

		int s = 0, mx = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			s += A[i];
			mx = max(mx, A[i]);
		}

		if(mx * 2 > s) puts("T");
		else if(s & 1) puts("T");
		else puts("HL");
	}	
	return 0;
}