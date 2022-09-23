#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		int zero = 0, one = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '0') zero++;
			else one++;
		}
		if(zero == one) printf("%d\n", zero - 1);
		else printf("%d\n", min(zero, one));
	}
	return 0;
}