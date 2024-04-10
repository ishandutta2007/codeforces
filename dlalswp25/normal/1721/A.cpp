#include <bits/stdc++.h>

using namespace std;

char S[5];
bool chk[26];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 0; i < 26; i++) chk[i] = false;
		int ans = 3;
		for(int i = 0; i < 2; i++) {
			scanf("%s", S);
			for(int j = 0; j < 2; j++) {
				if(chk[S[j] - 'a']) ans--;
				chk[S[j] - 'a'] = true;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}