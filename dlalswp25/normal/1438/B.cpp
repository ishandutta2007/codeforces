#include <bits/stdc++.h>

using namespace std;

int N;
int B[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		sort(B + 1, B + N + 1);
		bool ok = false;
		for(int i = 2; i <= N; i++) if(B[i] == B[i - 1]) ok = true;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}