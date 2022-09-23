#include <bits/stdc++.h>

using namespace std;

int N;
char A[30];
int pos[30];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		for(int i = 1; i <= N; i++) pos[i] = 0;
		for(int i = 1; i <= N; i++) pos[A[i] - 'a' + 1] = i;
		bool ok = true;
		for(int i = 1; i <= N; i++) if(!pos[i]) ok = false;
		int l = pos[1], r = pos[1];
		for(int i = 2; i <= N; i++) {
			if(pos[i] < l - 1 || pos[i] > r + 1) { ok = false; break; }
			if(pos[i] == l - 1) l--;
			else r++;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}