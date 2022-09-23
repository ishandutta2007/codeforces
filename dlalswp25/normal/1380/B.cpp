#include <bits/stdc++.h>

using namespace std;

int N;
char S[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		N = strlen(S + 1);
		int a = 0, b = 0, c = 0;
		for(int i = 1; i <= N; i++) {
			if(S[i] == 'R') a++;
			else if(S[i] == 'S') b++;
			else c++;
		}

		int mx = max(a, max(b, c));
		char x;
		if(mx == a) x = 'P';
		else if(mx == b) x = 'R';
		else x = 'S';
		for(int i = 1; i <= N; i++) printf("%c", x); puts("");
	}
	return 0;
}