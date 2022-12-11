#include<stdio.h>
#include<string.h>
char s[101];
int bj[101][4];
int main()
{
	gets(s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='A')bj[i][1]=bj[i-1][1]=bj[i+1][1]=1;
		else if(s[i]=='B')bj[i][2]=bj[i-1][2]=bj[i+1][2]=1;
		else if(s[i]=='C')bj[i][3]=bj[i-1][3]=bj[i+1][3]=1;
	}
	for(int i=0;i<strlen(s);i++)
	if(bj[i][1]==1&&bj[i][2]==1&&bj[i][3]==1)
	{
		printf("YES");
		return 0;	
	}
	printf("NO");
	return 0;
}