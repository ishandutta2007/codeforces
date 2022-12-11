#include<stdio.h>
#include<string.h>
int n,p,s[2001],a[2001],flag;
int main()
{
	scanf("%d %d",&n,&p);
	for(int i=1;i<=n;i++)
	scanf(" %c",&s[i]);
	for(int i=1;i<=n;i++)
	{
		if((s[i]==s[i+p]&&s[i]!='.')||i+p>n)continue;
		if(s[i]=='.'&&s[i+p]=='.')
		{
			s[i]='1';
			s[i+p]='0';
			flag=1;
			break;	
		}
		if(s[i]=='.')
		{
			if(s[i+p]=='0')s[i]='1';
			else if(s[i+p]=='1')s[i]='0';
			flag=1;
			break;
		}
		if(s[i+p]=='.')
		{
			if(s[i]=='0')s[i+p]='1';
			else if(s[i]=='1')s[i+p]='0';
			flag=1;
			break;
		}
		flag=1;
		break;
	}
	if(flag==0)printf("No");
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='.')s[i]='0';
			printf("%c",s[i]);
		}
	}
	return 0;
}