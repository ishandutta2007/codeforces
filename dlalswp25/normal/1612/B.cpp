#include <bits/stdc++.h>

using namespace std;

int N, A, B;
int ans[105];
bool chk[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &A, &B);
		ans[1] = A; ans[N] = B;
		for(int i = 1; i <= N; i++) chk[i] = false;
		chk[A] = chk[B] = true;
		int p = N;
		for(int i = 2; i <= N / 2; i++) {
			while(chk[p]) p--;
			ans[i] = p; chk[p] = true;
		}
		p = 1;
		for(int i = N - 1; i > N / 2; i--) {
			while(chk[p]) p++;
			ans[i] = p; chk[p] = true;
		}
		bool ok = true;
		for(int i = 1; i <= N / 2; i++) if(ans[i] < A) ok = false;
		for(int i = N / 2 + 1; i <= N; i++) if(ans[i] > B) ok = false;
		if(!ok) puts("-1");
		else {
			for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
		}
	}
	return 0;
}