#include<stdio.h>
#include<string.h>

char word1[200],word2[200];
int i,d;

int main()
{
	scanf("%s%s",word1,word2);
	
	for(i=0;word1[i];i++) if(word1[i]>='A' && word1[i]<='Z') word1[i]=word1[i]-'A'+'a';
	for(i=0;word2[i];i++) if(word2[i]>='A' && word2[i]<='Z') word2[i]=word2[i]-'A'+'a';

	d = strcmp(word1,word2);


	if(d==0) printf("0\n");
	else if(d>0) printf("1\n");
	else printf("-1\n");

	return 0;
}