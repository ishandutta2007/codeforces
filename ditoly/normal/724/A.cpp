#include<cstdio>
char s[15];
int read()
{
	scanf("%s",s);
	if(s[0]=='m')return 1;
	if(s[0]=='t'&&s[1]=='u')return 2;
	if(s[0]=='w')return 3;
	if(s[0]=='t')return 4;
	if(s[0]=='f')return 5;
	if(s[0]=='s'&&s[1]=='a')return 6;
	return 0;
}
int main()
{
	int a,b;
	a=read();b=read();
	puts(a==b||(a+2)%7==b||(a+3)%7==b?"YES":"NO");
}