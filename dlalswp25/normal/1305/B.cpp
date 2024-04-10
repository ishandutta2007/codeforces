#include <bits/stdc++.h>

using namespace std;

char S[1010];

bool chk[1010];

int main() {
	scanf("%s", S + 1);
	int N = strlen(S + 1);

	int ans = 0;
	int l = 1, r = N;
	while(l <= N && S[l] == ')') l++;
	while(r >= 1 && S[r] == '(') r--;

	while(l <= r) {
		ans += 2;
		chk[l] = chk[r] = true;
		l++; r--;
		while(l <= N && S[l] == ')') l++;
		while(r >= 1 && S[r] == '(') r--;
	}

	if(ans == 0) { puts("0"); return 0; }
	puts("1");
	printf("%d\n", ans);
	for(int i = 1; i <= N; i++) if(chk[i]) printf("%d ", i); puts("");

	return 0;
}