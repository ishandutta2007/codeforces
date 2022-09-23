#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		int cnt = 0;
		int l = -1, r = -1;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '0') {
				if(l == -1) l = i;
				r = i;
				cnt++;
			}
		}
		if(l == -1) puts("0");
		else if(cnt == r - l + 1) puts("1");
		else puts("2");
	}
	return 0;
}