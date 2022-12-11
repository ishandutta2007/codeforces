#include<cstdio>
char s[10];
int main()
{
	int n;
	scanf("%d%s",&n,s);
	if(s[3]>'5')s[3]='5';
	if(n==12)
	{
		if(s[0]=='1'&&s[1]>'2')s[1]='2';
		if(s[0]=='0'&&s[1]=='0')s[1]='1';
		if(s[0]>'1')
			if(s[1]>'0')s[0]='0';
			else s[0]='1';
	}
	if(n==24)if(s[0]>'2'||(s[0]=='2'&&s[1]>'3'))s[0]='0';
	printf("%s",s);
}