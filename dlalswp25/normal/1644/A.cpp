#include <bits/stdc++.h>

using namespace std;

char A[10];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A);
		int key = 0;
		bool ok = true;
		for(int i = 0; i < 6; i++) {
			if(A[i] == 'r') key |= 1;
			else if(A[i] == 'g') key |= 2;
			else if(A[i] == 'b') key |= 4;
			else if(A[i] == 'R') {
				if(~key & 1) ok = false;
			}
			else if(A[i] == 'G') {
				if(~key & 2) ok = false;
			}
			else {
				if(~key & 4) ok = false;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}