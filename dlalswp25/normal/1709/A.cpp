#include <bits/stdc++.h>

using namespace std;

int A[4];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int x; scanf("%d", &x);
		for(int i = 1; i <= 3; i++) scanf("%d", &A[i]);
		bool ok = true;
		for(int i = 1; i <= 3; i++) if(A[i] == i) ok = false;
		if(A[x] == 0) ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}