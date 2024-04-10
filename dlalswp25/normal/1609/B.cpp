#include <bits/stdc++.h>

using namespace std;

int N, Q;
char A[101010];

bool chk(int i) {
	if(i <= 0 || i > N - 2) return false;
	return A[i] == 'a' && A[i + 1] == 'b' && A[i + 2] == 'c';
}

int main() {
	scanf("%d%d", &N, &Q);
	scanf("%s", A + 1);
	int ans = 0;
	for(int i = 1; i <= N - 2; i++) ans += chk(i);
	while(Q--) {
		int p; char c;
		scanf("%d %c", &p, &c);
		ans -= chk(p - 2);
		ans -= chk(p - 1);
		ans -= chk(p);
		A[p] = c;
		ans += chk(p - 2);
		ans += chk(p - 1);
		ans += chk(p);
		printf("%d\n", ans);
	}
	return 0;
}