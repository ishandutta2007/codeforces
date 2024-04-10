#include <bits/stdc++.h>

using namespace std;

int N;
bool chk[505050];
int ans[505050];

int main() {
	scanf("%d", &N);

	int x = N;
	for(int i = N / 2; i >= 1; i--) {
		for(int j = i * 2; j <= N; j += i) {
			if(!chk[j]) {
				ans[x] = i;
				x--; chk[j] = true;
			}
		}
	}

	for(int i = 2; i <= N; i++) printf("%d ", ans[i]); puts("");
	return 0;
}