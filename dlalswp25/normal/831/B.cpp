#include <stdio.h>

char first[30];
char second[30];
char s[1005];

char change[130];

int main()
{
	scanf("%s", first);
	scanf("%s", second);

	scanf("%s", s);

	for(int i = 0; i < 128; i++)	change[i] = i;

	for(int i = 0; i < 26; i++)
	{
		change[first[i]] = second[i];
		change[first[i] - 32] = second[i] - 32;
	}

	for(int i = 0; s[i] != '\0'; i++)
	{
		printf("%c", change[s[i]]);
	}
	return 0;
}