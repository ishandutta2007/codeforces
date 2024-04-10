#include <bits/stdc++.h>

using namespace std;

char S[505050];

int main() {
	scanf("%s", S + 1);
	int N = strlen(S + 1);

	int mn = 987654321;

	for(int i = 1; i <= N; i++) {
		if(mn >= S[i]) puts("Mike");
		else puts("Ann");
		mn = min(mn, (int)S[i]);
	}

	return 0;
}