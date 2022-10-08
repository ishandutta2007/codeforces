#include <stdio.h>
char d[105];
char t[105];
int main() {
	int L, i, j, k;
	scanf("%s", d);
	for(L = 0; d[L] != 0; L++);
	for(i = 0; i <= L; i++) {
		for(j = 0; j < i; j++) t[j] = d[j];
		for(j = i+1; j <= L; j++) t[j] = d[j-1];
		for(j = 0; j < 26; j++) {
			t[i] = 'a'+j;
			for(k = 0; k <= L; k++) {
				if(t[k] != t[L-k]) break;
			}
			if(k == L+1) break;
		}
		if(j != 26) break;
	}
	if(i != L+1) printf("%s",t);
	else printf("NA");
	return 0;
}