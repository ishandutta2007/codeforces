#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

char buf[100];
int main() {
	do {
		puts("next 0 1");
		puts("next 1");
		fflush(stdout);
		fgets(buf, 100, stdin);
		fgets(buf, 100, stdin);
	} while (buf[0] == '3') ;
	do {
		puts("next 0 1 2 3 4 5 6 7 8 9");
		fflush(stdout);
		fgets(buf, 100, stdin);
	} while (buf[0] == '2') ;
	puts("done");
	fflush(stdout);
	return 0;
}