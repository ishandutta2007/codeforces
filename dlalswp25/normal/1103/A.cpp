#include <bits/stdc++.h>

char S[1005];

int main() {
	scanf("%s", S);
	int v = 0, h = 0;
	for(int i = 0; S[i]; i++) {
		if(S[i] == '1') {
			v = (v + 1) % 2;
			if(v) printf("4 3\n");
			else printf("4 1\n");
		}
		else {
			h = (h + 1) % 4;
			printf("1 %d\n", h + 1);
		}
	}
	return 0;
}