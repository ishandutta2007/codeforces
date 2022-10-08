#include <stdio.h>
char d[25];
int main() {
	scanf("%s", d);
	if(d[0] >= '5' && d[0] <= '8') d[0] = '0'+'9'-d[0];
	for(int i = 1; d[i] != 0; i++) {
		if(d[i] >= '5') d[i] = '0'+'9'-d[i];
	}
	printf("%s", d);
	return 0;
}