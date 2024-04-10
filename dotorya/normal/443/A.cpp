#include <stdio.h>
char d[1050];
char chk[26];
int main() {
	gets(d);
	int ANS = 0;
	for(int i = 0; d[i] != 0; i++) {
		if(d[i] >= 'a' && d[i] <= 'z') chk[d[i]-'a'] = 1;
	}
	
	for(int i = 0; i <= 25; i++) ANS += chk[i];
	printf("%d", ANS);
	return 0;
}