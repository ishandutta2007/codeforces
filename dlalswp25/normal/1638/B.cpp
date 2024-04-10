#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int mx[2] = {0, 0};
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			if(mx[a & 1] > a) ok = false;
			mx[a & 1] = max(mx[a & 1], a);
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}