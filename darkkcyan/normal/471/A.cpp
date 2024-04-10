#include <stdio.h>
#include <stdlib.h>


int main(void) {
	int l[10] = {0};
	for (int i = 0; i < 6; ++i) {
		int t;
		scanf("%d", &t);
		l[t] ++;
	}
	int c[7] = {0};
	for (int i = 0; i < 10; ++i) c[l[i]] ++;
	int isAlien = 0;
	if (c[6] == 1) {
		printf("Elephant");
	} else if (c[5] == 1) {
		printf("Bear");
	} else if (c[4] != 1) {
		printf("Alien");
	} else if (c[1] == 2) {
		printf("Bear");
	} else if (c[2] == 1) {
		printf("Elephant");
	} else {
		printf("Alien");
	}
	
	return 0;
}