#include<stdio.h>

char word[1005];
int cnt[30];
int i, odd, even;

int main()
{
	scanf("%s", word);
	for(i = 0; word[i]; i++)
	{
		cnt[ word[i]-'a' ] ++;
	}

	for(i = 0; i < 26; i++)
	{
		if(!cnt) continue;

		if(cnt[i]&1) odd++;
		else even++;
	}

	if(odd==0 || odd==1) printf("First\n");
	else if(odd%2==0) printf("Second\n");
	else printf("First\n");

	return 0;
}