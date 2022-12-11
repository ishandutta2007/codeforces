#include<stdio.h>
#include<string.h>
char a[1010];
int len;
int main()
{
	scanf("%s",a+1);
	len=strlen(a+1);
	for(int i=1;i<=len;++i)
		if((a[i]=='b'&&a[i+1]=='a')||(a[i]=='a'&&a[i+1]!='a'))printf("1 ");
		else printf("0 ");
	return 0;
}