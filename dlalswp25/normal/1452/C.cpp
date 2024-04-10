#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		int a = 0, b = 0;
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '(') a++;
			else if(A[i] == '[') b++;
			else if(A[i] == ')') {
				if(a > 0) { a--; ans++; }
			}
			else {
				if(b > 0) { b--; ans++; }
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}