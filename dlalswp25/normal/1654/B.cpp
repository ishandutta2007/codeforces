#include <bits/stdc++.h>

using namespace std;

int N;
char S[202020];
bool chk[26];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		N = strlen(S + 1);
		for(int i = 0; i < 26; i++) chk[i] = false;
		int st = N;
		for(int i = N; i >= 1; i--) {
			if(chk[S[i] - 'a']) continue;
			st = i;
			chk[S[i] - 'a'] = true;
		}
		for(int i = st; i <= N; i++) printf("%c", S[i]); puts("");
	}
	return 0;
}