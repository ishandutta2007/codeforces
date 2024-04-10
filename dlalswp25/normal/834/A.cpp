#include <stdio.h>

char cw[128];

int main()
{
	char first, last;
	scanf("%c %c", &first, &last);

	int n;	scanf("%d", &n);

	n %= 4;
	cw[118] = 60;	cw[60] = 94;	cw[94] = 62;	cw[62] = 118;

	if(n == 0 || n == 2)
	{
		puts("undefined");
		return 0;
	}

	if(n == 1)
	{
		if(cw[first] == last)	puts("cw");
		else	puts("ccw");
		return 0;
	}

	if(cw[first] == last)	puts("ccw");
	else	puts("cw");

	return 0;
}