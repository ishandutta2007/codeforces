#include<stdio.h>
#include<string.h>

int main()
{
	int len;
	char word[100], ch;
	int i, n;

	scanf("%s", word);
	len = strlen(word);
	scanf("%d", &n);

	for(i = 0; i < len; i++)
		if(word[i] >= 'A' && word[i] <='Z')
			word[i] = word[i] - 'A' + 'a';

	for(i = 0; i < len; i++)
	{
		ch = word[i];

		if(ch < n + 97)
			word[i] = word[i] - 'a' + 'A';
	}

	printf("%s\n", word);

	return 0;
}