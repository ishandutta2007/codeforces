#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N % 3 == 0) {
			for(int i = 1; i <= N / 3; i++) printf("21"); puts("");
		}
		else if(N % 3 == 1) {
			printf("1");
			for(int i = 1; i <= N / 3; i++) printf("21"); puts("");
		}
		else {
			for(int i = 1; i <= N / 3; i++) printf("21"); puts("2");
		}
	}
	return 0;
}