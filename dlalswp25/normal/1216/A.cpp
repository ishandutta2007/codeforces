#include <bits/stdc++.h>

using namespace std;

char S[202020];
int N;

int main() {
	scanf("%d", &N);
	scanf("%s", S + 1);
	int ans = 0;
	for(int i = 1; i <= N; i += 2) {
		if(S[i] != S[i + 1]) continue;
		ans++; S[i] = (S[i + 1] == 'a' ? 'b' : 'a');
	}
	printf("%d\n", ans);
	printf("%s\n", S + 1);
	return 0;
}