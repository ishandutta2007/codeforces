#include<stdio.h>
#include<string.h>

char months[100][100]=
{
"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

int main()
{
	char word[100];
	int i,k;

	scanf("%s%d",word,&k);
	for(i=0;i<12;i++)
		if(strcmp(word,months[i])==0) break;

	i = (i+k)%12;
	printf("%s\n",months[i]);

	return 0;
}