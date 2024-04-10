#include<stdio.h>

char word[100];
int n, t, i , j;

int main()
{
	scanf("%d%d",&n,&t);
	scanf("%s", word);

	for(i = 1; i <= t; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(word[j]=='B' && word[j+1]=='G')
			{
				word[j] = 'G';
				word[j+1] = 'B';
				j++;
			}
		}
	}

	printf("%s\n", word);

	return 0;
}