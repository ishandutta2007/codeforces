#include <bits/stdc++.h>

using namespace std;

const int MX = 1000000;

int N;
bool chk[1010101];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int a; scanf("%d", &a);
		chk[a] = true;
	}

	int ans = 0;
	for(int i = MX; i >= 1; i--) {
		if(chk[i]) continue;
		int mn = MX + 1;
		for(int j = i + i; j <= MX; j += i) {
			if(chk[j]) mn = min(mn, j);
		}
		if(mn > MX) continue;
		bool ok = false;
		for(int j = i + i; j <= MX; j += i) {
			if(chk[j]) {
				if(j % mn) ok = true;
			}
		}
		if(ok) { chk[i] = true; ans++; }
	}
	printf("%d\n", ans);
	return 0;
}