#include <bits/stdc++.h>

using namespace std;

char A[60];

int main() {
	scanf("%s", A);
	int N = strlen(A);
	bool ok = true;
	for(int i = 2; i < N; i++) {
		if(A[i] - 'A' != (A[i - 1] - 'A' + A[i - 2] - 'A') % 26) ok = false;
	}
	puts(ok ? "YES" : "NO");
	return 0;
}