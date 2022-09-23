#include <stdio.h>

char s[205];

int main()
{
	scanf("%s", s);
	int E;
	for(E = 0; s[E] != 'e'; E++);

	int b = 0;

	for(int i = E + 1; s[i] != 0; i++)
	{
		b = b * 10 + (s[i] - '0');
	}

	int dot = 1;
	while(1)
	{
		if(b == 0)	break;
		if(s[dot + 1] == 'e')	break;
		b--;
		s[dot] = s[dot + 1];	s[dot + 1] = '.';	dot++;
	}

	bool isInt = true;
	for(int i = dot + 1; s[i] != 'e'; i++)	if(s[i] != '0')	isInt = false;

	if(isInt)
	{
		for(int i = 0; i < dot; i++)	printf("%c", s[i]);
		for(int i = 0; i < b; i++)	printf("0");
	}
	else
	{
		for(int i = 0; s[i] != 'e'; i++)	printf("%c", s[i]);
	}

	return 0;
}