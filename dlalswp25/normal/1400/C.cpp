#include <bits/stdc++.h>

using namespace std;

int N;
char W[101010];
char S[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		N = strlen(S + 1);
		int x; scanf("%d", &x);

		for(int i = 1; i <= N; i++) W[i] = '1';
		for(int i = 1; i <= N; i++) {
			if(S[i] == '0') {
				if(i - x > 0) W[i - x] = '0';
				if(i + x <= N) W[i + x] = '0';
			}
		}

		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(S[i] == '0') continue;
			if(!(i - x > 0 && W[i - x] == '1') && !(i + x <= N && W[i + x] == '1')) ok = false;
		}
		if(!ok) puts("-1");
		else {
			for(int i = 1; i <= N; i++) printf("%c", W[i]); puts("");
		}
	}
	return 0;
}