#include <bits/stdc++.h>

using namespace std;

int N;
char A[55];
int lst[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		for(int i = 0; i <= 100; i++) lst[i] = -1;

		int s = 0; lst[s + 50] = 0;
		int x = -1, y = -1;
		for(int i = 1; i <= N; i++) {
			s += (A[i] == 'a' ? 1 : -1);
			if(lst[s + 50] != -1) {
				x = lst[s + 50] + 1; y = i;
			}
			lst[s + 50] = i;
		}
		printf("%d %d\n", x, y);
	}
	return 0;
}