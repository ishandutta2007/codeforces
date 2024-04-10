#include <bits/stdc++.h>

using namespace std;

int cnt[20];

int main() {
	int N, M; scanf("%d%d", &N, &M);
	bool ok = true;
	while(N) {
		if(cnt[N % M]) ok = false;
		cnt[N % M]++;
		N /= M;
	}
	puts(ok ? "YES" : "NO");
	return 0;
}