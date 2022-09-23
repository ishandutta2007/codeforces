#include <bits/stdc++.h>

using namespace std;

int A[101010];
int pos[101010];
bool chk[101010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			pos[A[i]] = i;
		}

		bool ok = true;

		int a = 1;
		while(a <= N) {
			int x = pos[a]; a++; chk[x] = true;
			for(int i = x + 1; i <= N; i++) {
				if(chk[i]) break;
				if(A[i] != a) { ok = false; break; }
				chk[i] = true;
				a++;
			}
			if(!ok) break;
		}
		puts(ok ? "Yes" : "No");

		for(int i = 1; i <= N; i++) chk[i] = false;
	}
	return 0;
}