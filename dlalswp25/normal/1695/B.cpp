#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
int A[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int mn = 1010101010, mni;
		for(int i = 1; i <= N; i++) if(A[i] < mn) { mn = A[i]; mni = i; }
		if(N & 1) puts("Mike");
		else puts(mni & 1 ? "Joe" : "Mike");
	}
	return 0;
}